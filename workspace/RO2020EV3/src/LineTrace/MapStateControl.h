// MapStateControl.h
#pragma once
// include�t�@�C��
#include <array>
#include "DistanceMeasure.h"
#include "MapStateDefinition.h"

//�萔��`
#define STATE_MAX 16       //���s��ԕψڂ̍ő吔
#define STATE_END 9372.1f  // GOAL�܂ł̋���//��
#define LEFT_COURSE 0
#define RIGHT_COURSE 1
#define COURSE_MODE RIGHT_COURSE  //���s�R�[�X�ݒ�

//�\���̒�`
//���s��ԊǗ��\����
struct DriveState {
  float Distance;  //���s��Ԑ؂�ւ��K�苗��
  MapState State;  //���s���
};

//�N���X��`
//�N���X��  :MapStateControl
//�@�\��    :�}�b�v��Ԑ؂�ւ�
//�@�\�T�v  :���s��������}�b�v���(���i�A�E�ܓ�)�𔻒f����B

// L�R�[�X�@���i�A�卶�܁A���i�A�卶�܁A���i�A�����܁A���E�܁A���i�A��E�܁A���i�A��E�܁A���i�A���E�܁A�����܁A���i�A�S�[��
// R�R�[�X�@���i�A��E�܁A���i�A��E�܁A���i�A���E�܁A�����܁A���i�A�卶�܁A���i�A�卶�܁A���i�A�����܁A���E�܁A���i�A�S�[��

class MapStateControl {
 public:
  MapStateControl();   //�R���X�g���N�^
  ~MapStateControl();  //�f�X�g���N�^
  //�֐���   :drivePosition
  //�@�\��   :���s�ʒu���f
  //�@�\�T�v :���s�������瑖�s���(�����A�E�J�[�u��)�𔻒f����
  //����     :����
  //�߂�l   :int        :���s���
  int drivePosition();
  void drivePositionReset();

 private:
  int errorCorrection();  //���ۂ̑��s��Ԃƃ}�b�v�X�e�[�^�X�̌덷���m
  int m_rightNumRotation;  //�E���[�^�[��]��
  int m_leftNumRotation;   //�����[�^�[��]��
  int nowState = 0;        //���݂̑��s���

  // L�R�[�X�̑��s�菇
  const std::array<DriveState, STATE_MAX> m_stateLeft = {
      {{620.0f + 80 - 5, Straight},
       {1240.0f + 80, LargeLeftTurn},
       {1836.0f + 80, Straight},
       {2592.0f + 80, LargeLeftTurn},
       {2722.0f + 80, Straight},
       {3388.0f + 80, SmallLeftTurn},
       {4704.0f + 80, SmallRightTurn},
       {4894.0f + 80, Straight},
       {5694.0f + 80, LargeRightTurn},
       {6604.0f + 80, Straight},
       {7240.0f + 80, LargeRightTurn},
       {7400.0f + 80, Straight},
       {7782.0f + 80 - 50, SmallRightTurn},
       {9192.0f + 80, SmallLeftTurn},
       {9372.0f + 80, Straight},
       {9372.1f + 80, Goal}}};

  // R�R�[�X�̑��s�菇
  const std::array<DriveState, STATE_MAX> m_stateRight = {
      {{620.0f + 80 - 5, Straight},
       {1240.0f + 80, LargeRightTurn},
       {1836.0f + 80, Straight},
       {2592.0f + 80, LargeRightTurn},
       {2722.0f + 80, Straight},
       {3388.0f + 80, SmallRightTurn},
       {4704.0f + 80, SmallLeftTurn},
       {4894.0f + 80, Straight},
       {5694.0f + 80, LargeLeftTurn},
       {6604.0f + 80, Straight},
       {7240.0f + 80, LargeLeftTurn},
       {7400.0f + 80, Straight},
       {7782.0f + 80 - 50, SmallLeftTurn},
       {9192.0f + 80, SmallRightTurn},
       {9372.0f + 80, Straight},
       {9372.1f + 80, Goal}}};
};