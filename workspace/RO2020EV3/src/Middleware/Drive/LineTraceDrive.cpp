#include "LineTraceDrive.h"
#include "../DriveEngine/DriveEngine.h"
#include "../Steering/SteeringManager.h"
#include "DriveManager.h"
#include "Detect.h"

bool LineTraceDrive::init() {
  m_rgbAverageTemp = 0;
  m_integral       = 0;

  return true;
}

bool LineTraceDrive::drive(int32 speed, int32 turn) {
  m_speed = speed;

  return true;
}

bool LineTraceDrive::stop() {
  m_speed = 0;

  return DriveEngine::GetSteering()->stop();
}

bool LineTraceDrive::rotate() {
  if (!DriveEngine::GetDrive()->setDriveMode(DriveMode::Nomal)) {
    return false;
  }

  if (!DriveEngine::GetSteering()->drive(0, -10)) {
    return false;
  }

  tslp_tsk(1000);

  while (true) {
    const RGB rgb          = RyujiEv3Engine::GetColorSensor()->getRGB();
    const float rgbAverage = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);

    void LineTraceDrive::update() {
      const RGB rgb = RyujiEv3Engine::GetColorSensor()->getRGB();

      // PID制御
      // RGBの色の平均を取得
      float rgbAverage = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);

      // しきい値を格納する
      if (Detect::GetColor() == ReadColor::BLUE) {
        // ラインが青の場合しきい値に青と白のしきい値を格納する
        m_threshold =
            static_cast<float>(m_blueGray + m_traceColor.white * 0.7) / 2.0f;
        m_limitVal = static_cast<float>(m_blueGray - m_traceColor.white);
      } else if (Detect::GetColor() == ReadColor::BLACK) {
        // ラインが黒の場合しきい値に黒と白のしきい値を格納する
        m_threshold = m_gray;
        m_limitVal =
            static_cast<float>(m_traceColor.black - m_traceColor.white);
      }
    }

    m_integral += (rgbAverage + m_rgbAverageTemp / 2.0 * m_deltaTime);

    return true;
  }

  void LineTraceDrive::update() {
    const RGB rgb = RyujiEv3Engine::GetColorSensor()->getRGB();

    // PID制御
    // RGBの色の平均を取得
    float rgbAverage;

    // ラインが青の場合しきい値に青と白のしきい値を格納する
    if (Detect::GetColor() == ReadColor::BLUE) {
      m_threshold = static_cast<float>(m_blueGray + m_traceColor.white) / 2.0f;
      rgbAverage  = static_cast<float>(rgb.b);
      m_limitVal  = static_cast<float>(m_blueGray - m_traceColor.white);
    } else if (Detect::GetColor() == ReadColor::BLACK) {
      m_threshold = m_gray;
      rgbAverage  = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);
      m_limitVal  = static_cast<float>(m_traceColor.black - m_traceColor.white);
    }

    m_integral += (rgbAverage + m_rgbAverageTemp / 2.0 * m_deltaTime);

    loc_mtx(PID_MTX);

    // P制御
    const float p_control =
        m_pid.kp * (rgbAverage - m_threshold) * (100.0f / m_limitVal);
    // I制御
    const float i_control = m_pid.ki * m_integral * (100.0f / m_limitVal);
    // D制御
    const float d_control =
        m_pid.kd * (rgbAverage - m_rgbAverageTemp) * (100.0f / m_limitVal);

    unl_mtx(PID_MTX);

    // 制御値を格納
    m_turn = p_control + i_control + d_control;

    // 今回のRGBを取得しておく
    m_rgbAverageTemp = rgbAverage;

    if (m_side == Side::Left) {
      m_turn *= -1;
    }

    DriveEngine::GetSteering()->drive(m_speed, m_turn);
  }

  void LineTraceDrive::setPID(const PID& pid) {
    loc_mtx(PID_MTX);
    m_pid = pid;
    unl_mtx(PID_MTX);
  }

  void LineTraceDrive::setTraceColor(const TraceColor& traceColor) {
    m_traceColor = traceColor;
    m_gray       = ((m_traceColor.black + m_traceColor.white) / 2.0f) * 0.7f;
    m_blueGray =
        ((m_traceColor.blue.r + m_traceColor.blue.g + m_traceColor.blue.b) /
         3.0f) *
        0.7f;

    m_threshold = m_gray;
    m_limitVal  = static_cast<float>(m_traceColor.black - m_traceColor.white);
  }

  TraceColor LineTraceDrive::getTraceColor() { return m_traceColor; }