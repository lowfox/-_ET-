///
/// @file Logger.h
/// @brief ロガー
///
#pragma once
//#define _DEBUG
#define EV3_LOG_DEBUGING
#define MAX_LOG_LENGTH	(256)

/// ログの種類
enum class LogDesc
{
	Error,
	Info,
	Application,
	Debug
};

/// ログの出力レベル
enum class LogOutLevel
{
	/// エラーログのみ
	Error,

	/// 通常ログ
	Nomal,

	/// 全ログを出力
	All
};

namespace Logger
{
	void WriteLog(LogDesc desc,const char* format,...);

	///
	/// @fn void SetOutLevel(LogOutLevel outLevel)
	/// @brief ログの出力レベルを設定する
	/// @param outLevel 速度(0～100)
	///
	void SetOutLevel(LogOutLevel outLevel);
}


#if defined (_DEBUG) || defined(EV3_LOG_DEBUGING)

/// ログ出力
#define EV3_LOG(...)       Logger::WriteLog(LogDesc::Application,__VA_ARGS__)

/// デバッグログ出力
#define EV3_LOG_DEBUG(...) Logger::WriteLog(LogDesc::Debug,__VA_ARGS__)

/// エラーログ出力
#define EV3_LOG_ERROR(...) Logger::WriteLog(LogDesc::Error,__VA_ARGS__)

/// システムログ出力
#define EV3_LOG_INFO(...)  Logger::WriteLog(LogDesc::Info,__VA_ARGS__)

#else 

#define EV3_LOG(...)       void(0) 

#define EV3_LOG_DEBUG(...) void(0)
#define EV3_LOG_ERROR(...) void(0)
#define EV3_LOG_INFO(...)  void(0)

#endif