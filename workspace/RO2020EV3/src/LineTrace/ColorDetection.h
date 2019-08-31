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
  //関数名   :getBlueColor
  //機能名   :青色検知
  //機能概要 :カラーセンサーで青色を検知したか否かを戻り値で返す
  //引数     :無し
  //戻り値   :bool       :青色検知 = true
  bool getBlueColor();   //青色検知関数
  //関数名   :getBlackColor
  //機能名   :黒色検知
  //機能概要 :カラーセンサーで黒色を検知したか否かを戻り値で返す
  //引数     :無し
  //戻り値   :bool       :黒色検知 = true
  bool getBlackColor();  //黒色検知関数
};