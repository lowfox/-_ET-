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
  int lineTraceDrive(
      MapState runState);

 private:
  //各種PID格納配列(順番はMapState(enum)に準拠)
  
  const std::array<PID, 5> m_PID = {{
      {1.0f, 0.0f, 1.0f},  //直線走行用PID値//(仮)
      {1.0f, 0.0f, 1.0f},  //右小回り用PID値//(仮)
      {1.0f, 0.0f, 1.0f},  //左小回り用PID値//(仮)
      {1.0f, 0.0f, 1.0f},  //右大回り用PID値//(仮)
      {1.0f, 0.0f, 1.0f}   //左大回り用PID値//(仮)
  }};
 };