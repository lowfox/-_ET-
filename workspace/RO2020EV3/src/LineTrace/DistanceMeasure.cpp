// DistanceMeasure.cpp

// include�t�@�C��
#include "DistanceMeasure.h"

float DistanceMeasure::m_mileage = 0.0f;

DistanceMeasure::DistanceMeasure() {}

DistanceMeasure::~DistanceMeasure() {}

float DistanceMeasure::getDistance() {
  // MW���猻�݂̗݌v�������擾
  m_mileage = Steering::GetDistance();
  return m_mileage;
}