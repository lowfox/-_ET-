///
/// @file Phase2.h
/// @brief 通過間処理
///

#pragma once
#include "SonarControl.h"
#include "TailControl.h"
#include "MotorControl.h"
#include <Drive.h>
#include <RyujiEv3.h>
#include"../Logger/CLogger.h"

/// フェーズ状況の確認
class Phase2
{
public:

		MotorControl m_ctrl;
		
		TailControl t_ctrl;

        ///
  	    /// @fn bool run()
	    /// @brief Phase2の開始
	    /// @retval true  成功
	    /// @retval false 失敗
	    ///   
        bool run();
};

