#pragma once
#include <ISceneLogic.h>
#include <vector>
class Course{
    private:
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
        bool run(const int* runSceneNo);
  
};