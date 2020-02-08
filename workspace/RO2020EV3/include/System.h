///
/// @file System.h
/// @brief �V�X�e���֐�
///
#pragma once
#include <RyujiEv3.h>

namespace System {
///
/// @fn bool Init(const PortData& port)
/// @brief ���C�u�����̏���������
/// @param port �Z���T�A���[�^�[�̐ڑ�����Ă���|�[�g���
/// @retval true ����
/// @retval false ���s
///
bool Init(const PortData& port);

///
/// @fn void Exit()
/// @brief ���C�u�����̏I������
///
void Exit();
}  // namespace System