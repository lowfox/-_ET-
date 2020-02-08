#include "CBluetooth.h"
#include <ev3api.h>
#include <stdarg.h>

namespace RyujiEv3 {
CBluetooth::CBluetooth() {}

CBluetooth::~CBluetooth() { fclose(m_spp); }

bool CBluetooth::init() {
  if (m_spp) {
    fclose(m_spp);
  }

  m_spp = ev3_serial_open_file(EV3_SERIAL_BT);

  if (!m_spp) {
    return false;
  }

  return true;
}

uint8 CBluetooth::read() {
  if (!isConnected()) {
    return EOF;
  }

  return static_cast<uint8>(fgetc(m_spp));
}

bool CBluetooth::read(uint8& data) {
  uint8 readData = read();

  if (readData == static_cast<uint8>(EOF)) {
    return false;
  }

  data = readData;

  return true;
}

bool CBluetooth::write(uint8 data) {
  if (!isConnected()) {
    return false;
  }

  fputc(data, m_spp);

  return true;
}

uint32 CBluetooth::writeString(const char* format, ...) {
  uint32 writeSize = 0;

  if (!isConnected()) {
    return writeSize;
  }

  va_list args;
  char buf[256];

  va_start(args, format);
  vsprintf(buf, format, args);
  va_end(args);

  for (int32 i = 0; buf[i] != '\0'; i++) {
    if (!write(buf[i])) {
      return writeSize;
    }
    writeSize++;
  }

  if (!write('\0')) {
    return writeSize;
  }

  return (writeSize++);
}

bool CBluetooth::isConnected() { return ev3_bluetooth_is_connected(); }
}  // namespace RyujiEv3