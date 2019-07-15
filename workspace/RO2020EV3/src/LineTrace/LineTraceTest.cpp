// LineTraceTest.cpp

#define CASE_MAX 9  //�e�X�g�P�[�X�̍ő吔

// include
#include "LineTrace.h"

//�e�X�g�P�[�X�i�[�\���̒�`
struct Test {
  MapState state:   //�����p����
  int trueResult;   //�����ɑ΂�����Ғl
};

int main(void) {
  //�e�X�g�p�����Ƃ��̊��Ғl�ꗗ
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

  // LineTrace�N���X����
  LineTrace lineTrace;

  for (int result = 0,int cnt = 0, cnt < CASE_MAX, cnt++) {
    result = lineTrace.lineTraceDrive(testCase[cnt].state);
    //���ۂ̖߂�l�����҂����߂�l�ƕs��v�������ꍇ
    if (result != testCase[cnt].trueResult) {
      printf("cnt %d is Error\n", cnt);
    }
  }
  return 0;
}