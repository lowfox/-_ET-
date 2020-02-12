#pragma once
#include <ISceneLogic.h>
#include <vector>

class Course{
    private:
        std::vector<ISceneLogic*> m_course; 
        std::vector<int> m_runSceneNo;
    public:
        ///
        /// @fn Course(std::vector<ISceneLogic*> course)
        /// @brief コンストラクタ。引数に実行するコースの実体を入れる
        /// @param *sceneMap 実行するコースのポインタ
        ///
        Course(std::vector<ISceneLogic*> course);

       
        ///
        /// @fn init(int runSceneNo)
        /// @brief 配列で実行するシーンを選択する
        /// @param *runSceneNo 実行するシーンNoのポインタ
        /// @retval true 成功
	    /// @retval false 失敗
        ///
        bool init(std::vector<int> runSceneNo);
        
        ///
        /// @fn run()
        /// @brief コースを実行する
        /// @retval true 成功
	    /// @retval false 失敗
        ///
        bool run();

};