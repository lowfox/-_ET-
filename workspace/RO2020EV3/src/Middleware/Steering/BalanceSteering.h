#pragma once
#include "ISteering.h"
#include "balancer.h"

class BalanceSterring : public ISteering {
 private:
  IMotor* leftMotor = nullptr;

  IMotor* rightMotor = nullptr;

  int32 m_speed = 0;

  int32 m_turn = 0;

  int8 leftPWM = 0;

  int8 rightPWM = 0;

 public:
  bool init() override;

  bool drive(int32 speed, int32 turn) override;

  bool stop() override;

  bool update() override;
};