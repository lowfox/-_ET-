// LineTrace.cpp

// includeファイル
#include "LineTrace.h"
#include <Logger.h>

// 定数定義
#define ERROR -1
#define SUCCESSFUL 0

LineTrace::LineTrace() {}

LineTrace::~LineTrace() {}

int LineTrace::lineTraceDrive(int runState) {
  //エラーチェック
  if (0 > runState || StateEnd <= runState) {
    return ERROR;
  }

  // runStateによって指定されたPID値をセット
  Drive::LineTrace::SetPID(m_PID[runState]);
  Drive::Drive(m_Speed[runState]);
  return SUCCESSFUL;
}