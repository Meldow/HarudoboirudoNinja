#ifndef WAYPOINT_ENEMY_H
#define WAYPOINT_ENEMY_H

#include <string>
#include "cg/cg.h"
#include "Debug.h"
#include "DebugManager.h"

namespace proj {

	class WaypointEnemy : public cg::Entity,
		public cg::IDrawListener,
		public Debug
	{
	private:
		cg::Vector3d _position;

	public:
		WaypointEnemy(std::string id, cg::Vector3d position);
		~WaypointEnemy();
		
		void init();
		void draw();
		
		cg::Vector3d getPosition();
	};
}


#endif