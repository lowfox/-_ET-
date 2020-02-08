///
/// @file SonarControl.h
/// @brief ゲート前での停止距離管理
///

#pragma once
#include "SonarFilter.h"
#include <RyujiEv3.h>
#include <Drive.h>
#define STOP_DISTANCE 15
#include "Debug.h"

class SonarControl
{
private:

        int16 avg_data = 0; 

        // singleton
        static SonarControl* instance; //local_static_instance
		~SonarControl();
        SonarControl();    
		SonarControl(const SonarControl &x);  //make it unable copy other data inside
    	SonarControl&operator=(const SonarControl &); //make it unable to make copy

public:

	///
  	/// @fn void Destroy()
    /// @brief シングルトンクラスのデストラクター
	///        
	static void Destroy() //only can be called from inside class
	{
		if (instance)
		{
			delete instance;
			instance = nullptr;
		}
	}

	///
  	/// @fn  static SonarControl* GetInstance()
    /// @brief シングルトンクラスの実態をもらう
	///	@retval SonarControl* シングルトンの実態 
	///
    static SonarControl* GetInstance();

    ///
  	/// @fn void SonarRun()
    /// @brief 走行する
	///        
    void SonarRun();

    ///
  	/// @fn int GetAvg()
	/// @brief SonarControlのavg_data値を返す
	/// @retval avg filter値
	///        
    int16 GetAvg();

    ///
  	/// @fn bool CheckAvg()
	/// @brief filter値をチェック
	/// @retval true 平均値が指定値内である
	/// @retval false 平均値が指定値内外である
    bool CheckAvg(); 

    #ifdef __LOOKUP_DEBUG__

    void SetAvg(int16 avg);
    #endif


};

