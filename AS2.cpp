/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/
      Tutorial Framework
      http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/
#include "EntityMgr.h"
#include "AS2.h"
#include "Types.h"
#include "Entity381.h"
#include<iostream>
using namespace std;
//-------------------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
}
//-------------------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//-------------------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    Ogre::Vector3 b1=Ogre::Vector3 (0,0,0);
    Ogre::Vector3 b2=Ogre::Vector3 (100,0,0);
    Ogre::Vector3 b3=Ogre::Vector3 (0,0,-300);
    Ogre::Vector3 b4=Ogre::Vector3 (0,0,-700);
    Ogre::Vector3 b5=Ogre::Vector3 (-200,0,-200);
    float head=0.0;
    Ogre::Real rotate = 1;
    mSceneMgr->setAmbientLight(Ogre::ColourValue(1,1,1));
    mCamera->setPosition(0, 120,300);
    //create point light
    Ogre::Light* pointLight = mSceneMgr->createLight("PointLight");
    pointLight->setType(Ogre::Light::LT_POINT);
    pointLight->setPosition(250, 150, 250);
    pointLight->setDiffuseColour(Ogre::ColourValue::White);
    pointLight->setSpecularColour(Ogre::ColourValue::White);
        // Create ground
    Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
    Ogre::MeshManager::getSingleton().createPlane("ground",
    Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    plane, 10000, 10000, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
    Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
    groundEntity->setMaterialName("Examples/sea");
    entity1=entityMgr->CreateEntity(mSceneMgr,ALIEN,b1,head);
    entity2=entityMgr->CreateEntity(mSceneMgr,CIGARETTE,b2,head);
    entity3=entityMgr->CreateEntity(mSceneMgr,DDG,b3,head);
    entity4=entityMgr->CreateEntity(mSceneMgr,CVN,b4,head);
    entity5=entityMgr->CreateEntity(mSceneMgr,FRIGATE,b5,head);

}
 bool TutorialApplication::keyReleased(const OIS::KeyEvent& ke)
{
  switch (ke.key)
  {
    case OIS::KC_TAB:
       entityMgr->SelectNextEntity();
       break;
    default:
       break;
   }
}
bool TutorialApplication::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool ret = BaseApplication::frameRenderingQueued(fe);

  if (!processUnbufferedInput(fe))
      return false;

  return ret;
}
bool TutorialApplication::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
    static float rad1=0;
    static float rad2=0;
    static float rad3=0;
    static float rad4=0;
    static float radc1=0;
    static float radc2=0;
    entityMgr->tick(fe.timeSinceLastFrame);
    if (mKeyboard->isKeyDown(OIS::KC_NUMPAD8))
    {
       if(entity1->isSelected)
       {
          if(entity1->desiredSpeed<=entity1->maxSpeed)
          {
            entity1->stopboat=false;
            entity1->desiredSpeed+=1;
          }
       }

       if(entity2->isSelected)
       {
          if(entity2->desiredSpeed<=entity2->maxSpeed)
          {
            entity2->stopboat=false;
            entity2->desiredSpeed+=1;
          }
       }
       if(entity3->isSelected)
       {
          if(entity3->desiredSpeed<=entity3->maxSpeed)
          {
            entity3->stopboat=false;
            entity3->desiredSpeed+=1;
          }
       }
       if(entity4->isSelected)
       {
          if(entity4->desiredSpeed<=entity4->maxSpeed)
          {
            entity4->stopboat=false;
            entity4->desiredSpeed+=1;
          }
       }
       if(entity5->isSelected)
       {
          if(entity5->desiredSpeed<=entity5->maxSpeed)
          {
            entity5->stopboat=false;
            entity5->desiredSpeed+=1;
          }
       }

    }
    if (mKeyboard->isKeyDown(OIS::KC_NUMPAD2))
    {
       if(entity1->isSelected)
       {
          if(entity1->desiredSpeed>entity1->minSpeed)
          {
            entity1->stopboat=false;
            entity1->desiredSpeed-=1;
          }
       }

       if(entity2->isSelected)
       {
          if(entity2->desiredSpeed>entity2->minSpeed)
          {
            entity2->stopboat=false;
            entity2->desiredSpeed-=1;
          }
       }
       if(entity3->isSelected)
       {
          if(entity3->desiredSpeed>entity3->minSpeed)
          {
            entity3->stopboat=false;
            entity3->desiredSpeed-=1;
          }
       }
       if(entity4->isSelected)
       {
          if(entity4->desiredSpeed>entity4->minSpeed)
          {
            entity4->stopboat=false;
            entity4->desiredSpeed-=1;
          }
       }
       if(entity5->isSelected)
       {
         if(entity5->desiredSpeed>entity5->minSpeed)
          {
            entity5->stopboat=false;
            entity5->desiredSpeed-=1;
          }
       }

    }
    if (mKeyboard->isKeyDown(OIS::KC_NUMPAD6))
    {
        if(entity1->isSelected)
       {
          entity1->stopboat=false;
          entity1->desiredHeading +=.01;
       }
        if(entity2->isSelected)
       {
          entity2->stopboat=false;
          entity2->desiredHeading +=.01;
       }
        if(entity3->isSelected)
       {
          entity3->stopboat=false;
          entity3->desiredHeading +=.01;
       }
        if(entity4->isSelected)
       {
          entity4->stopboat=false;
          entity4->desiredHeading +=.01;
       }
        if(entity5->isSelected)
       {
          entity5->stopboat=false;
          entity5->desiredHeading +=.01;
       }

     }
    if (mKeyboard->isKeyDown(OIS::KC_NUMPAD4))
    {
        if(entity1->isSelected)
       {
          entity1->stopboat=false;
          entity1->desiredHeading -=.01;
       }
        if(entity2->isSelected)
       {
          entity2->stopboat=false;
          entity2->desiredHeading -=.01;
       }
        if(entity3->isSelected)
       {
          entity3->stopboat=false;
          entity3->desiredHeading -=.01;
       }
        if(entity4->isSelected)
       {
          entity4->stopboat=false;
          entity4->desiredHeading -=.01;
       }
        if(entity5->isSelected)
       {
          entity5->stopboat=false;
          entity5->desiredHeading -=.01;
       }

     }
    Ogre::Vector3 cdirVec = mCamera->getPosition();
    if (mKeyboard->isKeyDown(OIS::KC_R))
        cdirVec.y += 50 * fe.timeSinceLastFrame;

    if (mKeyboard->isKeyDown(OIS::KC_F))
        cdirVec.y -= 50 * fe.timeSinceLastFrame;
    if (mKeyboard->isKeyDown(OIS::KC_S))
        cdirVec.z += 50 * fe.timeSinceLastFrame;

    if (mKeyboard->isKeyDown(OIS::KC_W))
        cdirVec.z -= 50 * fe.timeSinceLastFrame;
    if (mKeyboard->isKeyDown(OIS::KC_D))
        cdirVec.x += 50 * fe.timeSinceLastFrame;

    if (mKeyboard->isKeyDown(OIS::KC_A))
        cdirVec.x -= 50 * fe.timeSinceLastFrame;
    if(mKeyboard->isKeyDown(OIS::KC_E))
    {
       rad1+=.001;
       rad2=-rad1;
       radc2=-rad1;
       mCamera->setOrientation(Ogre::Quaternion::IDENTITY);
       mCamera->yaw(Ogre::Radian(-rad1));
       mCamera->pitch(Ogre::Radian(radc1));


    }
    if(mKeyboard->isKeyDown(OIS::KC_Q))
    {
       rad2+=.001;
       rad1=-rad2;
       radc2=rad2;
       mCamera->setOrientation(Ogre::Quaternion::IDENTITY);
       mCamera->yaw(Ogre::Radian(rad2));
       mCamera->pitch(Ogre::Radian(radc1));


    }
     if(mKeyboard->isKeyDown(OIS::KC_X))
    {
       rad3+=.001;
       rad4=-rad3;
       radc1=-rad3;
       mCamera->setOrientation(Ogre::Quaternion::IDENTITY);
       mCamera->pitch(Ogre::Radian(-rad3));
       mCamera->yaw(Ogre::Radian(radc2));

    }
    if(mKeyboard->isKeyDown(OIS::KC_Z))
    {
       rad4+=.001;
       rad3=-rad4;
       radc1=rad4;
       mCamera->setOrientation(Ogre::Quaternion::IDENTITY);
       mCamera->pitch(Ogre::Radian(rad4));
       mCamera->yaw(Ogre::Radian(radc2));

    }
    mCamera->setPosition(cdirVec);
    entityMgr->tick(fe.timeSinceLastFrame);
    return true;
}


#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        TutorialApplication app;

        try {
            app.go();
        } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif
