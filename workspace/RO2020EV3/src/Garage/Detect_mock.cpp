#include <Detect.h>
#include "../Drive/DriveManager.h"
#include "../DriveEngine/DriveEngine.h"
#include <RyujiEv3.h>



namespace Detect
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
		}
		
	}
}