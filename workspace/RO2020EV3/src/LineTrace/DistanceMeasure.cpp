// DistanceMeasure.cpp

// includeファイル
#include "DistanceMeasure.h"

float DistanceMeasure::m_mileage = 0.0f;

DistanceMeasure::DistanceMeasure() {}

DistanceMeasure::~DistanceMeasure() {}

float DistanceMeasure::getDistance() {
  // MWから現在の累計距離を取得
  m_mileage = Steering::GetDistance();
  return m_mileage;
}