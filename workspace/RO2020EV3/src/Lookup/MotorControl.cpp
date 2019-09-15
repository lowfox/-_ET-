#include "MotorControl.h"
#include "../Logger/CLogger.h"

bool MotorControl::CompareVal() {
#ifdef __LOOKUP_DEBUG__
  if (20 <= (this->start_val + this->offset_val)) {
    return false;
  }
#else
  if (Steering::GetDistance() <= (this->start_val + this->offset_val)) {
    return false;
  }
#endif
  return true;
}
#ifdef __LOOKUP_DEBUG__
void MotorControl::StbCompareVal(float start, int16 offset) {
  this->start_val  = start;
  this->offset_val = offset;
}
#endif

void MotorControl::SetStartDistance() {
#ifdef __LOOKUP_DEBUG__
  EV3_LOG_DEBUG("StartDistance %f[mm]", this->start_val);
#else
  this->start_val = Steering::GetDistance();
#endif
}

#ifdef __LOOKUP_DEBUG__
void MotorControl::StbSetStartDistance(float distance) {
  this->start_val = distance;
}
#endif

void MotorControl::SetOffset() {
  if (SonarControl::GetInstance()->GetAvg() != 99) {
    this->offset_val = SonarControl::GetInstance()->GetAvg();
    this->offset_val += THRESHOLD;
#ifdef __LOOKUP_DEBUG__
    EV3_LOG_DEBUG("SetOffset %d + %d = %d[mm]",
                  SonarControl::GetInstance()->GetAvg(), THRESHOLD,
                  this->offset_val);
#endif
  }
#ifdef __LOOKUP_DEBUG__
  EV3_LOG_DEBUG("SonarControl::GetInstance()->GetAvg() == 99");
#endif
  return;
}

void MotorControl::UpPassCnt() {
  this->pass_count += 1;
#ifdef __LOOKUP_DEBUG__
  EV3_LOG_DEBUG("pass_count %d回", pass_count);
#endif
}
#ifdef __LOOKUP_DEBUG__
void MotorControl::StbSetUpPassCnt(int8_t pass) { this->pass_count = pass; }
#endif

int8_t MotorControl::GetPassCount() { return this->pass_count; }