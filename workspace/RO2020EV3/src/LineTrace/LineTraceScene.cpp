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
  Standby stanby;       //Stanby�N���X�̃C���X�^���X����

  stanby.traceMain();       //setup�֐��J�n

  return change(LINETRACE_NEXT_SCENE);
}