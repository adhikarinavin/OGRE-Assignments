

#include "EntityMgr.h"
EntityMgr::EntityMgr()
{
	entities.clear();
	selectedEntity = 0;
}

EntityMgr::~EntityMgr()
{
	entities.clear();
}

void EntityMgr::tick(float dt)
{
	for (std::list<Entity381 *>::const_iterator it = entities.begin(); it != entities.end(); ++it){
		(*it)->Tick(dt);
		if ((*it)->isSelected)
			this->selectedEntity = (*it);
	}
}

void EntityMgr::init()
{
	return;
}

Entity381* EntityMgr::CreateEntity (Ogre::SceneManager* mSceneMgr,EEntityType entityType, Ogre::Vector3 position, float heading,int x)
{

	Entity381 *ent;
	switch(entityType){
	case ALIEN:
		ent = new Alien(position, heading);
		break;
	case CIGARETTE:
		ent = new Cigarette(position, heading);
		break;
	case DDG:
		ent = new Ddg(position, heading);
		break;
	case CVN:
		ent = new Cvn(position, heading);
		break;
	case FRIGATE:
		ent = new Frigate(position, heading);
		break;
	default:
		ent = new Ddg(position, heading);
		break;
	}
    ent->ogreEntity =mSceneMgr->createEntity(ent->meshfile);
    ent->ogreSceneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(ent->pos);
    ent->ogreSceneNode->attachObject(ent->ogreEntity);
    ent->ogreSceneNode->yaw(Ogre::Radian(ent->heading));

    switch(entityType){
	case ALIEN:
        ent->ogreEntity->setMaterialName("Examples/5");
		break;
	case CIGARETTE:
		ent->ogreEntity->setMaterialName("Examples/5");
		break;
	case DDG:
		ent->ogreEntity->setMaterialName("Examples/3");
		break;
	case CVN:
		ent->ogreEntity->setMaterialName("Examples/4");
		break;
	case FRIGATE:
		ent->ogreEntity->setMaterialName("Examples/2");
		break;
	default:
		break;
	}
	entities.push_front(ent);
	return ent;
}
void EntityMgr::SelectNextEntity()
{
	int n = 0;
	bool inside=false;
    std::cout << "Starting point of list" << std::endl;
	for (std::list<Entity381 *>::const_iterator it = entities.begin(); it != entities.end(); ++it)
    {
		n++;
		if((*it)->isSelected)
        {
			inside=true;
			(*it)->isSelected = false;
			it++;
			if(it == entities.end())
            {
				std::cout << "End point of list" << std::endl;
				selectedEntity = *(entities.begin());
			} else
			 {
				selectedEntity = *it;
				std::cout << "End of ents" << std::endl;
             }
			selectedEntity->isSelected = true;
			break;
		  }
         if(n==5 && inside==false)
         {
             selectedEntity = *(entities.begin());
		     selectedEntity->isSelected = true;
		     std::cout << "First time Selected" << std::endl;

         }

	}

}

