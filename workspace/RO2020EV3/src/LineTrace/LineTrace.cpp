// LineTrace.cpp

// include�t�@�C��
#include "LineTrace.h"
#include <Logger.h>

// �萔��`
#define ERROR -1
#define SUCCESSFUL 0

LineTrace::LineTrace() {}

LineTrace::~LineTrace() {}

int LineTrace::lineTraceDrive(int runState) {
  //�G���[�`�F�b�N
  if (0 > runState || StateEnd <= runState) {
    return ERROR;
  }

  // runState�ɂ���Ďw�肳�ꂽPID�l���Z�b�g
  Drive::LineTrace::SetPID(m_PID[runState]);
  Drive::Drive(m_Speed[runState]);
  EV3_LOG("Set PID = %f %f %f\n", m_PID[runState].kp, m_PID[runState].ki,
          m_PID[runState].kd);
  EV3_LOG("Set Speed = %d\n", m_Speed[runState]);
  return SUCCESSFUL;
}