
#ifndef ENTITYMGR_H_
#define ENTITYMGR_H_

#include <list>
#include <OgreVector3.h>
#include <OgreSceneManager.h>
#include <Ogre.h>
#include "Entity381.h"
#include "Types.h"
class EntityMgr
{

private:
	std::list<Entity381 *> entities;
public:
	Entity381* selectedEntity;
    EntityMgr();
	~EntityMgr();
	virtual void init();
	virtual void tick(float dt);
    Entity381 *CreateEntity( Ogre::SceneManager* mSceneMgr,EEntityType entityType, Ogre::Vector3 pos, float yaw = 0,int x=1);
	void SelectNextEntity();
};



#endif
