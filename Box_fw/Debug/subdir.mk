################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lcd1200.cpp \
../main.cpp 

OBJS += \
./lcd1200.o \
./main.o 

CPP_DEPS += \
./lcd1200.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../os -I../os/hal -I../os/kernel/include -I../kl_lib -I.././ -std=gnu++0x -fabi-version=0 -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


