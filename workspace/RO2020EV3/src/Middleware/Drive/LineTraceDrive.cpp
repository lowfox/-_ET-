#include "LineTraceDrive.h"
#include "../DriveEngine/DriveEngine.h"
#include "../Steering/SteeringManager.h"
#include "DriveManager.h"
#include "Detect.h"

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

	// PID§Œä
	// RGB‚ÌF‚Ì•½‹Ï‚ğæ“¾
	float rgbAverage = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);


	if (m_lineMode == BlueLineMode::Blue) {
	  // ‚µ‚«‚¢’l‚ğŠi”[‚·‚é
	  if (Detect::GetColor() == ReadColor::BLUE) {
          // ƒ‰ƒCƒ“‚ªÂ‚Ìê‡‚µ‚«‚¢’l‚ÉÂ‚Æ”’‚Ì‚µ‚«‚¢’l‚ğŠi”[‚·‚é
          m_threshold = static_cast<float>(m_blueGray + m_traceColor.white * 0.7) / 2.0f;
          m_limitVal = static_cast<float>(m_blueGray - m_traceColor.white);
      } else if (Detect::GetColor() == ReadColor::BLACK) {
          // ƒ‰ƒCƒ“‚ª•‚Ìê‡‚µ‚«‚¢’l‚É•‚Æ”’‚Ì‚µ‚«‚¢’l‚ğŠi”[‚·‚é
          m_threshold = m_gray;
          m_limitVal = static_cast<float>(m_traceColor.black - m_traceColor.white);
      }
    } else if (m_lineMode == BlueLineMode::Nomal) {
		m_threshold = m_gray;
        m_limitVal = static_cast<float>(m_traceColor.black - m_traceColor.white);
    }
	

	m_integral += (rgbAverage + m_rgbAverageTemp / 2.0 * m_deltaTime);

	loc_mtx(PID_MTX);

	// P§Œä
	const float p_control = m_pid.kp * (rgbAverage - m_threshold) * (100.0f / m_limitVal);
	// I§Œä
	const float i_control = m_pid.ki * m_integral * (100.0f / m_limitVal);
	// D§Œä
	const float d_control = m_pid.kd * (rgbAverage - m_rgbAverageTemp) * (100.0f / m_limitVal);

	unl_mtx(PID_MTX);

	// §Œä’l‚ğŠi”[
	m_turn = p_control + i_control + d_control;
	
	// ¡‰ñ‚ÌRGB‚ğæ“¾‚µ‚Ä‚¨‚­
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
	m_gray = ((m_traceColor.black + m_traceColor.white) / 2.0f) * 0.7f;
    m_blueGray = ((m_traceColor.blue.r + m_traceColor.blue.g + m_traceColor.blue.b) / 3.0f) * 0.7f;

	m_threshold = m_gray;
	m_limitVal = static_cast<float>(m_traceColor.black - m_traceColor.white);
}

TraceColor LineTraceDrive::getTraceColor()
{
	return m_traceColor;
}

void LineTraceDrive::setLineMode(BlueLineMode lineMode) {
  m_lineMode = lineMode;
}

BlueLineMode LineTraceDrive::getLineMode() { 
	return m_lineMode;
}
