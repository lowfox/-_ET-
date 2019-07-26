#include <Config.h>
#include "LineTraceScene.h"
//MapStateControlTest.cpp
//LineTraceSceneにそのまま張り付ければ使用可能

//テストコード*****************************************
#define CASE_MAX 49  //テストケースの最大数
#define ERROR -1
#define SUCCESSFUL 2

#include <Logger.h>
#include "MapStateControl.h"

LineTraceScene::LineTraceScene(ISceneChanger * sceneChanger)
  : IScene(sceneChanger) {}

bool LineTraceScene::init() { return true; }

bool LineTraceScene::run() {
  // LineTraceCode

  //テストコードStart******************************************
  //Lコース期待値
  std::array<MapState, CASE_MAX> trueResultLeft = {
  Straight,//期待値はテストの値決めてから。100が閾値とするなら、99はStraight、100はStraight、101はLargeLeftTurnみたいにする。
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

  //Rコース期待値
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

  // MapStateControlクラス生成
  MapStateControl mapStateControl;
  MapState result;                    //戻り値格納

  for (int cnt = 0; cnt < CASE_MAX; cnt++) {
    result = mapStateControl.drivePosition();
    //実際の戻り値が期待した戻り値と不一致だった場合
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
  //テストコードEnd*************************************************

  return change(LINETRACE_NEXT_SCENE);
}