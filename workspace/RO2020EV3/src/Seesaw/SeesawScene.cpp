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


	// �󂯓n�����ɌĂ�
	return change(SceneID::Garage);
}
