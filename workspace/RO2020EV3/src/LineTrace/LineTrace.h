// LineTrace.h
#pragma once
// includeファイル
#include <Drive.h>
#include <array>
#include "MapStateDefinition.h"

//クラス定義
//クラス名  :LineTrace
//機能名    :MWのLineTraceにPID値をセット
//機能概要  :各状況(カーブ等)に最適化されたPID値をセットする

class LineTrace {
 public:
  LineTrace();   //コンストラクタ
  ~LineTrace();  //デストラクタ

  //関数名   :lineTraceDrive
  //機能名   :PIDセット
  //機能概要 :マップ状況に合わせて最適なPID値をセット
  //引数     :MapState runState  :現在の走行状態(enumで0～StateEndまでの範囲)
  //戻り値   :int                :正常終了 = 0 : 異常終了 = -1
  int lineTraceDrive(int runState);

 private:
  //各種PID格納配列(順番はMapState(enum)に準拠)

  const std::array<PID, 15> m_PID = {{
      {0.15f, 0.0f, 0.1f},   // 1
      {0.4f, 0.0f, 0.38f},   // 2
      {0.1f, 0.0f, 0.1f},   // 3
      {0.35f, 0.0f, 0.15f},   // 4
      {0.4f, 0.0f, 0.2f},   // 5
      {0.42f, 0.0f, 0.2f},  // 6
      {0.295f, 0.000005f, 0.2f},   // 7
      {0.1f, 0.0f, 0.2f},   // 8
      {0.24f, 0.00001f, 0.15f},  // 9
      {0.1f, 0.0f, 0.2f},   // 10
      {0.3f, 0.0f, 0.2f},   // 11
      {0.15f, 0.0f, 0.2f},   // 12
      {0.45f, 0.0f, 0.1f},   // 13
      {0.4f, 0.0f, 0.1f},   // 14
      {0.1f, 0.0f, 0.1f}    // 15
  }};

  // 速度系
  const std::array<int32, 15> m_Speed = {
      {80, 90, 85, 80, 75, 75, 85, 85, 85, 80, 80, 80, 80, 85, 70}};
};