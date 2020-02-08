///
/// @file ILCD.h
/// @brief LCDへのインターフェース
///
#pragma once
#include "../RyujiEv3Forward.h"
#include "ev3api.h"

namespace RyujiEv3 {
enum class LCD_Font {
  // 小さい
  SMALL,

  // 普通
  MEDIUM,
};

// LCD Color
enum class LCD_Color {
  // 白
  WHITE,

  // 黒
  BLACK
};

/// LCDの横のドット数
constexpr int32 LCD_WIDTH = 178;

/// LCDの縦のドット数
constexpr int32 LCD_HEIGHT = 128;

///
/// @brief LCD Interface
///
class ILCD {
 public:
  virtual ~ILCD() {}

  ///
  /// @fn bool setFont(LCD_Font font)
  /// @brief 使用するフォントを指定する
  /// @param font 使用するフォント
  /// @retval true 成功
  /// @retval false 失敗
  ///
  virtual bool setFont(LCD_Font font) = 0;

  ///
  /// @fn LCD_Font getFont()
  /// @brief 使用しているフォントを取得する
  /// @return LCD_Font 使用しているフォント
  ///
  virtual LCD_Font getFont() const = 0;

  ///
  /// @fn bool drawString(int32 x,int32 y,const char* format,...)
  /// @brief 文字列を描画する
  /// @param x 描画x座標
  /// @param y 描画y座標
  /// @param format フォーマット
  /// @retval true 成功
  /// @retval false 失敗
  ///
  virtual bool drawString(int32 x, int32 y, const char* format, ...) = 0;

  ///
  /// @fn bool drawBitmap(int32 x,int32 y,const char* filename)
  /// @brief Bitmapファイルを表示する
  /// @param x 描画x座標
  /// @param y 描画y座標
  /// @param filename Bitmapファイルのパス
  /// @retval true 成功
  /// @retval false 失敗
  ///
  virtual bool drawBitmap(int32 x, int32 y, const char* filename) = 0;

  ///
  /// @fn bool fillRect(int32 x, int32 y, int32 width, int32 height, LCD_Color
  /// color)
  /// @brief 指定領域を塗りつぶす
  /// @param x 左上
  /// @param y 左下
  /// @param width 右上
  /// @param height 右下
  /// @param color 塗りつぶす色
  /// @retval true 成功
  /// @retval false 失敗
  ///
  virtual bool fillRect(int32 x, int32 y, int32 width, int32 height,
                        LCD_Color color) = 0;
};
}  // namespace RyujiEv3