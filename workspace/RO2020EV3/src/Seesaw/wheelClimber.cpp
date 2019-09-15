#include "wheelClimber.h"

bool wheelClimber::run() {
  EV3_LOG("wheelClimber__start\n");

  angleDetector i_angleDetector;
  braker i_braker;
  straightRunner i_straightRunner;
  angularVelocityDetector i_angVelDetector;
  getUp i_getUp;
  tailPositioner i_tailPositioner;

  RyujiEv3Engine::GetLED()->setColor(LED_Color::GREEN);
  /*
  while(1){
      EV3_LOG("angle=%d",RyujiEv3Engine::GetGyroSensor()->getAngle());
  }
  */
  // i_distanceRunner.run(&m_climbBeforeRun);
  i_getUp.run(&m_climbTail_pre, m_runUpDistance);
  i_braker.run();
  dly_tsk(1000);
  RyujiEv3Engine::GetGyroSensor()->setOffset(0);

  // while(1){}
  // ���ւŏ���A���S���Y��
  // if(!i_angleDetector.setTargetValue(m_wheelClimbTargetValue)){return false;}
  // distanceRunner i_distanceRunner;
  // InfoTail climbTail={90,100,false};
  // if(!i_getUp.run(&m_climbTail,m_getUpDistance)){return false;}
  // i_tailPositioner.run(&m_climbTail_pre);

  if (!i_straightRunner.run(m_wheelClimbPwm)) {
    return false;
  }
  // if(!i_distanceRunner.run(&m_climbDisRun)){return false;}
  i_tailPositioner.run(&m_climbTail);
  // while(!i_angleDetector.detect()){}
  if (!RyujiEv3Engine::GetTailMotor()->stop(true)) {
    return false;
  }
  // if(!i_distanceRunner.run(&climbRun)){return false;}

  if (!i_braker.run()) {
    return false;
  }

  //�Зւ�����̃A���S���Y��
  /*
      EV3_LOG("wheelClimber__leftMoter\n");
      //if(!i_angVelDetector.setOffsetValue(m_leftClimbOffsetValue)){return
     false;} if(!i_angleDetector.setTargetValue(m_leftClimbTargetValue)){return
     false;}
      //if(!i_straightRunner.run(m_climbPwm)){return false;}
      if(!RyujiEv3Engine::GetLeftMotor()->setPWM(m_climbPwm)){return false;}
      if(!RyujiEv3Engine::GetRightMotor()->stop(true)){return false;}
      //while(!i_angVelDetector.detect()){}
      while(!i_angleDetector.detect()){}

      RyujiEv3Engine::GetSpeaker()->playTone(200,30);
      if(!RyujiEv3Engine::GetLeftMotor()->stop(true)){return false;}
      if(!RyujiEv3Engine::GetRightMotor()->stop(true)){return false;}
      dly_tsk(1000);
      EV3_LOG("wheelClimber__rightMoter\n");
      //if(!i_angVelDetector.setOffsetValue(-30)){return false;}

      //if(!i_angleDetector.setTargetValue(m_wheelClimbTargetValue)){return
     false;}
      //if(!i_straightRunner.run(m_wheelClimbPwm)){return false;}

      //if(!i_angVelDetector.setOffsetValue(m_wheelClimbOffsetValue)){return
     false;}
      //if(!RyujiEv3Engine::GetRightMotor()->setCounts(10,m_climbPwm,true)){return
     false;}
      //while(i_angVelDetector.detect()){}
      if(!RyujiEv3Engine::GetLeftMotor()->stop(true)){return false;}
      if(!RyujiEv3Engine::GetRightMotor()->setPWM(m_wheelClimbPwm)){return
     false;} if(!i_tailPositioner.run(&m_climbTail1)){return false;}

      //while(!i_angVelDetector.detect()){}
      //while(!i_angleDetector.detect()){}
      //if(!i_tailPositioner.run(&m_climbTail2)){return false;}
      RyujiEv3Engine::GetSpeaker()->playTone(200,30);
      if(!RyujiEv3Engine::GetLeftMotor()->stop(true)){return false;}
      if(!RyujiEv3Engine::GetRightMotor()->stop(true)){return false;}
      RyujiEv3Engine::GetLED()->setColor(LED_Color::OFF);
      while(1){}
  */
  EV3_LOG("wheelClimber__finish\n");
  return true;
}