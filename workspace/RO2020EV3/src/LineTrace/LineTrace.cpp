// LineTrace.cpp

// include�t�@�C��
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
  // runState�ɂ���Ďw�肳�ꂽPID�l���Z�b�g
  Drive::LineTrace::SetPID(m_PID[runState]);
  return 0;
}