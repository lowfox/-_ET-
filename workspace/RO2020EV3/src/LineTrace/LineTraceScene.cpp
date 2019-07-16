#include "LineTraceScene.h"
#include <Config.h>

//テストコード*****************************************
#define CASE_MAX 9  //テストケースの最大数
#include "LineTrace.h"
#include <Logger.h>
//テストケース格納構造体定義
struct Test {
  MapState state;  //試験用引数
                    int trueResult;  //引数に対する期待値
};

//テストコード******************************************

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

  //テストコードここから********************************************
  //テスト用引数とその期待値一覧
        
std::array<Test, CASE_MAX> testCase = {{{(MapState)-1, -1},
                                        {Straight, 0},
                                        {SmallRightTurn, 0},
                                        {SmallLeftTurn, 0},
                                        {LargeRightTurn, 0},
                                        {LargeLeftTurn, 0},
                                        {Goal, 0},
                                        {StateEnd, -1},
                                        {(MapState)7, -1}}};

  // LineTraceクラス生成
  LineTrace lineTrace;
  int result = 0;

  for (int cnt = 0; cnt < CASE_MAX; cnt++) {
    result = lineTrace.lineTraceDrive(testCase[cnt].state);
    //実際の戻り値が期待した戻り値と不一致だった場合
    if (result != testCase[cnt].trueResult) {
      EV3_LOG_ERROR("Cnt = %d is error\n",cnt);
    }
  }
  EV3_LOG("End\n");
  //テストコードここまで*************************************************

	return change(LINETRACE_NEXT_SCENE);
}