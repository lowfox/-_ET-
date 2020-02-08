#include "CLED.h"
#include <ev3api.h>

namespace RyujiEv3 {
CLED::CLED() { setColor(LED_Color::OFF); }

CLED::~CLED() { setColor(LED_Color::OFF); }

bool CLED::setColor(LED_Color color) {
  ER result = ev3_led_set_color(static_cast<ledcolor_t>(color));

  if (result == E_PAR) {
    return false;
  }

  m_color = color;

  return true;
}

LED_Color CLED::getColor() { return m_color; }
}  // namespace RyujiEv3