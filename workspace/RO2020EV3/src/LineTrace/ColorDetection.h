// ColorDetection.h
#pragma once
// includeファイル
#include <RyujiEv3.h>

//クラス定義
//クラス名  :ColorDetection
//機能名    :色検知
//機能概要  :黒又は青色を検知する

class ColorDetection {
 public:
  ColorDetection();      //コンストラクタ
  ~ColorDetection();     //デストラクタ
  bool getBlueColor();   //青色検知関数
  bool getBlackColor();  //黒色検知関数
};