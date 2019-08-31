///
/// @file SonarControl.h
/// @brief 通過距離管理
///
#pragma once 
#include <Steering.h>
#include "SonarControl.h"
#include <Drive.h>
#include "Debug.h"
#define THRESHOLD 175

class MotorControl
{
private:

        int16 offset_val = 0;

        float start_val = 0;

        int8_t pass_count = 0;

public:     
        ///
  	/// @fn void Compare_Val()
	/// @brief 通過終了Distanceと比較
        /// @retval true  成功
        /// @retval false 失敗
	///   
        bool CompareVal();
        #ifdef __LOOKUP_DEBUG__
        void StbCompareVal(float start , int16 offset);
        #endif 

        ///
        /// @fn void SetStartDistance()
	/// @brief 開始距離のセット
	///   
        void SetStartDistance();
        #ifdef __LOOKUP_DEBUG__
        void StbSetStartDistance(float distance);
        #endif

        ///
  	/// @fn void SetOffset()
	/// @brief 通過完了値のセット
        /// @retval true  成功
        /// @retval false 失敗
        ///   
        void SetOffset();
        
        ///
        /// @fn void UpPassCnt()
	/// @brief 通過カウントアップ
	///   
        void UpPassCnt();
        #ifdef __LOOKUP_DEBUG__
        void StbSetUpPassCnt(int8_t pass);
        #endif

        ///
  	/// @fn  int GetPassCount
	/// @brief ゲート通過回数を返す
	/// @retval ゲート通過回数
        int8_t GetPassCount();

};

