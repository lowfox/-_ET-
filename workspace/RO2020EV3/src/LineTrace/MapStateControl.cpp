// MapStateControl.cpp
// include�t�@�C��
#include "MapStateControl.h"
#include <Logger.h>

// �萔��`
#define ERROR -1

MapStateControl::MapStateControl()
{
}

MapStateControl::~MapStateControl()
{
}

MapState MapStateControl::drivePosition() {
  static int nowState = 0;      //���݂̑��s���
  float milage = 0.0f;          //�݌v����



  //�݌v�����擾
  milage = DistanceMeasure::getDistance();

  //�R�[�X��L��R�ɂ���ď�����؂�ւ�(�ݒ肳��Ă��Ȃ���΃G���[�I��)
  if (COURSE_MODE == LEFT_COURSE) {
    //���݂̋��������݂̋K�苗���𒴂��A�S�[��(STATE_END)�𒴂��Ă��Ȃ���Δz��̓Y�������C���N�������g
    if (milage > m_stateLeft[nowState].Distance && milage <= STATE_END) {
      ++nowState;

      //走行状態切り替え時の距離をログに吐く
      EV3_LOG("State chenge nowState = %d\n Now milage  = %f\n", nowState, milage);//Takeuchi
    
    
    }
    return m_stateLeft[nowState].State;

  } else if (COURSE_MODE == RIGHT_COURSE) {
    
    if (milage > m_stateRight[nowState].Distance && milage <= STATE_END) {
      ++nowState;
    }
    return m_stateRight[nowState].State;

  } else {
    return (MapState)ERROR;
  }
}

int MapStateControl::errorCorrection() { return 0; }