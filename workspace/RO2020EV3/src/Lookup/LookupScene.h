#pragma once
#include <SceneManager.h>

/// ルックアップシーン
class LookupScene :public IScene
{
public:

	LookupScene(ISceneChanger* sceneChanger);

	///
	/// @fn bool init()
	/// @brief ルックアップシーンを初期化する。前のシーンからの受け渡し直後に呼ばれる。Arduinoのsetupと同じ作用
	/// @retval true 成功
	/// @retval false 失敗
	///
	bool init()override;

	///
	/// @fn bool run()
	/// @brief ルックアップシーンを実行する。init()直後に呼ばれる。
	/// @retval true 成功
	/// @retval false 失敗
	///
	bool run()override;
};