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
MasterControl.o\
Phase1.o\
Phase2.o\
Phase3.o\
SonarControl.o\
SonarFilter.o\
TailControl.o\
EmergencyControl.o\
MotorControl.o\
LookUpTest.o

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-test/Makefile
include $(EV3RT_SDK_LIB_DIR)/lib2/Makefile
include $(EV3RT_SDK_LIB_DIR)/RyujiEv3/Makefile



endif


