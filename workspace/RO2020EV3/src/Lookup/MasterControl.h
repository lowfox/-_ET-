///
/// @file MasterControl.h
/// @brief フェーズ管理
///

#pragma once 
#include "Phase1.h"
#include "Phase2.h"
#include "Phase3.h"
#include "Debug.h"

/// フェーズの状態遷移
class MasterControl
{
private:
		Phase1 phase1;

		Phase2 phase2;
		
		Phase3 phase3;

public:

		~MasterControl();
		
        ///
  	    /// @fn void LookUp()
	    /// @brief LookUp攻略
	    /// @retval true  成功
	    /// @retval false 失敗
	    ///   
        bool LookUp();


		
};
