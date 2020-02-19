#include <Drive.h>
#include <RyujiEv3.h>
#include <RyujiEv3Engine.h>
#include <Logger.h>
class DetectLineColor{
    private:
        ReadColor m_detectColor;
        ReadColor m_currentColor[10];
        int m_detectCnt;
        int m_trueCnt;
    public:
        void configDetectColor(ReadColor color);
        bool detect();
};