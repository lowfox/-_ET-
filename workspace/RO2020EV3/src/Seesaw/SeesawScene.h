#pragma once
#include <SceneManager.h>
#include"seesawCapture.h"
#include"seesawTest.h"

#include<Drive.h>
#include<RyujiEv3.h>
#include<Logger.h>

#include"lineTracer.h"
///�@�V�[�\�[�V�[��
class SeesawScene :public IScene
{
public:

	SeesawScene(ISceneChanger* sceneChanger);
	
	///
	/// @fn bool init()
	/// @brief �V�[�\�[�V�[��������������B�O�̃V�[������̎󂯓n������ɌĂ΂��BArduino��setup�Ɠ�����p
	/// @retval true ����
	/// @retval false ���s
	///
	bool init()override;

	///
	/// @fn bool run()
	/// @brief �V�[�\�[�V�[�������s����Binit()����ɌĂ΂��B
	/// @retval true ����
	/// @retval false ���s
	///
	bool run()override;
};