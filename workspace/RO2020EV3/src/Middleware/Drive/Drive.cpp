#include <Drive.h>
#include "DriveManager.h"
#include "../DriveEngine/DriveEngine.h"
#include "LineTraceDrive.h"
#include "../app.h"

namespace Drive
{
	bool Drive(int32 speed, int32 turn)
	{
		return DriveEngine::GetDrive()->drive(speed, turn);
	}

	bool Stop()
	{
		return DriveEngine::GetDrive()->stop();
	}

	bool Rotate()
	{
		return DriveEngine::GetDrive()->rotate();
	}

	bool SetDriveMode(DriveMode mode)
	{
		return DriveEngine::GetDrive()->setDriveMode(mode);
	}

	DriveMode GetDriveMode()
	{
		return DriveEngine::GetDrive()->getDriveMode();
	}


	namespace ColorCalibrate
	{
		RGB RGBAverage1Sec()
		{
			RGB rgb = {0,0,0};

			for (int32 i = 0; i < 100; i++)
			{
				const RGB rgbTemp = RyujiEv3Engine::GetColorSensor()->getRGB();
				rgb.r += rgbTemp.r;
				rgb.g += rgbTemp.g;
				rgb.b += rgbTemp.b;
				tslp_tsk(10);
			}

			rgb.r = rgb.r / 100;
			rgb.g = rgb.g / 100;
			rgb.b = rgb.b / 100;

			return rgb;
		}

		bool AddTraceColor(int32 count, const TraceColor& traceColor)
		{
			DriveEngine::GetTraceColorMap()->emplace(count, traceColor);
			return true;
		}

		TraceColor& GetTraceColor(int32 count)
		{
			return (*DriveEngine::GetTraceColorMap())[count];
		}
	}

	namespace LineTrace
	{
		void SetPID(const PID& pid)
		{
			DriveEngine::GetDrive()->getLineTraceDrive()->setPID(pid);
		}

		PID GetPID()
		{
			return DriveEngine::GetDrive()->getLineTraceDrive()->getPID();
		}

		void SetTraceColor(const TraceColor& color)
		{
			DriveEngine::GetDrive()->getLineTraceDrive()->setTraceColor(color);
		}

		TraceColor GetTraceColor()
		{
			return DriveEngine::GetDrive()->getLineTraceDrive()->getTraceColor();
		}

		void SetSide(Side side)
		{
			DriveEngine::GetDrive()->getLineTraceDrive()->setSide(side);
		}

		Side GetSide()
		{
			return DriveEngine::GetDrive()->getLineTraceDrive()->getSize();
		}

		void SetLineMode(BlueLineMode lineMode) 
		{
            DriveEngine::GetDrive()->getLineTraceDrive()->setLineMode(lineMode);
		}

		BlueLineMode GetLineMode() {
            return DriveEngine::GetDrive()->getLineTraceDrive()->getLineMode();
        }
	}
}
