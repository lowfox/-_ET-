#include "LookupScene.h"
#include "TestData.h"
LookupScene::LookupScene(ISceneChanger* sceneChanger) : IScene(sceneChanger)
{
}

bool LookupScene::init()
{
	return true;
}

bool LookupScene::run()
{
	MasterControl m_ctrl;

	// LookupCode
	m_ctrl.LookUp();
	
	//�󂯓n�����ɌĂ�
	return change(SceneID::Garage);
}
