// DistanceMeasure.h
#pragma once
// includeファイル
#include <Steering.h>

//クラス定義
//クラス名  :DistanceMeasure
//機能名    :距離計測
//機能概要  :スタートからの累計距離を計測する

class DistanceMeasure {
 public:
  DistanceMeasure();              //コンストラクタ
  ~DistanceMeasure();             //デストラクタ
  static float getDistance();     //累計距離取得関数

 private:
  static float m_mileage;         //累計距離保存変数
};