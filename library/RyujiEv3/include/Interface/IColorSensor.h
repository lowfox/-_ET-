///
/// @file IColorSensor.h
/// @brief カラーセンサーへのインターフェース
///
#pragma once

#include "../RyujiEv3Forward.h"

namespace RyujiEv3 {
struct RGB {
  /// r
  uint16 r;

  /// g
  uint16 g;

  /// b
  uint16 b;
};

enum class ReadColor {
  /// 識別不能
  NONE,

  ///黒
  BLACK,

  ///青
  BLUE,

  /// 緑
  GREEN,

  /// 黄
  YELLOW,

  /// 赤
  RED,

  /// 白
  WHITE,

  ///ブラウン
  BROWN
};

///
/// @brief ColorSensor Interface
///
class IColorSensor {
 public:
  virtual ~IColorSensor() {}

  ///
  /// @fn uint8 getReflect()
  /// @brief 反射光の強さを取得する
  /// @return uint8 反射光(0 ～ 100)
  ///
  virtual uint8 getReflect() = 0;

  ///
  /// @fn RGB getRGB()
  /// @brief RGB値を取得する
  /// @return RGB 現在のRGB値
  ///
  virtual RGB getRGB() = 0;

  ///
  /// @fn ReadColor getColor()
  /// @brief 現在の色を取得する
  /// @return ReadColor 現在の色を
  ///
  virtual ReadColor getColor() = 0;
};
}  // namespace RyujiEv3
