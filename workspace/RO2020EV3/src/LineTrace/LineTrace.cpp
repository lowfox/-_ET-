// LineTrace.cpp

// include�t�@�C��
#include "LineTrace.h"

LineTrace::LineTrace() {}

LineTrace::~LineTrace() {}

int LineTrace::lineTraceDrive(MapState runState) {
  //�G���[�`�F�b�N(runState��0�`5�ȊO�̒l���Z�b�g����Ă���ꍇ)
  if (0 > runState > 5) {
    return -1;
  }

  // runState�ɂ���Ďw�肳�ꂽPID�l���Z�b�g
  Drive::LineTrace::SetPID(m_PID[runState]);
  return 0;
}