#include "LinetraceMoc.h"

//テスト用関数
namespace SteeringMoc {
float GetDistance() {
  static int cnt = 0;  //関数が呼び出された回数を保存しておく
  float result;
  switch (cnt) {
    case 0:
      result = 0.0f;
      ++cnt;
      break;
    case 1:
      result = 0.1f;
      ++cnt;
      break;
    case 2:
      result = 1.0f;
      ++cnt;
      break;
    case 3:
      result = 10.0f;
      ++cnt;
      break;
    case 4:
      result = 100.0f;
      ++cnt;
      break;
    case 5:
      result = 1073741823.5f;
      ++cnt;
      break;
    case 6:
      result = 2147483647.0f;
      ++cnt;
      break;
    default:
      result = 0.0f;
      break;
  }

  return result;
}
}  // namespace SteeringMoc

static float getDistance() {
  static int cnt = 0;
  ++cnt;
  return cnt;
}

//テスト用クラスメンバ変数初期化
float DistanceMeasure::m_mileage = 0.0f;

DistanceMeasure::DistanceMeasure() {}  //テスト用コンストラクタ

DistanceMeasure::~DistanceMeasure() {}  //テスト用デストラクタ

//テスト用クラスメンバ関数定義
float DistanceMeasure::getDistance() {
  static int cnt = 0;  //関数が呼び出された回数を保存
  switch (cnt) {
    case 0:
      m_mileage = 0.0f;
      ++cnt;
      return m_mileage;
      break;
    case 1:
      m_mileage = 9.9f;
      ++cnt;
      return m_mileage;
      break;
    case 2:
      m_mileage = 10.0f;
      ++cnt;
      return m_mileage;
      break;
    case 3:
      m_mileage = 10.1f;
      ++cnt;
      return m_mileage;
      break;
    case 4:
      m_mileage = 19.9f;
      ++cnt;
      return m_mileage;
      break;
    case 5:
      m_mileage = 20.0f;
      ++cnt;
      return m_mileage;
      break;
    case 6:
      m_mileage = 20.1f;
      ++cnt;
      return m_mileage;
      break;
    case 7:
      m_mileage = 29.9f;
      ++cnt;
      return m_mileage;
      break;
    case 8:
      m_mileage = 30.0f;
      ++cnt;
      return m_mileage;
      break;
    case 9:
      m_mileage = 30.1f;
      ++cnt;
      return m_mileage;
      break;
    case 10:
      m_mileage = 39.9f;
      ++cnt;
      return m_mileage;
      break;
    case 11:
      m_mileage = 40.0f;
      ++cnt;
      return m_mileage;
      break;
    case 12:
      m_mileage = 40.1f;
      ++cnt;
      return m_mileage;
      break;
    case 13:
      m_mileage = 49.9f;
      ++cnt;
      return m_mileage;
      break;
    case 14:
      m_mileage = 50.0f;
      ++cnt;
      return m_mileage;
      break;
    case 15:
      m_mileage = 50.1f;
      ++cnt;
      return m_mileage;
    case 16:
      m_mileage = 59.9f;
      ++cnt;
      return m_mileage;
      break;
    case 17:
      m_mileage = 60.0f;
      ++cnt;
      return m_mileage;
      break;
    case 18:
      m_mileage = 60.1f;
      ++cnt;
      return m_mileage;
      break;
    case 19:
      m_mileage = 69.9f;
      ++cnt;
      return m_mileage;
      break;
    case 20:
      m_mileage = 70.0f;
      ++cnt;
      return m_mileage;
      break;
    case 21:
      m_mileage = 70.1f;
      ++cnt;
      return m_mileage;
      break;
    case 22:
      m_mileage = 79.9f;
      ++cnt;
      return m_mileage;
      break;
    case 23:
      m_mileage = 80.0f;
      ++cnt;
      return m_mileage;
      break;
    case 24:
      m_mileage = 80.1f;
      ++cnt;
      return m_mileage;
      break;
    case 25:
      m_mileage = 89.9f;
      ++cnt;
      return m_mileage;
      break;
    case 26:
      m_mileage = 90.0f;
      ++cnt;
      return m_mileage;
      break;
    case 27:
      m_mileage = 90.1f;
      ++cnt;
      return m_mileage;
      break;
    case 28:
      m_mileage = 99.9f;
      ++cnt;
      return m_mileage;
      break;
    case 29:
      m_mileage = 100.0f;
      ++cnt;
      return m_mileage;
      break;
    case 30:
      m_mileage = 100.1f;
      ++cnt;
      return m_mileage;
    case 31:
      m_mileage = 109.9f;
      ++cnt;
      return m_mileage;
      break;
    case 32:
      m_mileage = 110.0f;
      ++cnt;
      return m_mileage;
      break;
    case 33:
      m_mileage = 110.1f;
      ++cnt;
      return m_mileage;
      break;
    case 34:
      m_mileage = 119.9f;
      ++cnt;
      return m_mileage;
      break;
    case 35:
      m_mileage = 120.0f;
      ++cnt;
      return m_mileage;
      break;
    case 36:
      m_mileage = 120.1f;
      ++cnt;
      return m_mileage;
      break;
    case 37:
      m_mileage = 129.9f;
      ++cnt;
      return m_mileage;
      break;
    case 38:
      m_mileage = 130.0f;
      ++cnt;
      return m_mileage;
      break;
    case 39:
      m_mileage = 130.1f;
      ++cnt;
      return m_mileage;
      break;
    case 40:
      m_mileage = 139.9f;
      ++cnt;
      return m_mileage;
      break;
    case 41:
      m_mileage = 140.0f;
      ++cnt;
      return m_mileage;
      break;
    case 42:
      m_mileage = 140.1f;
      ++cnt;
      return m_mileage;
      break;
    case 43:
      m_mileage = 149.9f;
      ++cnt;
      return m_mileage;
      break;
    case 44:
      m_mileage = 150.0f;
      ++cnt;
      return m_mileage;
      break;
    case 45:
      m_mileage = 150.1f;
      ++cnt;
      return m_mileage;
      break;
    case 46:
      m_mileage = 159.9f;
      ++cnt;
      return m_mileage;
      break;
    case 47:
      m_mileage = 160.0f;
      ++cnt;
      return m_mileage;
      break;
    case 48:
      m_mileage = 160.1f;
      ++cnt;
      return m_mileage;
      break;
    default:
      return 0;
      break;
  }
}
