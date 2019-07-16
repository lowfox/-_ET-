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
  int lineTraceDrive(
      MapState runState);  //�}�b�v�󋵂ɍ��킹�čœK��PID�l���Z�b�g

 private:
  //�e��PID�i�[�z��(���Ԃ�MapState(enum)�ɏ���)
  /*
  const std::array<PID, 5> m_PID = {
      {0.0f, 0.0f, 0.0f},  //�������s�pPID�l//(��)
      {0.0f, 0.0f, 0.0f},  //�E�����pPID�l//(��)
      {0.0f, 0.0f, 0.0f},  //�������pPID�l//(��)
      {0.0f, 0.0f, 0.0f},  //�E����pPID�l//(��)
      {0.0f, 0.0f, 0.0f}   //������pPID�l//(��)
  };
  */
  PID m_PID[5] = {
      {0.0f, 0.0f, 0.0f},  //�������s�pPID�l//(��)
      {0.0f, 0.0f, 0.0f},  //�E�����pPID�l//(��)
      {0.0f, 0.0f, 0.0f},  //�������pPID�l//(��)
      {0.0f, 0.0f, 0.0f},  //�E����pPID�l//(��)
      {0.0f, 0.0f, 0.0f}   //������pPID�l//(��)
  };
 };