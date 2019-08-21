// MapStateControl.h
#pragma once
// include�t�@�C��
#include "DistanceMeasure.h"
#include "MapStateDefinition.h"
#include <array>

//�萔��`
#define STATE_MAX 16              //���s��ԕψڂ̍ő吔
#define STATE_END 9632.1f         // GOAL�܂ł̋���//��
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
      {{1070.0f, Straight},//(��)
       {1690.0f, LargeLeftTurn},//(��)
       {2286.0f, Straight},//(��)
       {3042.0f, LargeLeftTurn},//(��)
       {3172.0f, Straight},//(��)
       {3838.0f, SmallLeftTurn},//(��)
       {1316.0f, SmallRightTurn},//(��)
       {5154.0f, Straight},//(��)
       {5954.0f, LargeRightTurn},//(��)
       {6864.0f, Straight},//(��)
       {7500.0f, LargeRightTurn},//(��)
       {7660.0f, Straight},//(��)
       {8042.0f, SmallRightTurn},//(��)
       {9452.0f, SmallLeftTurn},//(��)
       {9632.0f, Straight},//(��)
       {9632.1f, Goal}}};//(��)

  //R�R�[�X�̑��s�菇
  const std::array<DriveState, STATE_MAX> m_stateRight = {
      {{1070.0f, Straight},//(��)
       {1690.0f, LargeRightTurn},//(��)
       {2286.0f, Straight},//(��)
       {3042.0f, LargeRightTurn},//(��)
       {3172.0f, Straight},//(��)
       {3838.0f, SmallRightTurn},//(��)
       {1316.0f, SmallLeftTurn},//(��)
       {5154.0f, Straight},//(��)
       {5954.0f, LargeLeftTurn},//(��)
       {6864.0f, Straight},//(��)
       {7500.0f, LargeLeftTurn},//(��)
       {7660.0f, Straight},//(��)
       {8042.0f, SmallLeftTurn},//(��)
       {9452.0f, SmallRightTurn},//(��)
       {9632.0f, Straight},//(��)
       {9632.1f, Goal}}};//(��)
};