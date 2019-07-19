#pragma once
#include <RyujiEv3.h>
#include "MapStateDefinition.h"
//ライントレースコース走行

class Run
{
public:
	Run();      //コンストラクタ
	~Run();     //デストラクタ

	void driveStart();

private:
	bool m_blueDetection;

	bool m_blackDetection;

	MapState m_runState;

	const int m_lowSpeed = 30;
};
