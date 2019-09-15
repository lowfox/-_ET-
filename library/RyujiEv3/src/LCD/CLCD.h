#pragma once
#include <Interface/ILCD.h>
#include <ev3api.h>

namespace RyujiEv3 {
class CLCD : public ILCD {
 private:
  LCD_Font m_font = LCD_Font::MEDIUM;

  image_t m_image;

 public:
  CLCD();

  ~CLCD() override;

  bool setFont(LCD_Font font) override;

  LCD_Font getFont() const override;

  bool clear();

  bool drawString(int32 x, int32 y, const char* format, ...) override;

  bool drawBitmap(int32 x, int32 y, const char* filename) override;

  bool fillRect(int32 x, int32 y, int32 width, int32 height,
                LCD_Color color) override;
};
}  // namespace RyujiEv3