///
/// @file SceneManager.h
/// @brief シーン管理
///
#pragma once
#include <map>

/// シーン識別ID
enum class SceneID
{
	/// ライントレース
	LineTrace,

	/// ガレージ
	Garage,

	/// シーソー
	Seesaw,

	/// ルックアップ
	Lookup,

	/// 終了
	End
};

/// シーン変更インターフェース
class ISceneChanger
{
public:

	virtual bool change(SceneID nextSceneID) = 0;
};

/// シーン
class IScene
{
private:

	ISceneChanger* m_sceneChanger = nullptr;

public:

	IScene(ISceneChanger* sceneChanger) :m_sceneChanger(sceneChanger) {};

	virtual ~IScene() {}

	///
	/// @fn bool init()
	/// @brief シーンを初期化する。前のシーンからの受け渡し直後に呼ばれる。Arduinoのsetupと同じ作用
	/// @retval true 成功
	/// @retval false 失敗
	///
	virtual bool init() { return true; }

	///
	/// @fn bool run()
	/// @brief シーンを実行する。init()直後に呼ばれる。Arduinoのloopと同じ作用
	/// @retval true 成功
	/// @retval false 失敗
	///
	virtual bool run() = 0;

	///
	/// @fn bool change(SceneID nextSceneID)
	/// @brief シーンを変更する。次のシーン(難所)への引き渡し時に呼ぶ。
	/// @param nextSceneID 次のシーン(難所)のID
	/// @retval true 成功
	/// @retval false 失敗
	///
	bool change(SceneID nextSceneID)
	{
		return m_sceneChanger->change(nextSceneID);
	}
};

class SceneManager :public ISceneChanger
{
private:

	struct SceneData
	{
		SceneID id;

		IScene* scene;
	};

	SceneData m_scene;

	SceneData m_nextScene;

	std::map<SceneID,IScene*> m_sceneMap;

	bool m_isEnable = false;

public:

	SceneManager();

	~SceneManager();

	bool init(SceneID startID);

	bool run();

	bool change(SceneID nextSceneID)override;

	bool isEnable()
	{
		return m_isEnable;
	}
};