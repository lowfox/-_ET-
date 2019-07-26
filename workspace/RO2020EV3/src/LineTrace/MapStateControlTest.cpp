#include <Config.h>
#include "LineTraceScene.h"
//MapStateControlTest.cpp
//LineTraceScene�ɂ��̂܂ܒ���t����Ύg�p�\

//�e�X�g�R�[�h*****************************************
#define CASE_MAX 49  //�e�X�g�P�[�X�̍ő吔
#define ERROR -1
#define SUCCESSFUL 2

#include <Logger.h>
#include "MapStateControl.h"

LineTraceScene::LineTraceScene(ISceneChanger * sceneChanger)
  : IScene(sceneChanger) {}

bool LineTraceScene::init() { return true; }

bool LineTraceScene::run() {
  // LineTraceCode

  //�e�X�g�R�[�hStart******************************************
  //L�R�[�X���Ғl
  std::array<MapState, CASE_MAX> trueResultLeft = {
  Straight,//���Ғl�̓e�X�g�̒l���߂Ă���B100��臒l�Ƃ���Ȃ�A99��Straight�A100��Straight�A101��LargeLeftTurn�݂����ɂ���B
  Straight,
  Straight,
  LargeLeftTurn,
  LargeLeftTurn,
  LargeLeftTurn,
  Straight,
  Straight,
  Straight,
  LargeLeftTurn,
  LargeLeftTurn,
  LargeLeftTurn,
  Straight,
  Straight,
  Straight,
  SmallLeftTurn,
  SmallLeftTurn,
  SmallLeftTurn,
  SmallRightTurn,
  SmallRightTurn,
  SmallRightTurn,
  Straight,
  Straight,
  Straight,
  LargeRightTurn,
  LargeRightTurn,
  LargeRightTurn,
  Straight,
  Straight,
  Straight,
  LargeRightTurn,
  LargeRightTurn,
  LargeRightTurn,
  Straight,
  Straight,
  Straight,
  SmallRightTurn,
  SmallRightTurn,
  SmallRightTurn,
  SmallLeftTurn,
  SmallLeftTurn,
  SmallLeftTurn,
  Straight,
  Straight,
  Straight,
  Goal,
  Goal,
  Goal,
  Goal
  };

  //R�R�[�X���Ғl
  std::array<MapState, CASE_MAX> trueResultRight = {
  Straight,
  Straight,
  Straight,
  LargeRightTurn,
  LargeRightTurn,
  LargeRightTurn,
  Straight,
  Straight,
  Straight,
  LargeRightTurn,
  LargeRightTurn,
  LargeRightTurn,
  Straight,
  Straight,
  Straight,
  SmallRightTurn,
  SmallRightTurn,
  SmallRightTurn,
  SmallLeftTurn,
  SmallLeftTurn,
  SmallLeftTurn,
  Straight,
  Straight,
  Straight,
  LargeLeftTurn,
  LargeLeftTurn,
  LargeLeftTurn,
  Straight,
  Straight,
  Straight,
  LargeLeftTurn,
  LargeLeftTurn,
  LargeLeftTurn,
  Straight,
  Straight,
  Straight,
  SmallLeftTurn,
  SmallLeftTurn,
  SmallLeftTurn,
  SmallRightTurn,
  SmallRightTurn,
  SmallRightTurn,
  Straight,
  Straight,
  Straight,
  Goal,
  Goal,
  Goal,
  Goal
  };

  // MapStateControl�N���X����
  MapStateControl mapStateControl;
  MapState result;                    //�߂�l�i�[

  for (int cnt = 0; cnt < CASE_MAX; cnt++) {
    result = mapStateControl.drivePosition();
    //���ۂ̖߂�l�����҂����߂�l�ƕs��v�������ꍇ
    if (COURSE_MODE == LEFT_COURSE) {
      if (result == trueResultLeft[cnt]) {
        EV3_LOG("case %d = SUCCESSFUL\n", cnt);
      }
      else {
        EV3_LOG("case %d = ERROR\n", cnt);
      }
    }
    else if (COURSE_MODE == RIGHT_COURSE) {
      if (result == trueResultRight[cnt]) {
        EV3_LOG("case %d = SUCCESSFUL\n", cnt);
      }
      else {
        EV3_LOG("case %d = ERROR\n", cnt);
      }
    }
  }

  EV3_LOG("End\n");
  //�e�X�g�R�[�hEnd*************************************************

  return change(LINETRACE_NEXT_SCENE);
}