#pragma once
#include <RyujiEv3.h>
#include <map>
#include <Drive.h>

class SteeringManager;
class DriveManager;

class DriveEngine
{
public:

	using TraceColorMap = std::map<int32, TraceColor>;

private:

	static DriveEngine* pEngine;

	SteeringManager* m_steering;

	DriveManager* m_drive;

	TraceColorMap* m_traceColorMap;

public:

	DriveEngine();

	~DriveEngine();

	static bool isActive()
	{
		return pEngine;
	}

	static SteeringManager* GetSteering()
	{
		return pEngine->m_steering;
	}

	static DriveManager* GetDrive()
	{
		return pEngine->m_drive;
	}

	static TraceColorMap* GetTraceColorMap()
	{
		return pEngine->m_traceColorMap;
	}
};