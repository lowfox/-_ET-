// DistanceMeasure.h
#pragma once
// include�t�@�C��
#include <Steering.h>

//�N���X��`
//�N���X��  :DistanceMeasure
//�@�\��    :�����v��
//�@�\�T�v  :�X�^�[�g����̗݌v�������v������

class DistanceMeasure {
 public:
  DistanceMeasure();              //�R���X�g���N�^
  ~DistanceMeasure();             //�f�X�g���N�^
  static float getDistance();     //�݌v�����擾�֐�

 private:
  static float m_mileage;         //�݌v�����ۑ��ϐ�
};