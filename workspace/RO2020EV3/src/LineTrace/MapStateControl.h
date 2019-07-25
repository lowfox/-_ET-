// MapStateControl.h
#pragma once
// include�t�@�C��
#include "DistanceMeasure.h"
#include "MapStateDefinition.h"
#include <array>

//�萔��`
#define STATE_MAX 16              //���s��ԕψڂ̍ő吔
#define STATE_END 150.1f          // GOAL�܂ł̋���//��
#define LEFT_COURSE 0
#define RIGHT_COURSE 1
#define COURSE_MODE LEFT_COURSE   //���s�R�[�X�ݒ�

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
  MapStateControl();          //�R���X�g���N�^
  ~MapStateControl();         //�f�X�g���N�^
  //�֐���   :drivePosition
  //�@�\��   :���s�ʒu���f
  //�@�\�T�v :���s�������瑖�s���(�����A�E�J�[�u��)�𔻒f����
  //����     :����
  //�߂�l   :MapState        :���s���
  MapState drivePosition();

 private:
  int errorCorrection();      //���ۂ̑��s��Ԃƃ}�b�v�X�e�[�^�X�̌덷���m
  int m_rightNumRotation;     //�E���[�^�[��]��
  int m_leftNumRotation;      //�����[�^�[��]��

  //L�R�[�X�̑��s�菇
  const std::array<DriveState, STATE_MAX> m_stateLeft = {
      {{10.0f, Straight},//(��)
       {20.0f, LargeLeftTurn},//(��)
       {30.0f, Straight},//(��)
       {40.0f, LargeLeftTurn},//(��)
       {50.0f, Straight},//(��)
       {60.0f, SmallLeftTurn},//(��)
       {70.0f, SmallRightTurn},//(��)
       {80.0f, Straight},//(��)
       {90.0f, LargeRightTurn},//(��)
       {100.0f, Straight},//(��)
       {110.0f, LargeRightTurn},//(��)
       {120.0f, Straight},//(��)
       {130.0f, SmallRightTurn},//(��)
       {140.0f, SmallLeftTurn},//(��)
       {150.0f, Straight},//(��)
       {150.1f, Goal}}};//(��)

  //R�R�[�X�̑��s�菇
  const std::array<DriveState, STATE_MAX> m_stateRight = {
      {{10.0f, Straight},//(��)
       {20.0f, LargeRightTurn},//(��)
       {30.0f, Straight},//(��)
       {40.0f, LargeRightTurn},//(��)
       {50.0f, Straight},//(��)
       {60.0f, SmallRightTurn},//(��)
       {70.0f, SmallLeftTurn},//(��)
       {80.0f, Straight},//(��)
       {90.0f, LargeLeftTurn},//(��)
       {100.0f, Straight},//(��)
       {110.0f, LargeLeftTurn},//(��)
       {120.0f, Straight},//(��)
       {130.0f, SmallLeftTurn},//(��)
       {140.0f, SmallRightTurn},//(��)
       {150.0f, Straight},//(��)
       {150.1f, Goal}}};//(��)
};