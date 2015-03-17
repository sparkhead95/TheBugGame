################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Animal.cpp \
../src/Aphid.cpp \
../src/Configuration.cpp \
../src/Grid.cpp \
../src/Ladybug.cpp \
../src/Main.cpp \
../src/Manager.cpp 

OBJS += \
./src/Animal.o \
./src/Aphid.o \
./src/Configuration.o \
./src/Grid.o \
./src/Ladybug.o \
./src/Main.o \
./src/Manager.o 

CPP_DEPS += \
./src/Animal.d \
./src/Aphid.d \
./src/Configuration.d \
./src/Grid.d \
./src/Ladybug.d \
./src/Main.d \
./src/Manager.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


