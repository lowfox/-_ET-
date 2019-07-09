//LineTrace.h

//includeファイル
#include <Drive.h>
#include "Enum.h"

//クラス定義
//クラス名  :LineTrace
//機能名    :MWのLineTraceにPID値をセット
//機能概要  :各状況(カーブ等)に最適化されたPID値をセットする


class LineTrace {
 public:
  LineTrace();                 //コンストラクタ
  ~LineTrace();                //デストラクタ
  int lineTraceDrive(MapState runState); //マップ状況に合わせて最適なPID値をセット

 private:
  PID m_straightPID;            //直線走行用PID値
  PID m_smallRightTurn;         //右小回り用PID値
  PID m_largeRightTurn;         //右大回り用PID値
  PID m_smallLeftTurn;          //左小回り用PID値
  PID m_largeLeftTurn;          //左大回り用PID値
};