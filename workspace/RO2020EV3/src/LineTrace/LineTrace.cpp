// LineTrace.cpp

// include�t�@�C��
#include "LineTrace.h"

LineTrace::LineTrace() {}

LineTrace::~LineTrace() {}

int LineTrace::lineTraceDrive(MapState runState) {
  //�G���[�`�F�b�N(runState��1�ȏ�StateEnd�����̒l���Z�b�g����Ă��Ȃ��ꍇ)
  if (0 > runState || StateEnd <= runState) {
    return -1;
  }

  // runState�ɂ���Ďw�肳�ꂽPID�l���Z�b�g
  Drive::LineTrace::SetPID(m_PID[runState]);
  return 0;
}