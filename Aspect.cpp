

#include "Aspect.h"
Aspect::Aspect (Entity381 * ent)
{
	this->entity = ent;

}

Aspect::~Aspect()
{

}

Renderable::Renderable(Entity381 * ent): Aspect(ent)
{
	return;
}

Renderable::~Renderable()
{

}

void Renderable::Tick(float dt)
{

    entity->ogreSceneNode->setPosition(entity->pos);
    entity->ogreSceneNode->setOrientation(Ogre::Quaternion::IDENTITY);
    entity->ogreSceneNode->yaw(Ogre::Radian(-entity->heading));
	if (entity->isSelected)
    {
        entity->ogreSceneNode->showBoundingBox(true);

    }

	else
    {
       entity->ogreSceneNode->showBoundingBox(false);
       if(entity->speed!=0||entity->heading!=0)
       {
           //entity->stopboat=true;
       }
       //entity->stop();

    }
}

Physics::Physics(Entity381 * ent): Aspect(ent)
{

}

Physics::~Physics()
{

}

//static float RadToDegree = 57.2958;

void Physics::Tick(float dt)
{

	if(entity->speed < entity->desiredSpeed)
    {
        entity->speed += entity->acceleration *dt;
    }

	if(entity->speed > entity->desiredSpeed)
    {
      entity->speed -= entity->acceleration *dt;
    }

	if(entity->heading < entity->desiredHeading)
    {
        entity->heading += entity->turnRate * dt;
    }

	if(entity->heading > entity->desiredHeading)
    {
       entity->heading -= entity->turnRate * dt;
    }

	entity->vel = Ogre::Vector3(cos(entity->heading) * entity->speed, 0, sin(entity->heading) * entity->speed);
	entity->pos += entity->vel * dt;

}
