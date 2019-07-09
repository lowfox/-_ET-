//LineTrace.h

//include�t�@�C��
#include <Drive.h>
#include "Enum.h"

//�N���X��`
//�N���X��  :LineTrace
//�@�\��    :MW��LineTrace��PID�l���Z�b�g
//�@�\�T�v  :�e��(�J�[�u��)�ɍœK�����ꂽPID�l���Z�b�g����


class LineTrace {
 public:
  LineTrace();                 //�R���X�g���N�^
  ~LineTrace();                //�f�X�g���N�^
  int lineTraceDrive(MapState runState); //�}�b�v�󋵂ɍ��킹�čœK��PID�l���Z�b�g

 private:
  PID m_straightPID;            //�������s�pPID�l
  PID m_smallRightTurn;         //�E�����pPID�l
  PID m_largeRightTurn;         //�E����pPID�l
  PID m_smallLeftTurn;          //�������pPID�l
  PID m_largeLeftTurn;          //������pPID�l
};