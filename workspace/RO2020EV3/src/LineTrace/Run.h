#pragma once
#include <RyujiEv3.h>
#include "MapStateDefinition.h"
//���C���g���[�X�R�[�X���s

class Run
{
public:
	Run();      //�R���X�g���N�^
	~Run();     //�f�X�g���N�^

	bool driveStart();

private:

	MapState m_runState;

	const int m_lowSpeed = 30;
};
