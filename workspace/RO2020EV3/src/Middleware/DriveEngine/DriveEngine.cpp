#include "DriveEngine.h"
#include "../Steering/SteeringManager.h"
#include "../Drive/DriveManager.h"

DriveEngine* DriveEngine::pEngine = nullptr;

DriveEngine::DriveEngine()
{
	if (!RyujiEv3Engine::isActive())
	{
		return;
	}

	if (isActive())
	{
		return;
	}

	pEngine = this;
	m_steering = new SteeringManager;
	m_drive = new DriveManager;
	m_traceColorMap = new TraceColorMap;

	ev3_sta_cyc(DRIVE_CYC);
}

DriveEngine::~DriveEngine()
{
	ev3_stp_cyc(DRIVE_CYC);

	delete m_steering;
	delete m_drive;
	delete m_traceColorMap;

	pEngine = nullptr;
}
