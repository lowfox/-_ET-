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
	if(!m_ctrl.LookUp())
	{
		return false;
	}
	//�󂯓n�����ɌĂ�
	return change(SceneID::Garage);
}
