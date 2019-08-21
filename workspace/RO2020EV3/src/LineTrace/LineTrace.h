// LineTrace.h
#pragma once
// include�t�@�C��
#include <Drive.h>
#include <array>
#include "MapStateDefinition.h"

//�N���X��`
//�N���X��  :LineTrace
//�@�\��    :MW��LineTrace��PID�l���Z�b�g
//�@�\�T�v  :�e��(�J�[�u��)�ɍœK�����ꂽPID�l���Z�b�g����

class LineTrace {
 public:
  LineTrace();   //�R���X�g���N�^
  ~LineTrace();  //�f�X�g���N�^

 //�֐���   :lineTraceDrive
 //�@�\��   :PID�Z�b�g
 //�@�\�T�v :�}�b�v�󋵂ɍ��킹�čœK��PID�l���Z�b�g
 //����     :MapState runState  :���݂̑��s���(enum��0�`StateEnd�܂ł͈̔�)
 //�߂�l   :int                :����I�� = 0 : �ُ�I�� = -1
  int lineTraceDrive(
      MapState runState);

 private:
  //�e��PID�i�[�z��(���Ԃ�MapState(enum)�ɏ���)
  
  const std::array<PID, 5> m_PID = {{
      {1.0f, 0.0f, 1.0f},  //�������s�pPID�l//(��)
      {1.0f, 0.0f, 1.0f},  //�E�����pPID�l//(��)
      {1.0f, 0.0f, 1.0f},  //�������pPID�l//(��)
      {1.0f, 0.0f, 1.0f},  //�E����pPID�l//(��)
      {1.0f, 0.0f, 1.0f}   //������pPID�l//(��)
  }};
 };