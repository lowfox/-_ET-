#include "CSonarSensor.h"
#include <ev3api.h>

namespace RyujiEv3 {
bool CSonarSensor::init(SensorPort port) {
  auto result =
      ev3_sensor_config(static_cast<sensor_port_t>(port), ULTRASONIC_SENSOR);

  if (result != E_OK) {
    return false;
  }
  this->port = port;

  return true;
}

int16 CSonarSensor::getDistance() {
  return ev3_ultrasonic_sensor_get_distance(static_cast<sensor_port_t>(port));
}
}  // namespace RyujiEv3