#pragma once
#include "IDrive.h"
#include <Drive.h>

class LineTraceDrive : public IDrive {
 private:
  PID m_pid;

  TraceColor m_traceColor;

  float m_threshold;

  float m_limitVal;

  float m_gray;

  float m_blueGray;

  float m_rgbAverageTemp = 0;

  float m_deltaTime = 0.004f;

  float m_integral = 0;

  int32 m_speed = 0;

  int32 m_turn = 0;

  ReadColor m_color;

  Side m_side = Side::Right;

 public:
  bool init() override;

  bool drive(int32 speed, int32 turn) override;

  bool stop() override;

  bool rotate() override;

  void update() override;

  void setTraceColor(const TraceColor& traceColor);

  TraceColor getTraceColor();

  void setPID(const PID& pid);

  PID getPID();

  void setSide(Side side);

  Side getSize();
};