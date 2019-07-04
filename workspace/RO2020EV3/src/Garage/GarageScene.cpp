#include "GarageScene.h"

GarageScene::GarageScene(ISceneChanger* sceneChanger) : IScene(sceneChanger)
{
}

bool GarageScene::init()
{
	return true;
}

bool GarageScene::run()
{
	// GarageCode

	return change(SceneID::End);
}
