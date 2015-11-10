#include "ObjectSexyMagazine.h"

namespace proj {

	ObjectSexyMagazine::ObjectSexyMagazine(std::string id, cg::Vector3d position) : WorldObject(id, position) {}
	ObjectSexyMagazine::~ObjectSexyMagazine() {}

	void ObjectSexyMagazine::init() {

		_caught = false;

		//throwing stuff
		_rotation = 0.0f;
		_time = 0;
		_throwing = false;
		_throwed = false;
		_frontspeed = 75;

		registerToCollisionManager();
		dynamic_cast<DebugManager*>(cg::Registry::instance()->get("DebugManager"))->registerStaticObject(dynamic_cast<Debug*>(this));
		_map = (ImageLoaderHeightMap*)cg::Registry::instance()->get("mappedterrain");
	}
	
	void ObjectSexyMagazine::update(unsigned long elapsed_millis) {
		if (_isColliding && !_caught) {
			_caught = true;
			_position.set(0.0f,0.0f,0.0f);
			printf("Ninja::Caught Magazine\n");
		}

		_isColliding = false;
		updateBoundingSpheres();

		//needs to update position, magazine is flying

		
		move(elapsed_millis);
		//hit map
		if (_map->Height((int)_position[0],(int)_position[1]) >= (int)_position[2] && _throwing) {
			reset();
			_throwing = false;
			//printf("reseting \n");
			return;
		}
	}

	void ObjectSexyMagazine::draw() {

		if (!_caught) {

			if (isDebug()) {

				float* color = getBoundingSphere(0)->getColor();
				glPushMatrix();

					glDisable(GL_LIGHTING);

					glColor3f(color[0], color[1], color[2]);
					glTranslated(getBoundingSphere(0)->getPosition()[0], getBoundingSphere(0)->getPosition()[1], getBoundingSphere(0)->getPosition()[2]);
					glutWireSphere(getBoundingSphere(0)->getRadius(), 20, 20);

					glEnable(GL_LIGHTING);

				glPopMatrix();
			}

			TextureManager* textureManager = dynamic_cast<TextureManager*>( cg::Registry::instance()->get("TextureManager"));
			GLuint sexyMagazineCover = textureManager->get("tex_icha_icha_tactics_cover")->getTextureDL();
			GLuint sexyMagazineSpine = textureManager->get("tex_icha_icha_tactics_spine")->getTextureDL();
			GLuint sexyMagazine = textureManager->get("tex_icha_icha_tactics")->getTextureDL();

			glPushMatrix();
				if (_throwing)
					_rotation += 30.0f;
				glEnable(GL_TEXTURE_2D);
				glTranslated(_position[0], _position[1], _position[2] + SEXY_MAGAZINE_HEIGHT / 2);
				glRotatef(_rotation, 0.0f, 0.0f, 1.0f);
				glScalef(SEXY_MAGAZINE_WIDTH, SEXY_MAGAZINE_LENGTH, SEXY_MAGAZINE_HEIGHT);
				unitCube(sexyMagazine, sexyMagazine, sexyMagazineCover, sexyMagazine, sexyMagazineSpine, sexyMagazine);
				glDisable(GL_TEXTURE_2D);

			glPopMatrix();
		}
	}

	void ObjectSexyMagazine::registerToCollisionManager() {

		createBoundingSpheres();

		CollisionManager *collisionManager = (CollisionManager*)cg::Registry::instance()->get("CollisionManager");
		collisionManager->registerSexyMagazine(dynamic_cast<Collidable*>(cg::Registry::instance()->get(getId())));
	}

	void ObjectSexyMagazine::createBoundingSpheres() {

		float radius = (float)(SEXY_MAGAZINE_LENGTH / 2);
		cg::Vector3d position(_position[0], _position[1], _position[2] + SEXY_MAGAZINE_HEIGHT / 2);

		BoundingSphere *b = new BoundingSphere(radius, position);
		addBoundingSphere(b);
	}

	void ObjectSexyMagazine::updateBoundingSpheres() {

		getBoundingSphere(0)->updatePosition(
				cg::Vector3d(getPosition()[0], getPosition()[1], getPosition()[2] + SEXY_MAGAZINE_HEIGHT / 2));
	}

	void ObjectSexyMagazine::wasThrown(cg::Vector3d position, cg::Vector3d front) {
		//if i have a magazine to throw
		if (_caught) {
			
			_front = front;
			_initialPosition = position;
			reset();
		}
	}

	bool ObjectSexyMagazine::wasCaught() {
		return _caught;
	}

	cg::Vector3d ObjectSexyMagazine::getPosition() {
		return _position;
	}

	cg::Vector3d ObjectSexyMagazine::getFront() { return cg::Vector3d(1,0,0); }
	void ObjectSexyMagazine::setHeight(int height) {}

	float ObjectSexyMagazine::setPhysicPosition(float time){
		return _frontspeed*time;
	}

	void ObjectSexyMagazine::reset() {
		_caught = false;
		_time = 0;
		_throwing = true;
		_throwed = false;
		_frontspeed = 75;
	}

	void ObjectSexyMagazine::move(unsigned long elapsed_millis) {
		double elapsed_seconds = elapsed_millis / (double)1000;

		if(_throwing) {
			_time += (float)elapsed_seconds;
			_frontspeed -= (float)(elapsed_seconds*25);
			
			//arrived my destiny, stops moving forward, allows moving downward
			if(_time > 1.6) {
				_throwing = false;
				_throwed = true;
				_frontspeed = 75;
			}
			
			//moves forward
			else {
				_position.set(	_initialPosition[0] + setPhysicPosition(_time)*_front[0] + 10*_front[0],
								_initialPosition[1] + setPhysicPosition(_time)*_front[1] + 10*_front[1],
								_initialPosition[2] + 5
								);
				
			}
		}

		//std::cout<<"throwed: "<<_throwed<<" || _position[2]: "<<_position[2]<<" || _map->Height: "<< _map->Height(_position[0],_position[1]) <<"\n";
		
		//stoped moving forward, cartoonlike moving downward
		if (_throwed && ( _position[2] > (_map->Height((int)_position[0],(int)_position[1]) + 0.5))) {
			_position[2] -= 0.5;
			//std::cout<<"hight: "<<_position[2]<<"\n";
		}
	}

}