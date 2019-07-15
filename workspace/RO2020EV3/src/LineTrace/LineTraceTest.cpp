// LineTraceTest.cpp

#define CASE_MAX 9  //テストケースの最大数

// include
#include "LineTrace.h"

//テストケース格納構造体定義
struct Test {
  MapState state:   //試験用引数
  int trueResult;   //引数に対する期待値
};

int main(void) {
  //テスト用引数とその期待値一覧
  std::array<Test, CASE_MAX> testCase =
  {
    {-1, -1},
    {Straight, 0},
    {SmallRight, 0},
    {SmallLeft, 0},
    {LargeRight, 0},
    {LargeLeft, 0},
    {Goal, 0},
    {StateEnd,-1},
    {7,-1}
  }

  // LineTraceクラス生成
  LineTrace lineTrace;

  for (int result = 0,int cnt = 0, cnt < CASE_MAX, cnt++) {
    result = lineTrace.lineTraceDrive(testCase[cnt].state);
    //実際の戻り値が期待した戻り値と不一致だった場合
    if (result != testCase[cnt].trueResult) {
      printf("cnt %d is Error\n", cnt);
    }
  }
  return 0;
}