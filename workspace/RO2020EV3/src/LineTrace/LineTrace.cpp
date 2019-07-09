// LineTrace.cpp

// include�t�@�C��
#include <Drive.h>
#include "LineTrace.h"

LineTrace::LineTrace()
{
}

LineTrace::~LineTrace()
{
}

int LineTrace::lineTraceDrive(MapState runState)
{
  // �߂�l�́APID�̃Z�b�g�ɐ����������ǂ����BGetPID�֐��Ō��݃Z�b�g����Ă�PID������̂ŁA�Z�b�g��ɂ���ĂׂΔ��f����Ă邩�킩��B

  //PID�l������
  //����
  m_straightPID.kp    = hoge;
  m_straightPID.ki    = hoge;
  m_straightPID.kd    = hoge;
  //�E�����
  m_smallRightTurn.kp = hoge;
  m_smallRightTurn.ki = hoge;
  m_smallRightTurn.kd = hoge;
  //�E����
  m_largeRightTurn.kp = hoge;
  m_largeRightTurn.ki = hoge;
  m_largeRightTurn.kd = hoge;
  //�������
  m_smallLeftTurn.kp  = hoge;
  m_smallLeftTurn.ki  = hoge;
  m_smallLeftTurn.kd  = hoge;
  //������
  m_largeLeftTurn.kp  = hoge;
  m_largeLeftTurn.ki  = hoge;
  m_largeLeftTurn.kd  = hoge;


  //runState�ɂ���ăZ�b�g����PID�l��ύX����
  switch (runState) {
    case Straight:
      Drive::LineTrace::SetPID(m_straightPID);
      break;

    case SmallRightTurn:
      Drive::LineTrace::SetPID(m_smallRightTurn);
      break;

    case SmallLeftTurn:
      Drive::LineTrace::SetPID(m_smallLeftTurn);
      break;

    case LargeRightTurn:
      Drive::LineTrace::SetPID(m_largeRightTurn);
      break;

    case LargeLeftTurn:
      Drive::LineTrace::SetPID(m_largeLeftTurn);
      break;

    //���s��Ԉꗗ�ɓ��Ă͂܂�Ȃ���΃G���[��-1��Ԃ�
    default:
      return -1;
      break;
  }

  //����ɒl���Z�b�g���ꂽ���m�F
  PID check;
  //���݃Z�b�g����Ă���PID�l���擾
  check = Drive::LineTrace::GetPID();
  //�{���Z�b�g����Ă���͂��̒l�ƈ�v�����琳��I��
  switch (runState) {
    case Straight:
      if (check.kp == m_straightPID.kp && check.ki == m_straightPID.ki &&
          check.kd == m_straightPID.kd) {
        return 0;
      } else {
        return -1;
      }
      break;

    case SmallRightTurn:
      if (check.kp == m_smallRightTurn.kp && check.ki == m_smallRightTurn.ki &&
          check.kd == m_smallRightTurn.kd) {
        return 0;
      } else {
        return -1;
      }
      break;

    case SmallLeftTurn:
      if (check.kp == m_smallLeftTurn.kp && check.ki == m_smallLeftTurn.ki &&
          check.kd == m_smallLeftTurn.kd) {
        return 0;
      } else {
        return -1;
      }
      break;

    case LargeRightTurn:
      if (check.kp == m_largeRightTurn.kp && check.ki == m_largeRightTurn.ki &&
          check.kd == m_largeRightTurn.kd) {
        return 0;
      } else {
        return -1;
      }
      break;

    case LargeLeftTurn:
      if (check.kp == m_largeLeftTurn.kp && check.ki == m_largeLeftTurn.ki &&
          check.kd == m_largeLeftTurn.kd) {
        return 0;
      } else {
        return -1;
      }
      break;

    default:
      return -1;
      break;
  }

}