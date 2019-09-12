///
/// @file Phase1.h
/// @brief ゲート前で停止させ、車体を後傾させる
///

#pragma once
#include "SonarControl.h"
#include "TailControl.h"
#include <Drive.h>
#include <RyujiEv3.h>

/// フェーズ状況の確認
class Phase1{
private:

        TailControl t_ctrl;

public:
        ///
  	    /// @fn bool run()
	    /// @brief Phase1の開始
	    /// @retval true  成功
	    /// @retval false 失敗
	    ///   
        bool run();
};

