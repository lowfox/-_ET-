#include "../Middleware/Drive/DriveManager.h"
#include "../Middleware/DriveEngine/DriveEngine.h"
#include <RyujiEv3.h>
#include "Detect_mock.h"
//#include <Detect.h>



namespace Detect_mock
{
	ReadColor GetColor(float blueCorr, float rgbCorr)
	{
		static int j = 0;

		j++;

		switch (j)
		{
		case 1:
			return ReadColor::BLUE;
			break;
		case 2:
			return ReadColor::BLACK;
			break;
		default :
			return ReadColor::NONE;
			break;
		}
	}
}