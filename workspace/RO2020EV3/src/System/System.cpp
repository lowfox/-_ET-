#include <System.h>
#include "../Middleware/DriveEngine/DriveEngine.h"
#include <RyujiEv3.h>
#include <Logger.h>
#include "../Logger/CLogger.h"

namespace System
{
	static RyujiEv3Engine* engine       = nullptr;
	static DriveEngine* steeringManager = nullptr;

	bool Init(const PortData& port)
	{
		try
		{
			engine          = new RyujiEv3Engine(port);
			steeringManager = new DriveEngine;
			CLogger::Create();
		}
		catch (std::bad_alloc err)
		{
			return false;
		}

		if (!RyujiEv3Engine::isActive())
		{
			EV3_LOG_ERROR("API InitError");
			return false;
		}

		if (!DriveEngine::isActive())
		{
			EV3_LOG_ERROR("MW InitError");
			return false;
		}

		EV3_LOG_INFO("API,MW InitSuccess");

		return true;
	}

	void Exit()
	{
		EV3_LOG_INFO("API,MW End");

		if (steeringManager) { delete steeringManager; }

		CLogger::Destroy();

		if (engine) { delete engine; }
	}
}