################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/STM32_USB_Host_Library/Class/Template/Src/usbh_template.c 

OBJS += \
./Middlewares/ST/STM32_USB_Host_Library/Class/Template/Src/usbh_template.o 

C_DEPS += \
./Middlewares/ST/STM32_USB_Host_Library/Class/Template/Src/usbh_template.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/STM32_USB_Host_Library/Class/Template/Src/%.o Middlewares/ST/STM32_USB_Host_Library/Class/Template/Src/%.su Middlewares/ST/STM32_USB_Host_Library/Class/Template/Src/%.cyclo: ../Middlewares/ST/STM32_USB_Host_Library/Class/Template/Src/%.c Middlewares/ST/STM32_USB_Host_Library/Class/Template/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I"D:/OneDrive/Documentos/Bus_Stop_Tracker/main-project/Drivers/BSP/Components/wm8994" -I../FATFS/Target -I../FATFS/App -I../USB_HOST/App -I../USB_HOST/Target -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Documentos/Bus_Stop_Tracker/main-project/Drivers/BSP/STM32746G-Discovery" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-STM32_USB_Host_Library-2f-Class-2f-Template-2f-Src

clean-Middlewares-2f-ST-2f-STM32_USB_Host_Library-2f-Class-2f-Template-2f-Src:
	-$(RM) ./Middlewares/ST/STM32_USB_Host_Library/Class/Template/Src/usbh_template.cyclo ./Middlewares/ST/STM32_USB_Host_Library/Class/Template/Src/usbh_template.d ./Middlewares/ST/STM32_USB_Host_Library/Class/Template/Src/usbh_template.o ./Middlewares/ST/STM32_USB_Host_Library/Class/Template/Src/usbh_template.su

.PHONY: clean-Middlewares-2f-ST-2f-STM32_USB_Host_Library-2f-Class-2f-Template-2f-Src

