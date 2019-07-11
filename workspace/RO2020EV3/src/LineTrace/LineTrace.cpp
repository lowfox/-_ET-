// LineTrace.cpp

// includeファイル
#include "LineTrace.h"

LineTrace::LineTrace() {}

LineTrace::~LineTrace() {}

int LineTrace::lineTraceDrive(MapState runState) {
  //エラーチェック(runStateに1以上StateEnd未満の値がセットされていない場合)
  if (0 > runState || StateEnd <= runState) {
    return -1;
  }

  // runStateによって指定されたPID値をセット
  Drive::LineTrace::SetPID(m_PID[runState]);
  return 0;
}