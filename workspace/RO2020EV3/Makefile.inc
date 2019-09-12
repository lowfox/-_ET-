APPL_COBJS +=\
balancer.o\
balancer_param.o

APPL_CXXOBJS +=\
System.o\
BalanceSteering.o\
NomalSteering.o\
SteeringManager.o\
Steering.o\
NomalDrive.o\
LineTraceDrive.o\
DriveManager.o\
DriveEngine.o\
Drive.o\
Detect.o\
Logger.o\
CLogger.o\
SceneManager.o\
LineTraceScene.o\
LookupScene.o\
GarageScene.o\
SeesawScene.o\
seesawCapture.o\
gotoSeesaw.o\
seesawClimber.o\
seesawDouble.o\
seesawDesc.o\
garageInit.o\
straightRunner.o\
distanceRunner.o\
modeSwitcher.o\
wheelClimber.o\
wheelAligner.o\
braker.o\
lineTracer.o\
getUp.o\
seesawRunner.o\
angleDetector.o\
angularVelocityDetector.o\
tailPositioner.o\
seesawTest.o\
tailPositionerTest.o\
angleDetectorTest.o\
angularVelocityDetectorTest.o\
distanceRunnerTest.o\
lineTracerTest.o\
seesawRunnerTest.o\
straightRunnerTest.o


SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-test/Makefile
include $(EV3RT_SDK_LIB_DIR)/lib2/Makefile
include $(EV3RT_SDK_LIB_DIR)/RyujiEv3/Makefile



endif


