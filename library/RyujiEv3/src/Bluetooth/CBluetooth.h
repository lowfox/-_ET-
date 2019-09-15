#include <Interface/IBluetooth.h>
#include <stdio.h>

namespace RyujiEv3 {
class CBluetooth : public IBluetooth {
 private:
  FILE* m_spp = nullptr;

 public:
  CBluetooth();

  ~CBluetooth() override;

  bool init();

  uint8 read() override;

  bool read(uint8& data) override;

  bool write(uint8 data) override;

  uint32 writeString(const char* format, ...) override;

  bool isConnected() override;
};
}  // namespace RyujiEv3