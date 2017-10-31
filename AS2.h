/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.h
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
#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_

#include "BaseApplication.h"

class TutorialApplication : public BaseApplication
{
public:
  TutorialApplication();
  virtual ~TutorialApplication();
protected:
  virtual void createScene();
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);
   bool tabpreviousframe = false;
    Entity381* entity1;
    Entity381* entity2;
    Entity381* entity3;
    Entity381* entity4;
    Entity381* entity5;
    EntityMgr e;
    EntityMgr * entityMgr=&e;
private:
  bool processUnbufferedInput(const Ogre::FrameEvent& fe);
  virtual bool keyReleased(const OIS::KeyEvent& ke);
};

#endif // #ifndef __TutorialApplication_h_
