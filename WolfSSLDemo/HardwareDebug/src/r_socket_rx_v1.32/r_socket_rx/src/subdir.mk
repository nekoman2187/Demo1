################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/r_socket_rx_v1.32/r_socket_rx/src/r_socket.c \
../src/r_socket_rx_v1.32/r_socket_rx/src/r_socket_par_check.c 

LST += \
r_socket.lst \
r_socket_par_check.lst 

C_DEPS += \
./src/r_socket_rx_v1.32/r_socket_rx/src/r_socket.d \
./src/r_socket_rx_v1.32/r_socket_rx/src/r_socket_par_check.d 

OBJS += \
./src/r_socket_rx_v1.32/r_socket_rx/src/r_socket.o \
./src/r_socket_rx_v1.32/r_socket_rx/src/r_socket_par_check.o 

MAP += \
WolfSSLDemo.map 


# Each subdirectory must supply rules for building sources it contributes
src/r_socket_rx_v1.32/r_socket_rx/src/%.o: ../src/r_socket_rx_v1.32/r_socket_rx/src/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-O0 -ffunction-sections -fdata-sections -fdiagnostics-parseable-fixits -Wstack-usage=100 -g2 -mcpu=rx72t -misa=v3 -mlittle-endian-data -std=gnu99 -I"D:\\ORG\\WolfSSLDemo\\src\\wolfssl" -I"D:\\ORG\\WolfSSLDemo\\src\\r_socket_rx_v1.32\\r_socket_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\r_socket_rx_v1.32\\r_config" -I"D:\\ORG\\WolfSSLDemo\\src\\r_t4_dns_client_rx" -I"D:\\ORG\\WolfSSLDemo\\src" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\general" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_pincfg" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_bsp" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_config" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_ether_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_driver_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_driver_rx\\src" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_rx\\lib" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_cmt_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_cmt_rx\\src" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_sys_time_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_sys_time_rx\\src" -DWOLFSSL_USER_SETTINGS -DDEBUG_WOLFSSL -Wa,-adlnh="$(basename $(notdir $<)).lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" "$<" -c -o "$@")
	@echo $< && rx-elf-gcc @"$@.in"

