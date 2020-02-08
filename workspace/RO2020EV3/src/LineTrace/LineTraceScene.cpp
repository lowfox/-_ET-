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
  Standby
      stanby;  // Stanby?øΩN?øΩ?øΩ?øΩX?øΩÃÉC?øΩ?øΩ?øΩX?øΩ^?øΩ?øΩ?øΩX?øΩ?øΩ?øΩ?øΩ

  stanby.traceMain();  // setup?øΩ÷êÔøΩ?øΩJ?øΩn

  return change(LINETRACE_NEXT_SCENE);
}