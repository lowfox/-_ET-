// ColorDetection.h
#pragma once
// include�t�@�C��
#include <RyujiEv3.h>

//�N���X��`
//�N���X��  :ColorDetection
//�@�\��    :�F���m
//�@�\�T�v  :�����͐F�����m����

class ColorDetection {
 public:
  ColorDetection();      //�R���X�g���N�^
  ~ColorDetection();     //�f�X�g���N�^
  //�֐���   :getBlueColor
  //�@�\��   :�F���m
  //�@�\�T�v :�J���[�Z���T�[�ŐF�����m�������ۂ���߂�l�ŕԂ�
  //����     :����
  //�߂�l   :bool       :�F���m = true
  bool getBlueColor();   //�F���m�֐�
  //�֐���   :getBlackColor
  //�@�\��   :���F���m
  //�@�\�T�v :�J���[�Z���T�[�ō��F�����m�������ۂ���߂�l�ŕԂ�
  //����     :����
  //�߂�l   :bool       :���F���m = true
  bool getBlackColor();  //���F���m�֐�
};