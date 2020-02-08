#include <Config.h>
#include "LineTraceScene.h"

// DistanceMeasureTest.cpp
// LineTraceSceneにそのまま張り付ければ使用可能

//テストコード*****************************************
#define CASE_MAX 7       //テストケースの最大数
#define LINETRACE_DEBUG  //デバッグモード(コメントアウトすると本番モードになる)

#include "LinetraceMoc.h"

#include <Logger.h>
#include <array>
#include <Drive.h>

LineTraceScene::LineTraceScene(ISceneChanger* sceneChanger)
    : IScene(sceneChanger) {}

bool LineTraceScene::init() { return true; }

bool LineTraceScene::run() {
  // LineTraceCode

  //テストコードStart******************************************

  //期待値
  std::array<float, CASE_MAX> trueResult = {
      0.0f, 0.1f, 1.0f, 10.0f, 100.0f, 1073741823.5f, 2147483647.0f};

  float result = 0.0;  //戻り値格納
  // trueResultの要素数分ループ
  for (auto& cnt : trueResult) {
    //関数呼び出し
    result = GET_DISTANCE();
    //結果比較
    if (result == cnt) {
      EV3_LOG("case %d = SUCCESSFUL %f", (int)cnt, result);
    } else {
      EV3_LOG("case %d = ERROR %f", (int)cnt, result);
    }
  }

  EV3_LOG("End\n");
  //テストコードEnd*************************************************

  return change(LINETRACE_NEXT_SCENE);
}