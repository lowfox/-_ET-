// LineTrace.cpp

// includeファイル
#include "LineTrace.h"

LineTrace::LineTrace() {}

LineTrace::~LineTrace() {}

int LineTrace::lineTraceDrive(MapState runState) {
  //エラーチェック(runStateに0～5以外の値がセットされている場合)
  if (0 > runState > 5) {
    return -1;
  }

  // runStateによって指定されたPID値をセット
  Drive::LineTrace::SetPID(m_PID[runState]);
  return 0;
}