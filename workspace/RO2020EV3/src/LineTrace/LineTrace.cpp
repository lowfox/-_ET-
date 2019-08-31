// LineTrace.cpp

// includeファイル
#include "LineTrace.h"

// 定数定義
#define ERROR -1
#define SUCCESSFUL 0

LineTrace::LineTrace() {}

LineTrace::~LineTrace() {}

int LineTrace::lineTraceDrive(MapState runState) {
  //エラーチェック
  if (0 > runState || StateEnd <= runState) {
    return ERROR;
  }

  // runStateによって指定されたPID値をセット
  Drive::LineTrace::SetPID(m_PID[runState]);
  return SUCCESSFUL;
}