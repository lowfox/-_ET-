#pragma once
#include "ISteering.h"

class NomalSterring :public ISteering
{
public:

	bool init()override;

	bool drive(int32 speed, int32 turn)override;

	bool stop()override;
};