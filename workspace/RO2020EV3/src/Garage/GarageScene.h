
#include <SceneManager.h>

/// �ｽK�ｽ�ｽ�ｽ[�ｽW�ｽV�ｽ[�ｽ�ｽ
class GarageScene :public IScene
{
public:

	GarageScene(ISceneChanger* sceneChanger);
	
	class garage_in
	{
	public:
		//�ｽﾖ撰ｿｽ�ｽ�ｽ`
		void Start_Process();			//�ｽﾂ�ｿｽ�ｽC�ｽ�ｽ�ｽﾌ托ｿｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽﾟゑｿｽ

	private:
		//�ｽﾏ撰ｿｽ�ｽ�ｽ`
		float Initial_Distance;								//�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽl
	};
	///
	/// @fn bool init()
	/// @brief �ｽK�ｽ�ｽ�ｽ[�ｽW�ｽV�ｽ[�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽB�ｽO�ｽﾌシ�ｽ[�ｽ�ｽ�ｽ�ｽ�ｽ�ｽﾌ受け渡�ｽ�ｽ�ｽ�ｽ�ｽ�ｽﾉ呼ばゑｿｽ�ｽBArduino�ｽ�ｽsetup�ｽﾆ難ｿｽ�ｽ�ｽ�ｽ�ｽp
	/// @retval true �ｽ�ｽ�ｽ�ｽ
	/// @retval false �ｽ�ｽ�ｽs
	///
	bool init()override;

	///
	/// @fn bool run()
	/// @brief �ｽK�ｽ�ｽ�ｽ[�ｽW�ｽV�ｽ[�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽs�ｽ�ｽ�ｽ�ｽBinit()�ｽ�ｽ�ｽ�ｽﾉ呼ばゑｿｽ�ｽB
	/// @retval true �ｽ�ｽ�ｽ�ｽ
	/// @retval false �ｽ�ｽ�ｽs
	///
	bool run()override;
};
