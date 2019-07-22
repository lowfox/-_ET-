
#include <SceneManager.h>

/// ガレージシーン
class GarageScene :public IScene
{
public:

	GarageScene(ISceneChanger* sceneChanger);
	
	class garage_in
	{
	public:
		//関数定義
		void blue_line_total_range_calculation();			//青ラインの総距離を求める
		void provision_range_calculation();					//青ライン終端からガレージインまでの総距離を青ラインの総距離から比率で既定距離を求める
		void check_up_to_garage_in();						//青ライン終端からガレージまでの既定距離を走行したかをチェック
	private:
		//変数定義
		int Judgment;										//判断変数
		float Distance_initia;								//初期距離値
		float current_range_value;							//現在の距離値
		float range_up_to_garage;							//青ライン終端からガレージまでの距離値
		float measuring_range_value;						//測定中の距離値
	};
	///
	/// @fn bool init()
	/// @brief ガレージシーンを初期化する。前のシーンからの受け渡し直後に呼ばれる。Arduinoのsetupと同じ作用
	/// @retval true 成功
	/// @retval false 失敗
	///
	bool init()override;

	///
	/// @fn bool run()
	/// @brief ガレージシーンを実行する。init()直後に呼ばれる。
	/// @retval true 成功
	/// @retval false 失敗
	///
	bool run()override;
};
