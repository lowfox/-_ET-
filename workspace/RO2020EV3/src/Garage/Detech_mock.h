#pragma once
#include <RyujiEv3.h>



namespace Detect
{
	ReadColor GetColor(float blueCorr = 0.7, float rgbCorr = 0.6);
}