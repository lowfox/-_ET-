#include "LineTraceScene.h"
#include <Config.h>

//�e�X�g�R�[�h*****************************************
#define CASE_MAX 9  //�e�X�g�P�[�X�̍ő吔
#include "LineTrace.h"
#include <Logger.h>
//�e�X�g�P�[�X�i�[�\���̒�`
struct Test {
  MapState state;  //�����p����
                    int trueResult;  //�����ɑ΂�����Ғl
};

//�e�X�g�R�[�h******************************************

LineTraceScene::LineTraceScene(ISceneChanger* sceneChanger) :IScene(sceneChanger)
{
}

bool LineTraceScene::init()
{
	return true;
}

bool LineTraceScene::run()
{
	// LineTraceCode

  //�e�X�g�R�[�h��������********************************************
  //�e�X�g�p�����Ƃ��̊��Ғl�ꗗ
        
std::array<Test, CASE_MAX> testCase = {{{(MapState)-1, -1},
                                        {Straight, 0},
                                        {SmallRightTurn, 0},
                                        {SmallLeftTurn, 0},
                                        {LargeRightTurn, 0},
                                        {LargeLeftTurn, 0},
                                        {Goal, 0},
                                        {StateEnd, -1},
                                        {(MapState)7, -1}}};

  // LineTrace�N���X����
  LineTrace lineTrace;
  int result = 0;

  for (int cnt = 0; cnt < CASE_MAX; cnt++) {
    result = lineTrace.lineTraceDrive(testCase[cnt].state);
    //���ۂ̖߂�l�����҂����߂�l�ƕs��v�������ꍇ
    if (result != testCase[cnt].trueResult) {
      EV3_LOG_ERROR("Cnt = %d is error\n",cnt);
    }
  }
  EV3_LOG("End\n");
  //�e�X�g�R�[�h�����܂�*************************************************

	return change(LINETRACE_NEXT_SCENE);
}