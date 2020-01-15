#pragma once
#include <steering.h>

//�e�X�g�p�֐�(DistanceMeasure�ȊO�̃e�X�g�p�֐��������ɏ����Ă����B)
namespace SteeringMoc {
  float GetDistance();
}

//�e�X�g�p�N���X
class DistanceMeasure {
public:
  DistanceMeasure();              //�R���X�g���N�^
  ~DistanceMeasure();             //�f�X�g���N�^
  //�֐���   :getDistance
  //�@�\��   :�e�X�g
  //�@�\�T�v :�e�X�g����(���l)�����^�[������
  //����     :����
  //�߂�l   :float               :�݌v���s������͂������l
  static float getDistance();     //�e�X�g�p�݌v�����擾�֐�

private:
  static float m_mileage;         //�e�X�g�p�݌v�����ۑ��ϐ�
};

#if defined LINETRACE_DEBUG
#define GET_DISTANCE() SteeringMoc::GetDistance()
//#define DISTANCE_MEASURE() DistanceMeasureMoc::getDistance()
#else
#define GET_DISTANCE() Steering::GetDistance()
//#define DISTANCE_MEASURE() DistanceMeasure::getDistance()

#endif