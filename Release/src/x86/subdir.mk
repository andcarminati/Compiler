################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/x86/assembler.c \
../src/x86/x86code_generator.c 

OBJS += \
./src/x86/assembler.o \
./src/x86/x86code_generator.o 

C_DEPS += \
./src/x86/assembler.d \
./src/x86/x86code_generator.d 


# Each subdirectory must supply rules for building sources it contributes
src/x86/%.o: ../src/x86/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


