#pragma once
#include <Interface/ISpeaker.h>
#include <ev3api.h>

namespace RyujiEv3 {
class CSpeaker : public ISpeaker {
 private:
  uint8 m_volume = 0;

  memfile_t m_wavefile;

  bool m_fileplay = false;

 public:
  CSpeaker();

  ~CSpeaker() override;

  bool setVolume(uint8 volume) override;

  uint8 getVolume() override;

  bool playFile(const char* path, int32 duration);

  bool playTone(uint16 frequency, int32 duration) override;

  bool stop() override;
};
}  // namespace RyujiEv3