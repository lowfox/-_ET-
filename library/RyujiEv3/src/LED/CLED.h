#pragma once
#include <Interface/ILED.h>

namespace RyujiEv3 {
class CLED : public ILED {
 private:
  LED_Color m_color = LED_Color::OFF;

 public:
  CLED();

  ~CLED() override;

  bool setColor(LED_Color color) override;

  LED_Color getColor() override;
};
}  // namespace RyujiEv3