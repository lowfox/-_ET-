///
/// @file SceneManager.h
/// @brief �V�[���Ǘ�
///
#pragma once
#include <map>

/// �V�[������ID
enum class SceneID {
  /// ���C���g���[�X
  LineTrace,

  /// �K���[�W
  Garage,

  /// �V�[�\�[
  Seesaw,

  /// ���b�N�A�b�v
  Lookup,

  /// �I��
  End
};

/// �V�[���ύX�C���^�[�t�F�[�X
class ISceneChanger {
 public:
  virtual bool change(SceneID nextSceneID) = 0;
};

/// �V�[��
class IScene {
 private:
  ISceneChanger* m_sceneChanger = nullptr;

 public:
  IScene(ISceneChanger* sceneChanger) : m_sceneChanger(sceneChanger){};

  virtual ~IScene() {}

  ///
  /// @fn bool init()
  /// @brief
  /// �V�[��������������B�O�̃V�[������̎󂯓n������ɌĂ΂��BArduino��setup�Ɠ�����p
  /// @retval true ����
  /// @retval false ���s
  ///
  virtual bool init() { return true; }

  ///
  /// @fn bool run()
  /// @brief �V�[�������s����Binit()����ɌĂ΂��BArduino��loop�Ɠ�����p
  /// @retval true ����
  /// @retval false ���s
  ///
  virtual bool run() = 0;

  ///
  /// @fn bool change(SceneID nextSceneID)
  /// @brief �V�[����ύX����B���̃V�[��(�)�ւ̈����n�����ɌĂԁB
  /// @param nextSceneID ���̃V�[��(�)��ID
  /// @retval true ����
  /// @retval false ���s
  ///
  bool change(SceneID nextSceneID) {
    return m_sceneChanger->change(nextSceneID);
  }
};

class SceneManager : public ISceneChanger {
 private:
  struct SceneData {
    SceneID id;

    IScene* scene;
  };

  SceneData m_scene;

  SceneData m_nextScene;

  std::map<SceneID, IScene*> m_sceneMap;

  bool m_isEnable = false;

 public:
  SceneManager();

  ~SceneManager();

  bool init(SceneID startID);

  bool run();

  bool change(SceneID nextSceneID) override;

  bool isEnable() { return m_isEnable; }
};