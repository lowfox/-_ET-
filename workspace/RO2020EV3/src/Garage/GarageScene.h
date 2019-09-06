
#include <SceneManager.h>

/// �K���[�W�V�[��
class GarageScene :public IScene
{
public:

	GarageScene(ISceneChanger* sceneChanger);
	
	class garage_in
	{
	public:
		//�֐���`
		void Start_Process();			//���C���̑����������߂�

	private:
		//�ϐ���`
		float Initial_Distance;								//���������l
	};
	///
	/// @fn bool init()
	/// @brief �K���[�W�V�[��������������B�O�̃V�[������̎󂯓n������ɌĂ΂��BArduino��setup�Ɠ�����p
	/// @retval true ����
	/// @retval false ���s
	///
	bool init()override;

	///
	/// @fn bool run()
	/// @brief �K���[�W�V�[�������s����Binit()����ɌĂ΂��B
	/// @retval true ����
	/// @retval false ���s
	///
	bool run()override;
};
