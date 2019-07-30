################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Seg_LCD.c \
../source/final_project.c \
../source/interruptFunc.c \
../source/mtb.c \
../source/semihost_hardfault.c \
../source/time.c \
../source/tpmTimer.c 

OBJS += \
./source/Seg_LCD.o \
./source/final_project.o \
./source/interruptFunc.o \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/time.o \
./source/tpmTimer.o 

C_DEPS += \
./source/Seg_LCD.d \
./source/final_project.d \
./source/interruptFunc.d \
./source/mtb.d \
./source/semihost_hardfault.d \
./source/time.d \
./source/tpmTimer.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL46Z256VLL4_cm0plus -DCPU_MKL46Z256VLL4 -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I../board -I../source -I../ -I../drivers -I../CMSIS -I../utilities -I../startup -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


