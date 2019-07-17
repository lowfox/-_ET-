//LineTraceTest.cpp
//LineTraceScene�ɂ��̂܂ܒ���t����Ύg�p�\
#include <Config.h>
#include "LineTraceScene.h"

//�e�X�g�R�[�h*****************************************
#define CASE_MAX 9  //�e�X�g�P�[�X�̍ő吔
#define ERROR -1
#define SUCCESSFUL 0

#include <Logger.h>
#include <iostream>
#include "LineTrace.h"
//�e�X�g�P�[�X�i�[�\���̒�`
struct Test {
  MapState state;  //�����p����
  int trueResult;  //�����ɑ΂�����Ғl
};

LineTraceScene::LineTraceScene(ISceneChanger* sceneChanger)
    : IScene(sceneChanger) {}

bool LineTraceScene::init() { return true; }

bool LineTraceScene::run() {
  // LineTraceCode

  //�e�X�g�R�[�hStart******************************************
  //�e�X�g�p�����Ƃ��̊��Ғl�ꗗ

  std::array<Test, CASE_MAX> testCase = {{{(MapState)-1, ERROR},
                                          {Straight, SUCCESSFUL},
                                          {SmallRightTurn, SUCCESSFUL},
                                          {SmallLeftTurn, SUCCESSFUL},
                                          {LargeRightTurn, SUCCESSFUL},
                                          {LargeLeftTurn, SUCCESSFUL},
                                          {Goal, SUCCESSFUL},
                                          {StateEnd, ERROR},
                                          {(MapState)7, ERROR}}};

  // LineTrace�N���X����
  LineTrace lineTrace;
  int result = 0;

  for (auto cnt = std::begin(testCase); cnt <= std::end(testCase);cnt++){
    result = lineTrace.lineTraceDrive(testCase[cnt].state);
    //���ۂ̖߂�l�����҂����߂�l�ƕs��v�������ꍇ
    if (result != testCase[cnt].trueResult) {
      EV3_LOG_ERROR("Cnt = %d is error\n", cnt);
    } else {
      EV3_LOG("Cnt = %d is OK\n", cnt);
    }
  }
  EV3_LOG("End\n");
  //�e�X�g�R�[�hEnd*************************************************

  return change(LINETRACE_NEXT_SCENE);
}