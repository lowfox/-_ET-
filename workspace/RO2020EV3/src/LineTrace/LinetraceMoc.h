#pragma once
#include <steering.h>

//テスト用関数(DistanceMeasure以外のテスト用関数もここに書いていく。)
namespace SteeringMoc {
  float GetDistance();
}

//テスト用クラス
class DistanceMeasure {
public:
  DistanceMeasure();              //コンストラクタ
  ~DistanceMeasure();             //デストラクタ
  //関数名   :getDistance
  //機能名   :テスト
  //機能概要 :テスト項目(数値)をリターンする
  //引数     :無し
  //戻り値   :float               :累計走行距離を模した数値
  static float getDistance();     //テスト用累計距離取得関数

private:
  static float m_mileage;         //テスト用累計距離保存変数
};

#if defined LINETRACE_DEBUG
#define GET_DISTANCE() SteeringMoc::GetDistance()
//#define DISTANCE_MEASURE() DistanceMeasureMoc::getDistance()
#else
#define GET_DISTANCE() Steering::GetDistance()
//#define DISTANCE_MEASURE() DistanceMeasure::getDistance()

#endif