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
  bool getBlueColor();   //�F���m�֐�
  bool getBlackColor();  //���F���m�֐�
};