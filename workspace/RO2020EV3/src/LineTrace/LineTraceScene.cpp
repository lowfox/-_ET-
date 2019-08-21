#include "LineTraceScene.h"
#include <Config.h>
#include "Standby.h"
LineTraceScene::LineTraceScene(ISceneChanger* sceneChanger)
  : IScene(sceneChanger) {}

bool LineTraceScene::init() { return true; }

bool LineTraceScene::run() {
  // LineTraceCode
  Standby stanby;       //Stanbyクラスのインスタンス生成

  stanby.traceMain();       //setup関数開始

  return change(LINETRACE_NEXT_SCENE);
}