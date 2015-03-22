################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../kl_lib/SimpleSensors.cpp \
../kl_lib/clocking_L1xx.cpp \
../kl_lib/keys.cpp \
../kl_lib/kl_lib_L15x.cpp \
../kl_lib/uart.cpp 

C_SRCS += \
../kl_lib/kl_sprintf.c 

OBJS += \
./kl_lib/SimpleSensors.o \
./kl_lib/clocking_L1xx.o \
./kl_lib/keys.o \
./kl_lib/kl_lib_L15x.o \
./kl_lib/kl_sprintf.o \
./kl_lib/uart.o 

C_DEPS += \
./kl_lib/kl_sprintf.d 

CPP_DEPS += \
./kl_lib/SimpleSensors.d \
./kl_lib/clocking_L1xx.d \
./kl_lib/keys.d \
./kl_lib/kl_lib_L15x.d \
./kl_lib/uart.d 


# Each subdirectory must supply rules for building sources it contributes
kl_lib/%.o: ../kl_lib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../os -I../os/hal -I../os/kernel/include -I../kl_lib -I.././ -std=gnu++0x -fabi-version=0 -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

kl_lib/%.o: ../kl_lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../os -I../os/hal -I../os/kernel/include -I.././ -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


