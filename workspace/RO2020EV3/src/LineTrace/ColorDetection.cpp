// ColorDetection.cpp

// include�t�@�C��
#include "ColorDetection.h"
#include <Detect.h>

ColorDetection::ColorDetection() {}

ColorDetection::~ColorDetection() {}

bool ColorDetection::getBlueColor() {
  //�擾�����F���Ȃ�true���A�����łȂ��Ȃ�false�����^�[������B
  return Detect::GetColor() == ReadColor::BLUE ? true : false;
}

bool ColorDetection::getBlackColor() {
  //�擾�����F�����Ȃ�true���A�����łȂ��Ȃ�false�����^�[������B
  return Detect::GetColor() == ReadColor::BLACK ? true : false;
}
