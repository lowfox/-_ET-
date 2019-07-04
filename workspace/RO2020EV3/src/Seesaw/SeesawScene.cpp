#include "SeesawScene.h"

SeesawScene::SeesawScene(ISceneChanger* sceneChanger):IScene(sceneChanger)
{
}

bool SeesawScene::init()
{
	return true;
}

bool SeesawScene::run()
{
	// SeesawCode


	// Žó‚¯“n‚µŽž‚ÉŒÄ‚Ô
	return change(SceneID::Garage);
}
