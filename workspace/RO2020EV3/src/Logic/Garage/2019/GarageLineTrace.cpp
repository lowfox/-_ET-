#include "GarageLineTrace.h"
GarageLineTrace::GarageLineTrace() {
  EV3_LOG_DEBUG("GarageLineTrace Start \n");
  Drive::SetDriveMode(DriveMode::LineTrace);
}

void GarageLineTrace::configTraceColor(ReadColor color) {
  if (color == ReadColor::BLUE) {
    Drive::LineTrace::SetLineMode(BlueLineMode::Blue);
  } else {
    Drive::LineTrace::SetLineMode(BlueLineMode::Nomal);
  }
}

void GarageLineTrace::configTraceAngle(int32 angle) {
  m_traceColor = Drive::ColorCalibrate::GetTraceColor(angle);
  Drive::LineTrace::SetTraceColor(m_traceColor);
}

void GarageLineTrace::configPID(PID pid) { Drive::LineTrace::SetPID(pid); }

bool GarageLineTrace::Drive(int32 speed) {
  Drive::Drive(speed);
  return true;
}

bool GarageLineTrace::stop() {
  Drive::Stop();
  return true;
}

GarageLineTrace::~GarageLineTrace() { EV3_LOG_DEBUG("GarageLineTrace End\n"); }