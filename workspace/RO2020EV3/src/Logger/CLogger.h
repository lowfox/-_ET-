#pragma once
#include <RyujiEv3.h>
#include <Logger.h>

class CLogger
{
private:

	LogOutLevel m_outLevel = LogOutLevel::All;

	static CLogger* m_instance;

public:

	static void Create()
	{
		if (m_instance)
		{
			return;
		}

		m_instance = new CLogger;
	}

	static void Destroy()
	{
		if (m_instance)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}

	static CLogger* GetInstance()
	{
		return m_instance;
	}

	void writeLog(LogDesc desc, const char* log);

	void setOutLevel(LogOutLevel outLevel);

private:

	CLogger();

	~CLogger();

	bool checkLevel(LogDesc desc);
};