#pragma once
#include <RyujiEv3.h>
#include "MapStateDefinition.h"
//ライントレースコース走行

class Run
{
public:
	Run();      //コンストラクタ
	~Run();     //デストラクタ

	bool driveStart();

private:

	int m_runState;

	const int m_lowSpeed = 30;
};
