
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
		void blue_line_total_range_calculation();			//���C���̑����������߂�
		void provision_range_calculation();					//���C���I�[����K���[�W�C���܂ł̑���������C���̑���������䗦�Ŋ��苗�������߂�
		void check_up_to_garage_in();						//���C���I�[����K���[�W�܂ł̊��苗���𑖍s���������`�F�b�N
	private:
		//�ϐ���`
		int Judgment;										//���f�ϐ�
		float Distance_initia;								//���������l
		float current_range_value;							//���݂̋����l
		float range_up_to_garage;							//���C���I�[����K���[�W�܂ł̋����l
		float measuring_range_value;						//���蒆�̋����l
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
