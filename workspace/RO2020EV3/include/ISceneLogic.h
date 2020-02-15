#pragma once
class ISceneLogic{
    private:
    public:
        virtual ~ISceneLogic(){}
        ///
        /// @fn bool init()
        /// @brief シーンロジックを初期化する。前のシーンからの受け渡し直後に呼ばれる。Arduinoのsetupと同じ作用
	    /// @retval true 成功
	    /// @retval false 失敗
        ///
        virtual bool init(void) = 0;
        
        ///
        /// @fn bool run()
        /// @brief シーンを実行する。init()直後に呼ばれる。Arduinoのloopと同じ作用
	    /// @retval true 成功
	    /// @retval false 失敗
        ///
        virtual bool run(void) = 0;
};