#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <math.h>
#include "cg/cg.h"
#include "Collidable.h"
#include "ImageLoaderHeightMap.h"
#include "LevelManager.h"
#include "Scene.h"
#include "Ninja.h"

namespace proj {

	class CollisionManager : public cg::Entity,
		public cg::IUpdateListener
	{
	private:
		ImageLoaderHeightMap *_map;

		Collidable* _ninja;

		std::vector<Collidable*>* _enemies;
		std::vector<Collidable*>* _clues;
		std::vector<Collidable*>* _sexyMagazines;
		std::vector<Collidable*>* _staticObjects;
		
		bool heightMapHorizontalCollision(Collidable* dynamicObject);
		void heightMapVerticalCollision(Collidable* dynamicObject);
		int ninjaVsEnemyCollisionDetection(Collidable* ninja, Collidable* enemy);
		int dynamicVsStaticObjectCollisionDetection(Collidable* dynamicObject, Collidable* staticObject);
		bool boundingSphereCollisionDetection(BoundingSphere* boundingSphere1, BoundingSphere* boundingSphere2);

	public:
		CollisionManager();
		~CollisionManager();

		void init();
		void update(unsigned long elapsed_millis);

		void registerNinja(Collidable* ninja);
		void registerEnemy(Collidable* enemy);
		void registerClue(Collidable* clue);
		void registerSexyMagazine(Collidable* sexyMagazines);
		void registerStaticObject(Collidable* staticObject);
		void dispose();
		int getListsSize();
	};
}

#endif