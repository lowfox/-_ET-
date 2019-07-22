#include <Steering.h>
#include "../DriveEngine/DriveEngine.h"
#include "SteeringManager.h"
#include "..//Drive/DriveManager.h"
#include "../app.h"
#include "Steering_mock.h"

namespace Steering
{
	float GetDistance()
	{
		static int j = 0;
		j++;
		switch (j)
		{
		case 1:
			result = 0.0f;
			break;
		case 2:
			result = 0.1f;
			break;
		case 3:
			result = 0.2f;
			break;
		case 4:
			result = 0.3f;
			break;

		}
	}
}