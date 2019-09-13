#include "LineTraceScene.h"
#include <Config.h>
// ColorDetectionTest.cpp
// LineTraceScene�ɂ��̂܂ܒ���t����Ύg�p�\

//�e�X�g�R�[�h*****************************************

#include <Logger.h>
#include "ColorDetection.h"

LineTraceScene::LineTraceScene(ISceneChanger* sceneChanger)
  : IScene(sceneChanger) {}

bool LineTraceScene::init() { return true; }

bool LineTraceScene::run() {
  // LineTraceCode

  //���@�ɓ���āA�Z���T�[��F�̏�ɏ悹��΃��O���o��͂��B
  //�e�X�g�R�[�hStart******************************************

  // ColorDetection�N���X����
  ColorDetection colorDetection;

  while (1) {
    if (colorDetection.getBlackColor() == true) {
      EV3_LOG("Now Black\n");
    }
    else if (colorDetection.getBlueColor() == true) {
      EV3_LOG("Now Blue\n");
    }
    else {
      EV3_LOG("No Color\n");
    }
  }

  EV3_LOG("End\n");
  //�e�X�g�R�[�hEnd*************************************************

  return change(LINETRACE_NEXT_SCENE);
}