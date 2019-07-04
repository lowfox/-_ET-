## TODO ##
- dockerfile -> dockerimage
- docker image がちゃんと想定通りの構成になっているか確認
- dockerimage -> dockercontainer
- build test
- install 報告


COPY failed: stat /var/lib/docker/tmp/docker-builder026759387/build/home: no such file or directory
make: *** [docker-build] Error 1

### docker run
docker run -it ubuntu:18.04 sh
docker run -v /Users/cr0w/dev/src/github.com/ro-2020/ev3/workspace/linetrace:/project -it ubuntu:18.04 sh

### hoge検索
cd /
find . -name hoge


```Makefile

```
cd /hrp2/sdk/workspace && make app=RO2020EV3
/hrp2/sdk/common/library
```


```
ATT_MOD("System.o");
ATT_MOD("Middleware/Steering/BalanceSteering.o");
ATT_MOD("Middleware/Steering/NomalSteering.o");
ATT_MOD("Middleware/Steering/SteeringManager.o");
ATT_MOD("Middleware/Steering/Steering.o");
ATT_MOD("Middleware/Drive/NomalDrive.o");
ATT_MOD("Middleware/Drive/LineTraceDrive.o");
ATT_MOD("Middleware/Drive/DriveManager.o");
ATT_MOD("Middleware/Drive/Drive.o");
ATT_MOD("Middleware/DriveEngine/DriveEngine.o");
ATT_MOD("Middleware/Detect/Detect.o");
ATT_MOD("Logger/Logger.o");
ATT_MOD("Logger/CLogger.o");
ATT_MOD("SceneManager/SceneManager.o");
ATT_MOD("LineTrace/LineTraceScene.o");
ATT_MOD("Lookup/LookupScene.o");
ATT_MOD("Garage/GarageScene.o");
ATT_MOD("Seesaw/SeesawScene.o");
```