#pragma once
#include <SceneManager.h>

/// ���C���g���[�X�V�[��
class LineTraceScene :public IScene
{
public:

	LineTraceScene(ISceneChanger* sceneChanger);

	///
	/// @fn bool init()
	/// @brief ���C���g���[�X�V�[��������������B�O�̃V�[������̎󂯓n������ɌĂ΂��BArduino��setup�Ɠ�����p
	/// @retval true ����
	/// @retval false ���s
	///
	bool init()override;

	///
	/// @fn bool run()
	/// @brief ���C���g���[�X�V�[�������s����Binit()����ɌĂ΂��B
	/// @retval true ����
	/// @retval false ���s
	///
	bool run()override;
};