#include "seesawRunner.h"

bool seesawRunner::run(direction dir) {
  braker i_braker;
  angularVelocityDetector i_angularVelocityDetector;
  lineTracer i_lineTracer;
  tailPositioner i_tailPositioner;
  straightRunner i_straightRunner;
  distanceRunner i_distanceRunner;
  getUp i_getUp;

  if (dir == direction::forward) {
    EV3_LOG("seesawRunner.run(forward)\n");
    if (!i_getUp.run(&m_forwadPreTail, forwardRunUpDistance)) {
      return false;
    }
    dly_tsk(500);
    // if(!i_distanceRunner.run(&m_preRunForward)){return false;}

    //ライン復帰処理
    //左と右どちらにいるか判定
    // RGBが小から大ならライン右、大から小になったらライン左
    /*
      if(!RyujiEv3Engine::GetLeftMotor()->stop(true)){return false;}
      if(!RyujiEv3Engine::GetRightMotor()->setPWM(m_lineReturnPwm)){return
      false;} dly_tsk(m_lineReturnTime);

      if(!RyujiEv3Engine::GetRightMotor()->stop(true)){return false;}
      if(!RyujiEv3Engine::GetLeftMotor()->stop(true)){return false;}
   */
    // dly_tsk(1000);
    /*
      rgb = Drive::ColorCalibrate::RGBAverage1Sec();
      if(luminance > (rgb.r + rgb.g + rgb.b)/3){
          //ライン左にいる
          Drive::LineTrace::SetSide(Side::Left);
      }else if(luminance < (rgb.r + rgb.g + rgb.b)/3){
          //ライン右にいる
          Drive::LineTrace::SetSide(Side::Right);
      }
  */

    if (!i_angularVelocityDetector.setOffsetValue(m_forwardBentOffset)) {
      return false;
    }
    if (!i_lineTracer.run(m_forwardPwm, m_lineTraceAngle)) {
      return false;
    }
    m_preDistance = Steering::GetDistance();
    while (Steering::GetDistance() - m_preDistance < 20.0f) {
    }
    RyujiEv3Engine::GetLED()->setColor(LED_Color::GREEN);
    while (i_angularVelocityDetector.detect() == false) {
    }
    if (!i_tailPositioner.run(&m_forwardBentTail)) {
      return false;
    }
    if (!Drive::SetDriveMode(DriveMode::Nomal)) {
      EV3_LOG("SetDriveMode...return false;");
    }
    // if(!i_distanceRunner.run(&m_postRunForward)){return false;}
    if (!i_braker.run()) {
      return false;
    }
  } else if (dir == direction::back) {
    EV3_LOG("seesawRunner.run(back)\n");
    // if(!i_getUp.run(&m_backPreTail,backRunUpDistance)){return false;}
    // if(!i_braker.run()){return false;}
    // dly_tsk(1000);
    if (!i_distanceRunner.run(&m_preRunBack)) {
      return false;
    }
    dly_tsk(1000);
    if (!i_angularVelocityDetector.setOffsetValue(m_backBentOffset)) {
      return false;
    }
    if (!i_straightRunner.run(m_backPwm)) {
      return false;
    }
    /*
     while(m_cnt<m_detectCnt){
        if(i_angularVelocityDetector.detect() == true){ m_cnt++; }
    }
    */
    while (i_angularVelocityDetector.detect() == false) {
    }
    // m_cnt = 0;

    if (!i_tailPositioner.run(&m_backBentTail)) {
      return false;
    }

  } else {
    EV3_LOG_ERROR("ARGS ERR seesawRunner.run(direction)\n");
    return false;
  }

  if (!i_braker.run()) {
    return false;
  }

  return true;
}
