///
/// @file Phase3.h
/// @brief ガレージに受け渡し
///
#pragma once
#include "TailControl.h"
#include "EmergencyControl.h"

/// フェーズ状況の確認
class Phase3{
private:
		TailControl t_ctrl;
		
		EmergencyControl e_ctrl;
public:

        ///
  	    /// @fn bool run()
	    /// @brief Phase3の開始
	    /// @retval true  成功
	    /// @retval false 失敗
	    ///   
        bool run();
};

