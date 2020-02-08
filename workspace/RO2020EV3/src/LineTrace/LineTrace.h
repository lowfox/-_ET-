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
      {0.31f, 0.0f, 0.2f},   // 2
      {0.2f, 0.0f, 0.13f},   // 3
      {0.3f, 0.0f, 0.15f},   // 4
      {0.27f, 0.0f, 0.14f},   // 5
      {0.32f, 0.0f, 0.23f},  // 6
      {0.24f, 0.000005f, 0.2f},   // 7
      {0.2f, 0.0f, 0.2f},   // 8
      {0.24f, 0.00001f, 0.15f},  // 9
      {0.2f, 0.0f, 0.2f},   // 10
      {0.25f, 0.0f, 0.2f},   // 11
      {0.18f, 0.0f, 0.2f},   // 12
      {0.28f, 0.0f, 0.16f},   // 13
      {0.4f, 0.0f, 0.2f},   // 14
      {0.13f, 0.0f, 0.1f}    // 15
  }};

  // 速度系
  const std::array<int32, 15> m_Speed = {
      {80, 78, 82, 78, 75, 73, 80, 85, 85, 87, 78, 78, 77, 80, 75}};
};