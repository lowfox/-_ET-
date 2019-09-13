// MapStateControl.cpp
// include�t�@�C��
#include "MapStateControl.h"
#include <Logger.h>

// �萔��`
#define ERROR -1

MapStateControl::MapStateControl() {
}

MapStateControl::~MapStateControl() {
}

int MapStateControl::drivePosition() {
  float milage = 0.0f;  //�݌v����

  //�݌v�����擾
  milage = DistanceMeasure::getDistance();

  //�R�[�X��L��R�ɂ���ď�����؂�ւ�(�ݒ肳��Ă��Ȃ���΃G���[�I��)
  if (COURSE_MODE == LEFT_COURSE) {
    //���݂̋��������݂̋K�苗���𒴂��A�S�[��(STATE_END)�𒴂��Ă��Ȃ���Δz��̓Y�������C���N�������g
    if (milage > m_stateLeft[nowState].Distance && milage <= STATE_END) {
      ++nowState;

      //���s��Ԑ؂�ւ����̋��������O�ɓf��
      EV3_LOG("State chenge nowState = %d\n Now milage  = %f\n", nowState,
              milage);  // Takeuchi
      RyujiEv3Engine::GetSpeaker()->setVolume(500);
      RyujiEv3Engine::GetSpeaker()->playTone(500, 10);
    } else if (milage > STATE_END) {
      //�S�[�������Ȃ�nowState��-1�ɂ���
      nowState = -1;
    }
    return nowState;

  } else if (COURSE_MODE == RIGHT_COURSE) {
    if (milage > m_stateRight[nowState].Distance && milage <= STATE_END) {
      ++nowState;
      //���s��Ԑ؂�ւ����̋��������O�ɓf��
      EV3_LOG("State chenge nowState = %d\n Now milage  = %f\n", nowState,
              milage);  // Takeuchi
      RyujiEv3Engine::GetSpeaker()->setVolume(500);
      RyujiEv3Engine::GetSpeaker()->playTone(900, 10);
    } else if (milage > STATE_END) {
      //�S�[�������Ȃ�nowState��-1�ɂ���
      nowState = -1;
    }
    return nowState;

  } else {
    return (int)ERROR;
  }
}

void MapStateControl::drivePositionReset() {
  nowState = 0;
}

int MapStateControl::errorCorrection() { return 0; }