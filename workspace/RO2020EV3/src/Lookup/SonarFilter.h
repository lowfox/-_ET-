///
/// @file SonarFilter.h
/// @brief ゲート通過準備
///
#pragma once
#include <array>
#include <RyujiEv3.h>
#include "Debug.h"

#define MIN_SONER 5
#define MAX_SONER 30
#define OUT_OF_RANGE 99

class SonarFilter
{
private:

        int16 data_pointer = 0;

        std::array<int16, 3> avg_datas {0, 0, 0};
        
        #ifdef __LOOKUP_DEBUG__
        int16 distance = 0;
        #endif

        // singleton
        SonarFilter();
        ~SonarFilter(); 
        static SonarFilter* instance;   //local_static_instance
        SonarFilter(const SonarFilter &x);  //make it unable copy other data inside
        SonarFilter&operator=(const SonarFilter &); //make it unable to make copy

public:

        #ifdef __LOOKUP_DEBUG__
        void SetAvg(int16 test_val1,int16 test_val2,int16 test_val3);
        void StbGetDistance(int distance);
        #endif

        ///
  	/// @fn void FilterInput()
        /// @brief sonarsensorの値を取得し、格納する
        /// @retval true  成功
	/// @retval false 失敗
    	///   
        bool FilterInput();

        ///
        /// @fn int GetAvg()
        /// @brief SonarSensor値の取得
        /// @retval avg avgdatasの平均値[cm]
        ///   
        int16 GetAvg(); 

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
  	///@fn  static SonarFilter* GetInstance()
        ///@brief シングルトンクラスの実体をもらう
	///@retval SonarFilter* シングルトンの実体 
	///
        static SonarFilter* GetInstance(void);      

        ///
  	/// @fn void RestartData()
	/// @brief avgdatasの値をリセット
	///   
        void RestartData();
};

