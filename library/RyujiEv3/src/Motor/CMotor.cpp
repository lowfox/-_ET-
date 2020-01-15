#include "Cmotor.h"
#include <ev3api.h>

namespace RyujiEv3 {
bool CMotor::init(MotorPort port) {
  auto result = ev3_motor_config(static_cast<motor_port_t>(port), LARGE_MOTOR);

  if (result != E_OK) {
    return false;
  }
  this->port = port;

  return true;
}
int32 CMotor::getCounts() {
  return ev3_motor_get_counts(static_cast<motor_port_t>(port));
}

int32 CMotor::getPWM() {
  return ev3_motor_get_power(static_cast<motor_port_t>(port));
}

bool CMotor::resetCounts() {
  return E_OK == ev3_motor_reset_counts(static_cast<motor_port_t>(port));
}

bool CMotor::setCounts(int32 degree, int32 speed, bool blocking) {
  auto result = ev3_motor_rotate(static_cast<motor_port_t>(port), degree, speed,
                                 blocking);

  if (result != E_OK) {
    return false;
  }

  return true;
}
bool CMotor::setPWM(int32 power) {
  auto result = ev3_motor_set_power(static_cast<motor_port_t>(port), power);

  if (result != E_OK) {
    return false;
  }

  return true;
}

bool CMotor::stop(bool brake) {
  auto result = ev3_motor_stop(static_cast<motor_port_t>(port), brake);

  if (result != E_OK) {
    return false;
  }

  return true;
}
}  // namespace RyujiEv3