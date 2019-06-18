#include "CSpeaker.h"
#include <ev3api.h>

namespace RyujiEv3 {
CSpeaker::CSpeaker() { setVolume(0); }

CSpeaker::~CSpeaker() { stop(); }

bool CSpeaker::setVolume(uint8 volume) {
  auto result = ev3_speaker_set_volume(volume);

  if (result != E_OK) {
    return false;
  }

  m_volume = volume;

  return true;
}

uint8 CSpeaker::getVolume() { return m_volume; }

bool CSpeaker::playFile(const char* path, int32 duration) {
  stop();
  if (E_OK != ev3_memfile_load(path, &m_wavefile)) {
    return false;
  }

  if (E_OK != ev3_speaker_play_file(&m_wavefile, duration)) {
    return false;
  }

  m_fileplay = true;

  return true;
}

bool CSpeaker::playTone(uint16 frequency, int32 duration) {
  stop();
  return E_OK == ev3_speaker_play_tone(frequency, duration);
}

bool CSpeaker::stop() {
  if (E_OK != ev3_speaker_stop()) {
    return false;
  }

  if (m_fileplay) {
    ev3_memfile_free(&m_wavefile);
    m_fileplay = false;
  }

  return true;
}
}  // namespace RyujiEv3