///
/// @file Drive.h
/// @brief ドライブ
///
#pragma once
#include <RyujiEv3.h>

/// ドライブモード
enum class DriveMode
{
	/// ライントレースモード
	LineTrace,

	/// 通常モード
	Nomal
};

/// 黒ラインをトレースする側
enum class Side
{
	/// 左側
	Left,

	/// 右側
	Right
};

/// PID
struct PID
{
	/// P
	float kp;

	/// I
	float ki;

	/// D
	float kd;
};

/// トレースカラー
struct TraceColor
{
	/// 黒色
	float black;

	/// 白色
	float white;

	///青色
	RGB blue;
};

namespace Drive 
{
	///
	/// @fn void Drive(int32 speed,int32 turn = 0)
	/// @brief 走行する
	/// @param speed 速度(0～100)
	/// @param turn 旋回値(-100～100)※ライントレースモード時は無効
	/// @retval true 成功
	/// @retval false 失敗
	///
	bool Drive(int32 speed,int32 turn = 0);

	///
	/// @fn void Stop()
	/// @brief 停止する
	/// @retval true 成功
	/// @retval false 失敗
	///
	bool Stop();

	///
	/// @fn void Rotate()
	/// @brief 反転する　三点倒立をしていない状態では、この関数は必ず失敗する
	/// @retval true 成功
	/// @retval false 失敗
	///
	bool Rotate();

	///
	/// @fn void SetDriveMode(DriveMode mode)
	/// @brief ドライブモードを指定する
	/// @param mode ドライブモード
	///
	bool SetDriveMode(DriveMode mode);

	///
	/// @fn DriveMode GetDriveMode()
	/// @brief 現在使用しているドライブモードを取得する
	/// @return 現在使用しているドライブモード
	///
	DriveMode GetDriveMode();

	

	namespace ColorCalibrate
	{
		///
		/// @fn RGB RGBAverage1Sec()
		/// @brief 1秒間のRGBの平均を返す
		/// @return 1秒間のRGBの平均値
		///
		RGB RGBAverage1Sec();

		///
		/// @fn bool AddTraceColor(int32 count,const TraceColor& traceColor)
		/// @brief countのトレースカラーを追加する
		/// @param count 角度(度)
		/// @param traceColor トレースカラー
		/// @retval true 成功
		/// @retval false 失敗
		///
		bool AddTraceColor(int32 count,const TraceColor& traceColor);

		///
		/// @fn TraceColor& GetTraceColor(int32 count)
		/// @brief countに対応するトレースカラーを返す。countに対応するトレースカラーがない場合はデフォルト構築して参照を返す。
		/// @param count 車体の角度
		/// @return countに対応するトレースカラー
		///
		TraceColor& GetTraceColor(int32 count);
	}


	namespace LineTrace
	{
		///
		/// @fn void SetPID(const PID& pid)
		/// @brief ライントレースに使用するPIDの値を設定する
		/// @param pid セットするPID値
		///
		void SetPID(const PID& pid);

		///
		/// @fn PID GetPID()
		/// @brief 現在使用しているPID値を取得する
		/// @return 現在使用しているPID値
		///
		PID GetPID();

		///
		/// @fn void SetTraceColor(const TraceColor& traceColor)
		/// @brief ライントレースに使用するトレースカラーを設定する
		/// @param traceColor セットするトレースカラー
		///
		void SetTraceColor(const TraceColor& traceColor);

		///
		/// @fn TraceColor GetTraceColor()
		/// @brief 現在使用しているトレースカラーを取得する
		/// @return 現在使用しているトレースカラー
		///
		TraceColor GetTraceColor();

		///
		/// @fn void SetSide(Side side)
		/// @brief 黒ラインのどちら側をトレースするか設定する
		/// @param side 黒ラインの側
		///
		void SetSide(Side side);

		///
		/// @fn Side GetSide()
		/// @brief 現在、黒ラインのどちら側をトレースしているか取得する
		/// @return トレースしている側
		///
		Side GetSide();
	}
}