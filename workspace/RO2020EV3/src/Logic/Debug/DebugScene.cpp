#include "DebugScene.h"
DebugScene::DebugScene() {}
DebugScene::~DebugScene() {}
bool DebugScene::init() { return true; }
bool DebugScene::run() {
  EV3_LOG_DEBUG("DebugLineTrace Start \n");
  RyujiEv3Engine::GetTailMotor()->setCounts(83, 30, true);

  Drive::SetDriveMode(DriveMode::LineTrace);

  TraceColor m_traceColor;
  m_traceColor = Drive::ColorCalibrate::GetTraceColor(83);

  Drive::LineTrace::SetTraceColor(m_traceColor);

  // Drive::LineTrace::SetLineMode(BlueLineMode::Blue);
  Drive::LineTrace::SetLineMode(BlueLineMode::Nomal);

  Drive::LineTrace::SetPID({0.24f, 0.0f, 0.2f});

  Drive::Drive(5);
  while (1)
    ;
  Drive::Stop();

  EV3_LOG_DEBUG("DebugLineTrace End\n");

  ReadColor color;
  while (1) {
    color = Detect::GetColorHSV();
    EV3_LOG_DEBUG("color=%d", static_cast<int>(color));
  }

  return true;
}