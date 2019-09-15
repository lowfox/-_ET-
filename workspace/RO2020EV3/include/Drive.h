///
/// @file Drive.h
/// @brief �h���C�u
///
#pragma once
#include <RyujiEv3.h>

/// �h���C�u���[�h
enum class DriveMode {
  /// ���C���g���[�X���[�h
  LineTrace,

  /// �ʏ탂�[�h
  Nomal
};

/// ���C���̐F
enum class BlueLineMode 
{
	/// �F���C���g���[�X
	Blue,

	/// �ʏ탉�C���g���[�X
	Nomal
};

/// �����C�����g���[�X���鑤
enum class Side {
  /// ����
  Left,

  /// �E��
  Right
};

/// PID
struct PID {
  /// P
  float kp;

  /// I
  float ki;

  /// D
  float kd;
};

/// �g���[�X�J���[
struct TraceColor {
  /// ���F
  float black;

  /// ���F
  float white;

  ///�F
  RGB blue;
};

namespace Drive 
{
	///
	/// @fn void Drive(int32 speed,int32 turn = 0)
	/// @brief ���s����
	/// @param speed ���x(0�`100)
	/// @param turn ����l(-100�`100)�����C���g���[�X���[�h���͖���
	/// @retval true ����
	/// @retval false ���s
	///
	bool Drive(int32 speed,int32 turn = 0);

	///
	/// @fn void Stop()
	/// @brief ��~����
	/// @retval true ����
	/// @retval false ���s
	///
	bool Stop();

	///
	/// @fn void Rotate()
	/// @brief ���]����@�O�_�|�������Ă��Ȃ���Ԃł́A���̊֐��͕K�����s����
	/// @retval true ����
	/// @retval false ���s
	///
	bool Rotate();

	///
	/// @fn void SetDriveMode(DriveMode mode)
	/// @brief �h���C�u���[�h���w�肷��
	/// @param mode �h���C�u���[�h
	///
	bool SetDriveMode(DriveMode mode);

	///
	/// @fn DriveMode GetDriveMode()
	/// @brief ���ݎg�p���Ă���h���C�u���[�h���擾����
	/// @return ���ݎg�p���Ă���h���C�u���[�h
	///
	DriveMode GetDriveMode();

	

	namespace ColorCalibrate
	{
		///
		/// @fn RGB RGBAverage1Sec()
		/// @brief 1�b�Ԃ�RGB�̕��ς�Ԃ�
		/// @return 1�b�Ԃ�RGB�̕��ϒl
		///
		RGB RGBAverage1Sec();

		///
		/// @fn bool AddTraceColor(int32 count,const TraceColor& traceColor)
		/// @brief count�̃g���[�X�J���[��ǉ�����
		/// @param count �p�x(�x)
		/// @param traceColor �g���[�X�J���[
		/// @retval true ����
		/// @retval false ���s
		///
		bool AddTraceColor(int32 count,const TraceColor& traceColor);

		///
		/// @fn TraceColor& GetTraceColor(int32 count)
		/// @brief count�ɑΉ�����g���[�X�J���[��Ԃ��Bcount�ɑΉ�����g���[�X�J���[���Ȃ��ꍇ�̓f�t�H���g�\�z���ĎQ�Ƃ�Ԃ��B
		/// @param count �ԑ̂̊p�x
		/// @return count�ɑΉ�����g���[�X�J���[
		///
		TraceColor& GetTraceColor(int32 count);
	}


	namespace LineTrace
	{
		///
		/// @fn void SetPID(const PID& pid)
		/// @brief ���C���g���[�X�Ɏg�p����PID�̒l��ݒ肷��
		/// @param pid �Z�b�g����PID�l
		///
		void SetPID(const PID& pid);

		///
		/// @fn PID GetPID()
		/// @brief ���ݎg�p���Ă���PID�l���擾����
		/// @return ���ݎg�p���Ă���PID�l
		///
		PID GetPID();

		///
		/// @fn void SetTraceColor(const TraceColor& traceColor)
		/// @brief ���C���g���[�X�Ɏg�p����g���[�X�J���[��ݒ肷��
		/// @param traceColor �Z�b�g����g���[�X�J���[
		///
		void SetTraceColor(const TraceColor& traceColor);

		///
		/// @fn TraceColor GetTraceColor()
		/// @brief ���ݎg�p���Ă���g���[�X�J���[���擾����
		/// @return ���ݎg�p���Ă���g���[�X�J���[
		///
		TraceColor GetTraceColor();

		///
		/// @fn void SetSide(Side side)
		/// @brief �����C���̂ǂ��瑤���g���[�X���邩�ݒ肷��
		/// @param side �����C���̑�
		///
		void SetSide(Side side);

		///
		/// @fn Side GetSide()
		/// @brief ���݁A�����C���̂ǂ��瑤���g���[�X���Ă��邩�擾����
		/// @return �g���[�X���Ă��鑤
		///
		Side GetSide();

		///
		/// @fn void setLineMode(BlueLineMode lineMode)
		/// @brief �F�̃��C���g���[�X�����邩�ۂ�
		/// @return �u���[���C�����[�h�̃I���I�t
		///
		void SetLineMode(BlueLineMode lineMode);

		///
		/// @fn  BlueLineMode getLineMode()
		/// @brief ���݁A�u���[���C�����[�h�̎擾
		/// @param BlueLineMode �F�����C���g���[�X�̃I���I�t
		///
        BlueLineMode GetLineMode();
	}
}
