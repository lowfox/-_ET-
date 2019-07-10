// LineTrace.cpp

// includeファイル
#include "LineTrace.h"
#include <Drive.h>

LineTrace::LineTrace()
{
}

LineTrace::~LineTrace()
{
}

int LineTrace::lineTraceDrive(MapState runState)
{
  // runStateによって指定されたPID値をセット
  Drive::LineTrace::SetPID(m_PID[runState]);
  return 0;
}