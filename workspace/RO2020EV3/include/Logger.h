///
/// @file Logger.h
/// @brief ���K�[
///
#pragma once
//#define _DEBUG
#define EV3_LOG_DEBUGING
#define MAX_LOG_LENGTH	(256)

/// ���O�̎��
enum class LogDesc
{
	Error,
	Info,
	Application,
	Debug
};

/// ���O�̏o�̓��x��
enum class LogOutLevel
{
	/// �G���[���O�̂�
	Error,

	/// �ʏ탍�O
	Nomal,

	/// �S���O���o��
	All
};

namespace Logger
{
	void WriteLog(LogDesc desc,const char* format,...);

	///
	/// @fn void SetOutLevel(LogOutLevel outLevel)
	/// @brief ���O�̏o�̓��x����ݒ肷��
	/// @param outLevel ���x(0�`100)
	///
	void SetOutLevel(LogOutLevel outLevel);
}


#if defined (_DEBUG) || defined(EV3_LOG_DEBUGING)

/// ���O�o��
#define EV3_LOG(...)       Logger::WriteLog(LogDesc::Application,__VA_ARGS__)

/// �f�o�b�O���O�o��
#define EV3_LOG_DEBUG(...) Logger::WriteLog(LogDesc::Debug,__VA_ARGS__)

/// �G���[���O�o��
#define EV3_LOG_ERROR(...) Logger::WriteLog(LogDesc::Error,__VA_ARGS__)

/// �V�X�e�����O�o��
#define EV3_LOG_INFO(...)  Logger::WriteLog(LogDesc::Info,__VA_ARGS__)

#else 

#define EV3_LOG(...)       void(0) 

#define EV3_LOG_DEBUG(...) void(0)
#define EV3_LOG_ERROR(...) void(0)
#define EV3_LOG_INFO(...)  void(0)

#endif