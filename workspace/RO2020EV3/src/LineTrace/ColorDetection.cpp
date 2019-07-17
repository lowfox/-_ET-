// ColorDetection.cpp

// includeファイル
#include "ColorDetection.h"

ColorDetection::ColorDetection() {}

ColorDetection::~ColorDetection() {}

bool ColorDetection::getBlueColor() {
  ReadColor checkBlue;  //取得した色保存

  //現在の色情報を取得
  checkBlue = RyujiEv3Engine::GetColorSensor()->getColor();

  //取得した色が青ならtrueを、そうでないならfalseをリターンする。
  return checkBlue == ReadColor::BLUE ? true : false;
}

bool ColorDetection::getBlackColor() {
  ReadColor checkBlack;  //取得した色保存

  //現在の色情報を取得
  checkBlack = RyujiEv3Engine::GetColorSensor()->getColor();

  //取得した色が黒ならtrueを、そうでないならfalseをリターンする。
  return checkBlack == ReadColor::BLACK ? true : false;
}
