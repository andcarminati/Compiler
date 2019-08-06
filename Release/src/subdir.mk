################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/code_generator.c \
../src/error_report.c \
../src/lex.yy.c \
../src/list.c \
../src/main.c \
../src/semantic.c \
../src/sint.c \
../src/symbol_table.c 

OBJS += \
./src/code_generator.o \
./src/error_report.o \
./src/lex.yy.o \
./src/list.o \
./src/main.o \
./src/semantic.o \
./src/sint.o \
./src/symbol_table.o 

C_DEPS += \
./src/code_generator.d \
./src/error_report.d \
./src/lex.yy.d \
./src/list.d \
./src/main.d \
./src/semantic.d \
./src/sint.d \
./src/symbol_table.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


