#pragma once
#include <ISceneLogic.h>
#include <RyujiEv3.h>
#include <vector>
#include <Logger.h>
class Course{
    private:
        uint8 m_runSceneTotalNum = 0;
    protected:
        std::vector<ISceneLogic*> m_course;
    public:
        ///
        /// @fn bool run()
        /// @brief 実行するシーンを引数に渡してコースを実行する 
        /// @param const int* runSceneNo 実行するシーンNoが入った配列ポインタ
	    /// @retval true 成功
	    /// @retval false 失敗
        ///
        bool run(const uint8* runSceneNo);
        virtual ~Course(){}
};