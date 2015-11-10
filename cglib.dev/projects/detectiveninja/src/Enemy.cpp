#include "Enemy.h"

namespace proj {

	Enemy::Enemy(std::string id, cg::Vector3d position) : WorldObject(id, position) {
		_waypoints = new std::vector<WaypointEnemy*>();
	}
	Enemy::~Enemy() {}

	void Enemy::init() {

		_physics.setPosition(_position[0], _position[1], _position[2]);
		_physics.setLinearVelocity(20.0);
		_physics.setAngularVelocity(50.0);
		_physics.setAxesScale(12.0);

		_previousPosition = _position;

		_isMoving = false;
		_spottedNinja = false;
		_spottedSexyMagazine = false;

		_headWidth =  3.0f;
		_headLength = 2.0f;
		_headHeight = 4.0f;

		_bodyWidth =  4.0f;
		_bodyLength = 2.5f;
		_bodyHeight = 4.0f;

		_armWidth =  1.0f;
		_armLength = 1.0f;
		_armHeight = 3.0f;

		_legWidth =  1.0f;
		_legLength = 1.0f;
		_legHeight = 3.0f;

		_headAngle = 0.0f;

		_armAngle[0] = 0.0f;
		_armAngle[1] = 0.0f;
		_armRotationVector[0].set(1,0,0);
		_armRotationVector[1].set(1,0,0);

		_armDirection[0] = false;
		_armDirection[1] = true;

		_legAngle[0] = 0.0f;
		_legAngle[1] = 0.0f;
		_legRotationVector[0].set(1,0,0);
		_legRotationVector[1].set(1,0,0);

		_legDirection[0] = true;
		_legDirection[1] = false;

		CollisionManager *collisionManager = (CollisionManager*)cg::Registry::instance()->get("CollisionManager");
		collisionManager->registerEnemy(dynamic_cast<Collidable*>(cg::Registry::instance()->get(getId())));
		createBoundingSpheres();
		makeAlertDL();

		dynamic_cast<DebugManager*>(cg::Registry::instance()->get("DebugManager"))->registerEnemy(dynamic_cast<Debug*>(this));
		

		_timer = 3.0f;
		_waypointChangeCounter = -1;
		_targetWaypoint = 0;
	}
	
	void Enemy::makeAlertDL() {

		_alertDL = glGenLists(1);
		assert(_alertDL != 0);
		glNewList(_alertDL, GL_COMPILE);
			glDisable(GL_LIGHTING);
			glColor3f(1.0, 0.0, 0.0);
			glTranslatef(0.0f, 0.0f, 12.0f);
			glutSolidCube(1);
			glTranslatef(0.0f, 0.0f, 3.0f);
			glScalef(1.0f, 1.0f, 2.5f);
			glutSolidCube(1);
			glEnable(GL_LIGHTING);
		glEndList();
	}

	void Enemy::update(unsigned long elapsed_millis) {

		double elapsed_seconds = elapsed_millis / (double)1000;
		_physics.step(elapsed_seconds);

		if (!_spottedSexyMagazine && !_spottedNinja) {
			
			//if has 1 or more waypoints, goes there and does his thing
			if (_waypoints->size() > 0) {
				//update target position
				_targetWaypointPosition = _waypoints->at(_targetWaypoint)->getPosition();

				//update distance to waypoint
				_squaredDistanceToWaypoint = squarelength(_physics.getPosition(), _targetWaypointPosition);
		
				//refresh my position
				_position = this->getPosition();

				//calculate vector pointing to *NEW* target
				_targetVector = _targetWaypointPosition - _position;

				//angle between front and my *NEW* target (working)
				_angle = acos((dotProduct(_physics.getFront(),_targetVector)) / (length(_physics.getFront())*length(_targetVector)));
				

				if(_squaredDistanceToWaypoint < DISTANCE_TO_CHANGE_WAYPOINT) {
					//means im close to waypoint, gotta change it
					_waypointChangeCounter++;
					_waypointChangeCounter = _waypointChangeCounter % _waypoints->size();
					//change waypoint index
					changeWaypoint();
					//_isMoving = false;
					//std::cout << "_waypointChangeCounter: "<<_waypointChangeCounter<<"\n";
				}

				else { 
					if(_angle <= ANGLE_ERROR) {
						//means im looking at waypoint, move forward
						_physics.goAhead();
						//_isMoving = true;
					}
					else {
						//aux to check wich side to turn
						_angleRight = acos((dotProduct(_physics.getRight(),_targetVector)) / (length(_physics.getRight())*length(_targetVector)));
						_angleLeft = acos((dotProduct(_physics.getLeft(),_targetVector)) / (length(_physics.getLeft())*length(_targetVector)));
						//std::cout<<"angle is: "<<_angle<<"\n";
						//means im NOT looking at waypoint, rotates
						if (_angleRight < _angleLeft)
							_physics.yawRight();
						else
							_physics.yawLeft();
						//_isMoving = false;
					}

				}
			}
			//if it has no waypoint, just sits where he is spawned and looks around
			else 
				_physics.yawRight();

			//COLLISION
			_previousPosition = getPosition();
			updateBoundingSpheres();
		}
		else 
			if (_spottedSexyMagazine) {	// Jump !

			if (!_physics.isJumping()) {
				_timer +=(float) elapsed_seconds;
			}

			if (_timer > 0.2) {
				_physics.jump();
				_timer = 0.0;
			}
		}

		
	}

