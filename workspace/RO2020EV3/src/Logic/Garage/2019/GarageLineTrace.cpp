#include "GarageLineTrace.h"
GarageLineTrace::GarageLineTrace() {
  EV3_LOG_DEBUG("GarageLineTrace Start \n");
  Drive::SetDriveMode(DriveMode::LineTrace);
}

void GarageLineTrace::configTraceColor(TraceColor traceColor) {
  Drive::LineTrace::SetTraceColor(traceColor);
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