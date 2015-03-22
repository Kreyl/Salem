################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../os/hal/hal_lld.cpp 

C_SRCS += \
../os/hal/chcore.c \
../os/hal/chcore_v7m.c \
../os/hal/crt0.c \
../os/hal/hal.c \
../os/hal/nvic.c \
../os/hal/stm32_dma.c \
../os/hal/vectors.c 

OBJS += \
./os/hal/chcore.o \
./os/hal/chcore_v7m.o \
./os/hal/crt0.o \
./os/hal/hal.o \
./os/hal/hal_lld.o \
./os/hal/nvic.o \
./os/hal/stm32_dma.o \
./os/hal/vectors.o 

C_DEPS += \
./os/hal/chcore.d \
./os/hal/chcore_v7m.d \
./os/hal/crt0.d \
./os/hal/hal.d \
./os/hal/nvic.d \
./os/hal/stm32_dma.d \
./os/hal/vectors.d 

CPP_DEPS += \
./os/hal/hal_lld.d 


# Each subdirectory must supply rules for building sources it contributes
os/hal/%.o: ../os/hal/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../os -I../os/hal -I../os/kernel/include -I.././ -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

os/hal/%.o: ../os/hal/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../os -I../os/hal -I../os/kernel/include -I../kl_lib -I.././ -std=gnu++0x -fabi-version=0 -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


