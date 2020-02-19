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
Course.o\
Course2019Left.o\
Course2019Right.o\
GarageScene2019Logic.o\
SeesawScene2019Logic.o\
CompleteGarage.o\
GarageLineTrace.o\
RecognizeCurrentRocation.o\
DetectLineColor.o\
DetectMireage.o\

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-test/Makefile
include $(EV3RT_SDK_LIB_DIR)/lib2/Makefile
include $(EV3RT_SDK_LIB_DIR)/RyujiEv3/Makefile



endif


