#include <Steering.h>
#include <RyujiEv3.h>
class DetectMireage{
    private:
    float m_detectMireage;
    float m_currentMireage;
    public:
    void configDetectDistance(float distance);
    bool detect();

};