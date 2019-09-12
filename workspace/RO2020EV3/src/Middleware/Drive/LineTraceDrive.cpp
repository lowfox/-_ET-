#include "LineTraceDrive.h"
#include "../DriveEngine/DriveEngine.h"
#include "../Steering/SteeringManager.h"
#include "DriveManager.h"

bool LineTraceDrive::init()
{
	m_rgbAverageTemp = 0;
	m_integral = 0;

	return true;
}

bool LineTraceDrive::drive(int32 speed, int32 turn)
{
	m_speed = speed;

	return true;
}

bool LineTraceDrive::stop()
{
	m_speed = 0;

	return DriveEngine::GetSteering()->stop();
}

bool LineTraceDrive::rotate()
{
	if (!DriveEngine::GetDrive()->setDriveMode(DriveMode::Nomal))
	{
		return false;
	}

	if (!DriveEngine::GetSteering()->drive(0, -10))
	{
		return false;
	}

	tslp_tsk(1000);

	while (true)
	{
		const RGB rgb = RyujiEv3Engine::GetColorSensor()->getRGB();
		const float rgbAverage = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);

		if (rgbAverage < static_cast<float>(m_traceColor.black * 1.5f)) 
		{
			break;
		}
	}

	if (!DriveEngine::GetDrive()->stop())
	{
		return false;
	}

	if (!DriveEngine::GetDrive()->setDriveMode(DriveMode::LineTrace))
	{
		return false;
	}

	return true;
}

void LineTraceDrive::update()
{
	const RGB rgb = RyujiEv3Engine::GetColorSensor()->getRGB();

	// PID????
	// RGB??F???????��
	const float rgbAverage = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);

	m_integral += (rgbAverage + m_rgbAverageTemp / 2.0 * m_deltaTime);

	loc_mtx(PID_MTX);

	// P????
	const float p_control = m_pid.kp * (rgbAverage - m_gray) * (100.0f / static_cast<float>(m_traceColor.black - m_traceColor.white));
	// I????
	const float i_control = m_pid.ki * m_integral * (100.0f / static_cast<float>(m_traceColor.black - m_traceColor.white));
	// D????
	const float d_control = m_pid.kd * (rgbAverage - m_rgbAverageTemp) * (100.0f / static_cast<float>(m_traceColor.black - m_traceColor.white));

	unl_mtx(PID_MTX);

	// ????l???i?[
	m_turn = p_control + i_control + d_control;
	
	// ?????RGB???��???????
	m_rgbAverageTemp = rgbAverage;

	if (m_side == Side::Left) {
		m_turn *= -1;
	}


	DriveEngine::GetSteering()->drive(m_speed, m_turn);
}

void LineTraceDrive::setPID(const PID& pid)
{
	loc_mtx(PID_MTX);
	m_pid = pid;
	unl_mtx(PID_MTX);
}

PID LineTraceDrive::getPID()
{
	return m_pid;
}

void LineTraceDrive::setSide(Side side)
{
	m_side = side;
}

Side LineTraceDrive::getSize()
{
	return m_side;
}

void LineTraceDrive::setTraceColor(const TraceColor& traceColor)
{
	m_traceColor = traceColor;
	m_gray = (m_traceColor.black + m_traceColor.white) / 2.0f;
}

TraceColor LineTraceDrive::getTraceColor()
{
	return m_traceColor;
}
