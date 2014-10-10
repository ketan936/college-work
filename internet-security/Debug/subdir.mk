################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ceasar.cpp \
../railfence.cpp \
../some_cipher.cpp \
../transpose.cpp 

OBJS += \
./ceasar.o \
./railfence.o \
./some_cipher.o \
./transpose.o 

CPP_DEPS += \
./ceasar.d \
./railfence.d \
./some_cipher.d \
./transpose.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


