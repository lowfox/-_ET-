#include "LookupScene.h"

LookupScene::LookupScene(ISceneChanger* sceneChanger) : IScene(sceneChanger) {}

bool LookupScene::init() { return true; }

bool LookupScene::run() {
  // LookupCode

  //�󂯓n�����ɌĂ�
  return change(SceneID::Garage);
}
