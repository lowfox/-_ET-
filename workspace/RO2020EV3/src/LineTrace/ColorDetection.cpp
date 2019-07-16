// ColorDetection.cpp

// include�t�@�C��
#include "ColorDetection.h"

ColorDetection::ColorDetection() {}

ColorDetection::~ColorDetection() {}

bool ColorDetection::getBlueColor() {
  ReadColor checkBlue;  //�擾�����F�ۑ�

  //���݂̐F�����擾
  checkBlue = RyujiEv3Engine::GetColorSensor()->getColor();

  //�擾�����F���Ȃ�true���A�����łȂ��Ȃ�false�����^�[������B
  if (checkBlue == ReadColor::BLUE) {
    return true;
  } else {
    return false;
  }
}

bool ColorDetection::getBlackColor() {
  ReadColor checkBlack;  //�擾�����F�ۑ�

  //���݂̐F�����擾
  checkBlack = RyujiEv3Engine::GetColorSensor()->getColor();

  //�擾�����F�����Ȃ�true���A�����łȂ��Ȃ�false�����^�[������B
  if (checkBlack == ReadColor::BLACK) {
    return true;
  } else {
    return false;
  }
}
