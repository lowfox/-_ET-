#include "LineTraceScene.h"
#include <Config.h>
#include "Standby.h"
#include <Drive.h>
#include <Logger.h>
LineTraceScene::LineTraceScene(ISceneChanger* sceneChanger)
  : IScene(sceneChanger) {}

bool LineTraceScene::init() { return true; }

bool LineTraceScene::run() {
  // LineTraceCode
  Standby stanby;       //Stanby?申N?申?申?申X?申��C?申?申?申X?申^?申?申?申X?申?申?申?申

  stanby.traceMain();       //setup?申��鐃�?申J?申n
  
  return change(LINETRACE_NEXT_SCENE);
}