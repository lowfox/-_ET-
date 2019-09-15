#include <Config.h>
#include "LineTraceScene.h"

// DistanceMeasureTest.cpp
// LineTraceScene�ɂ��̂܂ܒ���t����Ύg�p�\

//�e�X�g�R�[�h*****************************************
#define CASE_MAX 7       //�e�X�g�P�[�X�̍ő吔
#define LINETRACE_DEBUG  //�f�o�b�O���[�h(�R�����g�A�E�g����Ɩ{�ԃ��[�h�ɂȂ�)

#include "LinetraceMoc.h"

#include <Logger.h>
#include <array>
#include <Drive.h>

LineTraceScene::LineTraceScene(ISceneChanger* sceneChanger)
    : IScene(sceneChanger) {}

bool LineTraceScene::init() { return true; }

bool LineTraceScene::run() {
  // LineTraceCode

  //�e�X�g�R�[�hStart******************************************

  //���Ғl
  std::array<float, CASE_MAX> trueResult = {
      0.0f, 0.1f, 1.0f, 10.0f, 100.0f, 1073741823.5f, 2147483647.0f};

  float result = 0.0;  //�߂�l�i�[
  // trueResult�̗v�f�������[�v
  for (auto& cnt : trueResult) {
    //�֐��Ăяo��
    result = GET_DISTANCE();
    //���ʔ�r
    if (result == cnt) {
      EV3_LOG("case %d = SUCCESSFUL %f", (int)cnt, result);
    } else {
      EV3_LOG("case %d = ERROR %f", (int)cnt, result);
    }
  }

  EV3_LOG("End\n");
  //�e�X�g�R�[�hEnd*************************************************

  return change(LINETRACE_NEXT_SCENE);
}