	void Enemy::draw() {
		
		if (_isColliding) {

			_physics.setPosition(_previousPosition[0], _previousPosition[1], _previousPosition[2]);
			_physics.setMinHeight((int)_previousPosition[2]);
			_isColliding = false;

			updateBoundingSpheres();
		}

		if (isDebug()) {
			_physics.drawAxes();

			glDisable(GL_LIGHTING);

			for (int i = 0; i < (int)getBoundingSpheres()->size(); i++) {

				float* color = getBoundingSphere(i)->getColor();
				GLuint slices = 20;
				GLuint stacks = 20;
				glPushMatrix();
					glColor3f(color[0], color[1], color[2]);
					glTranslatef((float)getBoundingSphere(i)->getPosition()[0],
						(float)getBoundingSphere(i)->getPosition()[1],
						(float)getBoundingSphere(i)->getPosition()[2]);
					glutWireSphere((double)getBoundingSphere(i)->getRadius(), slices, stacks);
				glPopMatrix();
			}

			glEnable(GL_LIGHTING);
		}

		updateAngles();

		glPushMatrix();

		// LOAD TEXTURES
		TextureManager* tm = dynamic_cast<TextureManager*>( cg::Registry::instance()->get("TextureManager"));
		GLuint txEnemyFace;
		if (_spottedSexyMagazine) {
			txEnemyFace = tm->get("tex_enemy_perv_face")->getTextureDL();
		}
		else {
			txEnemyFace = tm->get("tex_enemy_face")->getTextureDL();
		}
		GLuint txEnemyBody = tm->get("tex_dark_ninja_body")->getTextureDL();

		glEnable(GL_TEXTURE_2D);

		_physics.applyTransforms();
		
		// left leg
		glPushMatrix();
			glTranslatef(-(_legWidth + _bodyWidth) / 5.0f, 0.0f, _legHeight);
			glRotatef(_legAngle[0], _legRotationVector[0][0], _legRotationVector[0][1], _legRotationVector[0][2]);
			glTranslatef(0.0f, 0.0f, -_legHeight / 2.0f);
			glScalef(_legWidth, _legLength, _legHeight);
			unitCube(txEnemyBody);
		glPopMatrix();

		// right leg
		glPushMatrix();
			glTranslatef((_legWidth + _bodyWidth) / 5.0f, 0.0f, _legHeight);
			glRotatef(_legAngle[1], _legRotationVector[1][0], _legRotationVector[1][1], _legRotationVector[1][2]);
			glTranslatef(0.0f, 0.0f, -_legHeight / 2.0f);
			glScalef(_legWidth, _legLength, _legHeight);
			unitCube(txEnemyBody);
		glPopMatrix();

		// left arm
		glPushMatrix();
			if (_spottedNinja) {
				glTranslatef(-0.3f, 0.0f, _armHeight);
			}
			else if (_spottedSexyMagazine) {
				glTranslatef(0.5f, 0.0f, _armHeight - 0.5f);
			}
			glTranslatef(-_bodyWidth / 2.0f, 0.0f, _armHeight + _legHeight);
			glRotatef(_armAngle[0], _armRotationVector[0][0], _armRotationVector[0][1], _armRotationVector[0][2]);
			glTranslatef(-_armWidth / 2.0f, 0.0f, -_armHeight / 2.0f);
			glScalef(_armWidth, _armLength, _armHeight);
			unitCube(txEnemyBody);
		glPopMatrix();

		// right arm
		glPushMatrix();
			if (_spottedNinja) {
				glTranslatef(0.3f, 0.0f, _armHeight);
			}
			else if (_spottedSexyMagazine) {
				glTranslatef(-0.5f, 0.0f, _armHeight - 0.5f);
			}
			glTranslatef(_bodyWidth / 2.0f, 0.0f, _armHeight + _legHeight);
			glRotatef(_armAngle[1], _armRotationVector[1][0], _armRotationVector[1][1], _armRotationVector[1][2]);
			glTranslatef(_armWidth / 2.0f, 0.0f, -_armHeight / 2.0f);
			glScalef(_armWidth, _armLength, _armHeight);
			unitCube(txEnemyBody);
		glPopMatrix();

		// body
		glPushMatrix();
			glTranslatef(0.0f, 0.0f, _bodyHeight / 2.0f + _legHeight - 0.5f);
			glScalef(_bodyWidth, _bodyLength, _bodyHeight);
			unitCube(txEnemyBody);
		glPopMatrix();

		// head
		glPushMatrix();
			if (_spottedSexyMagazine) {
				glTranslatef(0.0f, 1.0f, 0.0f);
			}
			glTranslatef(0.0f, 0.0f, _headHeight / 2.0f + _bodyHeight + _legHeight - 1.75f);
			glRotatef(_headAngle, 1.0f, 0.0f, 0.0f);
			glScalef(_headWidth, _headLength, _headHeight);
			unitCube(txEnemyFace, txEnemyBody, txEnemyBody, txEnemyBody, txEnemyBody, txEnemyBody);
		glPopMatrix();

		if(_spottedNinja || _spottedSexyMagazine) {
			glCallList(_alertDL);
		}

		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	void Enemy::registerToCollisionManager() {

		createBoundingSpheres();

		CollisionManager *collisionManager = (CollisionManager*)cg::Registry::instance()->get("CollisionManager");
		collisionManager->registerNinja(dynamic_cast<Collidable*>(cg::Registry::instance()->get(getId())));
	}

	void Enemy::createBoundingSpheres() {

		// body bounding spheres
		float r = (_headHeight + _bodyHeight + _legHeight) / 2 - 0.7f;
		cg::Vector3d p(getPosition()[0], getPosition()[1], getPosition()[2] + r);
		BoundingSphere *b = new BoundingSphere(r, p);

		addBoundingSphere(b);

		r = _headHeight / 2;
		p.set(getPosition()[0], getPosition()[1], getPosition()[2] + _legHeight + _bodyHeight + _headHeight / 2 - 1.2f);
		b = new BoundingSphere(r, p);

		addBoundingSphere(b);

		r = (_bodyHeight + _armWidth) / 2;
		p.set(getPosition()[0], getPosition()[1], getPosition()[2] + _legHeight + _bodyHeight / 2 - 0.7f);
		b = new BoundingSphere(r, p);

		addBoundingSphere(b);

		r = _legHeight / 2;
		p.set(getPosition()[0], getPosition()[1], getPosition()[2] + _legHeight / 2);
		b = new BoundingSphere(r, p);

		addBoundingSphere(b);

		// vision bounding spheres
		double prevR = (_headHeight + _bodyHeight + _legHeight) / 2 - 0.7f;
		r = _headHeight / 2;

		cg::Vector3d prevP;
		p.set(getPosition()[0], getPosition()[1] + prevR + r, getPosition()[2] + _legHeight + _bodyHeight / 2);

		int maxNBoundingSpheres = 5;
		for (int i = 0; i <= maxNBoundingSpheres; i++) {
			
			b = new BoundingSphere(r, p);
			addBoundingSphere(b);

			prevR = r; r += 1.0f;
			prevP.set(p[0], p[1], p[2]); p.set(prevP[0], prevP[1] + prevR + r, prevP[2]); 
		}
	}

	void Enemy::updateBoundingSpheres() {

		// body bounding spheres
		double r = getBoundingSphere(0)->getRadius();
		cg::Vector3d p(getPosition()[0], getPosition()[1], getPosition()[2] + r);
		getBoundingSphere(0)->updatePosition(p);

		r = getBoundingSphere(1)->getRadius();
		p.set(getPosition()[0], getPosition()[1], getPosition()[2] + _legHeight + _bodyHeight + _headHeight / 2 - 1.2f);
		getBoundingSphere(1)->updatePosition(p);

		r = getBoundingSphere(2)->getRadius();
		p.set(getPosition()[0], getPosition()[1], getPosition()[2] + _legHeight + _bodyHeight / 2 - 0.6f);
		getBoundingSphere(2)->updatePosition(p);

		r = getBoundingSphere(3)->getRadius();
		p.set(getPosition()[0], getPosition()[1], getPosition()[2] + _legHeight / 2);
		getBoundingSphere(3)->updatePosition(p);

		// vision bounding spheres
		double prevR = getBoundingSphere(0)->getRadius();
		r = getBoundingSphere(1)->getRadius();

		cg::Vector3d prevP;
		p.set(getPosition()[0]+(_physics.getFront()[0]*(prevR + r)), (getPosition()[1]) + (_physics.getFront()[1]*(prevR + r )), getPosition()[2] + _legHeight + _bodyHeight / 2);

		for (int i = 4; i < (int)getBoundingSpheres()->size(); i++) {
			
			getBoundingSphere(i)->updatePosition(p);

			if (i < (int)getBoundingSpheres()->size() - 1) {
				prevR = r; r = getBoundingSphere(i + 1)->getRadius();
				prevP.set(p[0], p[1], p[2]); p.set(prevP[0]+(_physics.getFront()[0]*(prevR + r)), prevP[1] + (_physics.getFront()[1]*(prevR + r )), prevP[2]);
			}
		}
	}

	cg::Vector3d Enemy::getPosition() {
		return _physics.getPosition();
	}

	cg::Vector3d Enemy::getFront() {
		return _physics.getFront();
	}

	void Enemy::setHeight(int height) {
		//_physics.setPosition(getPosition()[0], getPosition()[1], height);
		_physics.setMinHeight(height);
	}

	void Enemy::spottedNinja() {

		_isMoving = false;
		_spottedNinja = true;
	}

	void Enemy::spottedSexyMagazine(bool spottedSexyMag) {

		if (spottedSexyMag && !_spottedNinja) {
			_isMoving = false;
			_spottedSexyMagazine = true;
		}
		else if (!spottedSexyMag && !_spottedNinja) {
			_isMoving = true;
			_spottedSexyMagazine = false;
		}
		else {
			_isMoving = false;
			_spottedSexyMagazine = false;
		}
	}

	void Enemy::updateAngles() {

		float _armMaxAngle = 45.0f, _armAngleUpdate = 4.0f;
		float _legMaxAngle = 35.0f, _legAngleUpdate = 3.0f;
		
		if (_isMoving) {

			if (_armDirection[0]) {
				_armAngle[0] += _armAngleUpdate;
			}
			else {
				_armAngle[0] -= _armAngleUpdate;
			}

			if (_armAngle[0] <= -_armMaxAngle) {
				_armDirection[0] = true;
			}
			else if (_armAngle[0] >= _armMaxAngle) {
				_armDirection[0] = false;
			}

			if (_armDirection[1]) {
				_armAngle[1] += _armAngleUpdate;
			}
			else {
				_armAngle[1] -= _armAngleUpdate;
			}

			if (_armAngle[1] <= -_armMaxAngle) {
				_armDirection[1] = true;
			}
			else if (_armAngle[1] >= _armMaxAngle) {
				_armDirection[1] = false;
			}

			_armRotationVector[0].set(1,0,0);
			_armRotationVector[1].set(1,0,0);

			if (_legDirection[0]) {
				_legAngle[0] += _legAngleUpdate;
			}
			else {
				_legAngle[0] -= _legAngleUpdate;
			}

			if (_legAngle[0] <= -_legMaxAngle) {
				_legDirection[0] = true;
			}
			else if (_legAngle[0] >= _legMaxAngle) {
				_legDirection[0] = false;
			}

			if (_legDirection[1]) {
				_legAngle[1] += _legAngleUpdate;
			}
			else {
				_legAngle[1] -= _legAngleUpdate;
			}

			if (_legAngle[1] <= -_legMaxAngle) {
				_legDirection[1] = true;
			}
			else if (_legAngle[1] >= _legMaxAngle) {
				_legDirection[1] = false;
			}

			_legRotationVector[0].set(1,0,0);
			_legRotationVector[1].set(1,0,0);
		}
		else if (_spottedNinja) {

			_headAngle = 0.0f;

			_armAngle[0] = -20.0f;
			_armAngle[1] = 20.0f;
			_armRotationVector[0].set(0,1,0);
			_armRotationVector[1].set(0,1,0);

			_legAngle[0] = _legAngle[1] = 0.0f;
			_legRotationVector[0].set(1,0,0);
			_legRotationVector[1].set(1,0,0);

			_legDirection[0] = true;
			_legDirection[1] = false;
		}
		else if (_spottedSexyMagazine) {
			_headAngle = -15;

			_armAngle[0] = 10.0f;
			_armAngle[1] = -10.0f;
			_armRotationVector[0].set(0,1,0);
			_armRotationVector[1].set(0,1,0);

			if (_physics.isJumping()) {

				_legAngle[0] = 110.0f;
				_legAngle[1] = -110.0f;
				_legRotationVector[0].set(0,1,0);
				_legRotationVector[1].set(0,1,0);

				_legDirection[0] = true;
				_legDirection[1] = false;
			}
			else {

				_legAngle[0] = _legAngle[1] = 0.0f;
				_legRotationVector[0].set(1,0,0);
				_legRotationVector[1].set(1,0,0);
			}
		}
		else {	// stop moving

			_headAngle = 0.0f;

			_armAngle[0] = _armAngle[1] = 0.0f;
			_armRotationVector[0].set(1,0,0);
			_armRotationVector[1].set(1,0,0);

			_legAngle[0] = _legAngle[1] = 0.0f;
			_legRotationVector[0].set(1,0,0);
			_legRotationVector[1].set(1,0,0);

			_legDirection[0] = true;
			_legDirection[1] = false;
		}
	}

	void Enemy::addPath(WaypointEnemy* box){
		_waypoints->push_back(box);
		std::cout<<"_waypoints->size() of "<<this->getId()<<" is now: "<<_waypoints->size()<<"\n";
	}

	double Enemy::dotProduct(cg::Vector3d v1, cg::Vector3d v2) {
		double result;
		result = (v1[0] * v2[0]) + (v1[1] * v2[1]);
		return result;
	}

	double Enemy::length(cg::Vector3d v1){
		double result = 0;
		for (int i=0; i<2; i++) {
			result += v1[i] * v1[i];
		}
		return sqrt(result);
	}

	double Enemy::squarelength(cg::Vector3d v1){
		double result = 0;
		for (int i=0; i<2; i++) {
			result += v1[i] * v1[i];
		}
		return result;
	}

	double Enemy::squarelength(cg::Vector3d v1, cg::Vector3d v2){
		double result = 0;
		for (int i=0; i<2; i++) {
			result += (v2[i] - v1[i]) * (v2[i] - v1[i]);
		}
		return result;
	}

	void Enemy::changeWaypoint() {
		//comportamento sentinela tipo olofote
		if(_waypoints->size() == 1 || _waypoints->size()) {}
		
		//comportamento yo-yo
		if(_waypoints->size() == 2) {
			switch (_waypointChangeCounter){
			case 0:
				_targetWaypoint += 1;
				_targetWaypoint = _targetWaypoint % _waypoints->size();
				break;
			case 1:
				_targetWaypoint += 1;
				_targetWaypoint = _targetWaypoint % _waypoints->size();
				break;
			}
		}

		//comportamento triangulo
		if(_waypoints->size() == 3) {
			switch (_waypointChangeCounter){
			case 0:
				_targetWaypoint += 1;
				_targetWaypoint = _targetWaypoint % _waypoints->size();
				break;
			case 1:
				_targetWaypoint += 1;
				_targetWaypoint = _targetWaypoint % _waypoints->size();
				break;
			case 3:
				_targetWaypoint += 1;
				_targetWaypoint = _targetWaypoint % _waypoints->size();
				break;
			}
		}

		//comportamento quadrado
		if(_waypoints->size() == 4) {
			switch (_waypointChangeCounter)
			{
			case 0:
				//std::cout << "case 0\n";
				_targetWaypoint += 1;
				_targetWaypoint = _targetWaypoint % _waypoints->size();
				break;
			case 1:
				//std::cout << "case 1\n";
				_targetWaypoint += 2;
				_targetWaypoint = _targetWaypoint % _waypoints->size();
				break;
			case 2:
				//std::cout << "case 2\n";
				_targetWaypoint -= 1;
				_targetWaypoint = _targetWaypoint % _waypoints->size();
				break;
			case 3:
				//std::cout << "case 3\n";
				_targetWaypoint -= 2;
				_targetWaypoint = _targetWaypoint % _waypoints->size();
				break;
			}
		}
	}
}