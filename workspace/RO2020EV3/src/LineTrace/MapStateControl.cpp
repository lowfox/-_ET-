// MapStateControl.cpp

// include�t�@�C��
#include "MapStateControl.h"

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
    //���݂̋��������݂̋K�苗���𒴂�����z��̓Y�������C���N�������g
    if (milage > m_stateLeft[nowState].Distance) {
      ++nowState;
    }
    return m_stateLeft[nowState].State;

  } else if (COURSE_MODE == RIGHT_COURSE) {
    
    if (milage > m_stateRight[nowState].Distance) {
      ++nowState;
    }
    return m_stateRight[nowState].State;

  } else {
    return (MapState)ERROR;
  }
}

int MapStateControl::errorCorrection() { return 0; }