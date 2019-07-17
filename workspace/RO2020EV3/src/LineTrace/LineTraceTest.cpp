//LineTraceTest.cpp
//LineTraceSceneにそのまま張り付ければ使用可能
#include <Config.h>
#include "LineTraceScene.h"

//テストコード*****************************************
#define CASE_MAX 9  //テストケースの最大数
#define ERROR -1
#define SUCCESSFUL 0

#include <Logger.h>
#include <iostream>
#include "LineTrace.h"
//テストケース格納構造体定義
struct Test {
  MapState state;  //試験用引数
  int trueResult;  //引数に対する期待値
};

LineTraceScene::LineTraceScene(ISceneChanger* sceneChanger)
    : IScene(sceneChanger) {}

bool LineTraceScene::init() { return true; }

bool LineTraceScene::run() {
  // LineTraceCode

  //テストコードStart******************************************
  //テスト用引数とその期待値一覧

  std::array<Test, CASE_MAX> testCase = {{{(MapState)-1, ERROR},
                                          {Straight, SUCCESSFUL},
                                          {SmallRightTurn, SUCCESSFUL},
                                          {SmallLeftTurn, SUCCESSFUL},
                                          {LargeRightTurn, SUCCESSFUL},
                                          {LargeLeftTurn, SUCCESSFUL},
                                          {Goal, SUCCESSFUL},
                                          {StateEnd, ERROR},
                                          {(MapState)7, ERROR}}};

  // LineTraceクラス生成
  LineTrace lineTrace;
  int result = 0;

  for (auto cnt = std::begin(testCase); cnt <= std::end(testCase);cnt++){
    result = lineTrace.lineTraceDrive(testCase[cnt].state);
    //実際の戻り値が期待した戻り値と不一致だった場合
    if (result != testCase[cnt].trueResult) {
      EV3_LOG_ERROR("Cnt = %d is error\n", cnt);
    } else {
      EV3_LOG("Cnt = %d is OK\n", cnt);
    }
  }
  EV3_LOG("End\n");
  //テストコードEnd*************************************************

  return change(LINETRACE_NEXT_SCENE);
}