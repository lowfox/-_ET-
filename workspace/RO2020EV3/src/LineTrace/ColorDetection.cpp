// ColorDetection.cpp

// includeファイル
#include "ColorDetection.h"
#include <Detect.h>

ColorDetection::ColorDetection() {}

ColorDetection::~ColorDetection() {}

bool ColorDetection::getBlueColor() {
  //取得した色が青ならtrueを、そうでないならfalseをリターンする。
  return Detect::GetColor() == ReadColor::BLUE ? true : false;
}

bool ColorDetection::getBlackColor() {
  //取得した色が黒ならtrueを、そうでないならfalseをリターンする。
  return Detect::GetColor() == ReadColor::BLACK ? true : false;
}
