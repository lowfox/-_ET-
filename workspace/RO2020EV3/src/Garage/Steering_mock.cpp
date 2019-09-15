#include "../Middleware/DriveEngine/DriveEngine.h"
#include "../Middleware/Steering/SteeringManager.h"
#include "../Middleware/Drive/DriveManager.h"
#include "../../app.h"
#include "Steering_mock.h"
//#include <Steering.h>

namespace Steering_mock {
float GetDistance() {
  static int j = 0;
  j++;
  switch (j) {
    case 1:
      return 0.0f;
      break;
    case 2:
      return 0.1f;
      break;
    case 3:
      return 0.2f;
      break;
    case 4:
      return 0.3f;
      break;
    default:
      return 0.0f;
      break;
  }
}
}  // namespace Steering_mock