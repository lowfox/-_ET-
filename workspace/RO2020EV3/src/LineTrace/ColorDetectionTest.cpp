#include "LineTraceScene.h"
#include <Config.h>
// ColorDetectionTest.cpp
// LineTraceSceneにそのまま張り付ければ使用可能

//テストコード*****************************************

#include <Logger.h>
#include "ColorDetection.h"

LineTraceScene::LineTraceScene(ISceneChanger* sceneChanger)
  : IScene(sceneChanger) {}

bool LineTraceScene::init() { return true; }

bool LineTraceScene::run() {
  // LineTraceCode

  //実機に入れて、センサーを色の上に乗せればログが出るはず。
  //テストコードStart******************************************

  // ColorDetectionクラス生成
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
  //テストコードEnd*************************************************

  return change(LINETRACE_NEXT_SCENE);
}