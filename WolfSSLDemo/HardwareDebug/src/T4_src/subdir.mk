################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/T4_src/T4_Version.c \
../src/T4_src/dhcp.c \
../src/T4_src/ether.c \
../src/T4_src/igmp.c \
../src/T4_src/ip.c \
../src/T4_src/tcp.c \
../src/T4_src/tcp_api.c \
../src/T4_src/udp.c 

LST += \
T4_Version.lst \
dhcp.lst \
ether.lst \
igmp.lst \
ip.lst \
tcp.lst \
tcp_api.lst \
udp.lst 

C_DEPS += \
./src/T4_src/T4_Version.d \
./src/T4_src/dhcp.d \
./src/T4_src/ether.d \
./src/T4_src/igmp.d \
./src/T4_src/ip.d \
./src/T4_src/tcp.d \
./src/T4_src/tcp_api.d \
./src/T4_src/udp.d 

OBJS += \
./src/T4_src/T4_Version.o \
./src/T4_src/dhcp.o \
./src/T4_src/ether.o \
./src/T4_src/igmp.o \
./src/T4_src/ip.o \
./src/T4_src/tcp.o \
./src/T4_src/tcp_api.o \
./src/T4_src/udp.o 

MAP += \
WolfSSLDemo.map 


# Each subdirectory must supply rules for building sources it contributes
src/T4_src/%.o: ../src/T4_src/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-O0 -ffunction-sections -fdata-sections -fdiagnostics-parseable-fixits -Wstack-usage=100 -g2 -mcpu=rx72t -misa=v3 -mlittle-endian-data -std=gnu99 -I"D:\\ORG\\WolfSSLDemo\\src\\wolfssl" -I"D:\\ORG\\WolfSSLDemo\\src\\r_socket_rx_v1.32\\r_socket_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\r_socket_rx_v1.32\\r_config" -I"D:\\ORG\\WolfSSLDemo\\src\\r_t4_dns_client_rx" -I"D:\\ORG\\WolfSSLDemo\\src" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\general" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_pincfg" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_bsp" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_config" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_ether_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_driver_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_driver_rx\\src" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_rx\\lib" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_cmt_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_cmt_rx\\src" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_sys_time_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_sys_time_rx\\src" -DWOLFSSL_USER_SETTINGS -DDEBUG_WOLFSSL -Wa,-adlnh="$(basename $(notdir $<)).lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" "$<" -c -o "$@")
	@echo $< && rx-elf-gcc @"$@.in"

