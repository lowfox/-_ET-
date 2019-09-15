// MapStateControl.cpp
// includeファイル
#include "MapStateControl.h"
#include <Logger.h>
#include <RyujiEv3.h>
#include <Config.h>

// 定数定義
#define ERROR -1

MapStateControl::MapStateControl() {}

MapStateControl::~MapStateControl() {}

int MapStateControl::drivePosition() {
  float milage = 0.0f;  //累計距離

  //累計距離取得
  milage = DistanceMeasure::getDistance();

  //コースがLかRによって処理を切り替え(設定されていなければエラー終了)
  if (LINETRACE_NEXT_SCENE == SceneID::Seesaw) {
    //現在の距離が現在の規定距離を超え、ゴール(STATE_END)を超えていなければ配列の添え字をインクリメント
    if (milage > m_stateLeft[nowState].Distance) {
      ++nowState;

      //走行状態切り替え時の距離をログに吐く

      EV3_LOG("State chenge nowState = %d\n Now milage  = %f\n", nowState,
              milage);  // Takeuchi
      RyujiEv3Engine::GetSpeaker()->setVolume(255);
      RyujiEv3Engine::GetSpeaker()->playTone(500, 10);
    }
    if (milage > STATE_END) {
      //ゴールしたならnowStateを-1にする
      nowState = -1;
    }
    return nowState;

  } else if (LINETRACE_NEXT_SCENE == SceneID::Lookup) {
    if (milage > m_stateRight[nowState].Distance) {
      ++nowState;
      //走行状態切り替え時の距離をログに吐く
      EV3_LOG("State chenge nowState = %d\n Now milage  = %f\n", nowState,
              milage);  // Takeuchi
      // RyujiEv3Engine::GetSpeaker()->setVolume(500);
      // RyujiEv3Engine::GetSpeaker()->playTone(900, 10);
    }
    if (milage > STATE_END) {
      //ゴールしたならnowStateを-1にする
      nowState = -1;
    }
    return nowState;

  } else {
    return (int)ERROR;
  }
}

void MapStateControl::drivePositionReset() { nowState = 0; }

int MapStateControl::errorCorrection() { return 0; }