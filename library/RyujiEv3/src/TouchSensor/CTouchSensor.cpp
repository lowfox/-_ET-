#include "CTouchSensor.h"
#include "ev3api.h"

namespace RyujiEv3 {
bool CTouchSensor::init(SensorPort port) {
  auto result =
      ev3_sensor_config(static_cast<sensor_port_t>(port), TOUCH_SENSOR);

  if (result != E_OK) {
    return false;
  }
  this->port = port;

  return true;
}
bool CTouchSensor::click() { return m_click; }

bool CTouchSensor::clicked() { return m_clicked; }

bool CTouchSensor::pressing() { return m_pressing; }

bool CTouchSensor::update() {
  auto prev = m_pressing;

  m_pressing = ev3_touch_sensor_is_pressed(static_cast<sensor_port_t>(port));

  if (m_pressing) {
    m_click   = prev ? false : true;
    m_clicked = false;
  } else {
    m_clicked = prev ? true : false;
    m_click   = false;
  }

  return true;
}
}  // namespace RyujiEv3