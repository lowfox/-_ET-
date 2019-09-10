#include "LookupScene.h"

LookupScene::LookupScene(ISceneChanger* sceneChanger) : IScene(sceneChanger) {}

bool LookupScene::init() { return true; }

bool LookupScene::run() {
  // LookupCode

  //Žó‚¯“n‚µŽž‚ÉŒÄ‚Ô
  return change(SceneID::Garage);
}
