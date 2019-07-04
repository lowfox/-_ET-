///
/// @file Steering.h
/// @brief �X�e�A�����O
///
#pragma once
#include <RyujiEv3.h>

/// �X�e�A�����O���[�h
enum class SteeringMode
{
	/// �|�����[�h
	Balance,

	/// �ʏ탂�[�h
	Nomal
};

namespace Steering
{
	///
	/// @fn void SetMode(SteeringMode mode)
	/// @brief �X�e�A�����O���[�h���w�肷��
	/// @param mode �X�e�A�����O���[�h
	/// @retval true ����
	/// @retval false ���s
	///
	bool SetMode(SteeringMode mode);

	///
	/// @fn float GetDistance()
	/// @brief �N��������̑��s�������擾����
	/// @return ���s����[mm]
	///
	float GetDistance();
}