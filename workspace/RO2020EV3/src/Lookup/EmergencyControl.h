///
/// @file EmergencyControl.h
/// @brief ライン復帰
///

#pragma once
#include "RyujiEv3.h"
#include <Drive.h>
#include "Debug.h"

#define MIN_REFLRCT 10
#define MAX_REFLRCT 40


class EmergencyControl
{
private:
               
		#ifdef __LOOKUP_DEBUG__
        int8  reflect      	  = 0;
		int32 left_deg     	  = 0;
		int32 right_deg    	  = 0;
		#endif
public:
        ///
        /// @fn bool LeftTurn()
		/// @brief 走行体が左に向いてラインを見つける
		/// @retval true  成功
		/// @retval false 失敗
		///   
        bool LeftTurn();

        ///
        /// @fn bool RightTurn()
		/// @brief 走行体が右に向いてラインを見つける
		/// @retval true  成功
		/// @retval false 失敗
		///   
        bool RightTurn();
        
        ///
        /// @fn void StartColor()
		/// @brief カラセンサーを非同期でラインをチェックする
		///   
        void StartColor();

        ///
        /// @fn void StartColor()
		/// @brief ライン上であるかどうかの判断
		/// @retval true  白/黒のライン上にある
		/// @retval false 白/黒のライン上でない
		///   
        bool LineCheck();

		#ifdef __LOOKUP_DEBUG__
        void StbGetColor(uint8 reflect);

		void StbLeftTurnAngle(int32 left,int32 right);

		void StbRightTurnAngle(int32 left,int32 right);

        #endif

};
