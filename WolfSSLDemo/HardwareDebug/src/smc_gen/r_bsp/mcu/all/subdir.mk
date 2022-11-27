################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../src/smc_gen/r_bsp/mcu/all/reset_program.S 

C_SRCS += \
../src/smc_gen/r_bsp/mcu/all/dbsct.c \
../src/smc_gen/r_bsp/mcu/all/lowlvl.c \
../src/smc_gen/r_bsp/mcu/all/lowsrc.c \
../src/smc_gen/r_bsp/mcu/all/mcu_locks.c \
../src/smc_gen/r_bsp/mcu/all/r_bsp_common.c \
../src/smc_gen/r_bsp/mcu/all/r_bsp_cpu.c \
../src/smc_gen/r_bsp/mcu/all/r_bsp_interrupts.c \
../src/smc_gen/r_bsp/mcu/all/r_bsp_locking.c \
../src/smc_gen/r_bsp/mcu/all/r_bsp_mcu_startup.c \
../src/smc_gen/r_bsp/mcu/all/r_bsp_software_interrupt.c \
../src/smc_gen/r_bsp/mcu/all/r_rx_intrinsic_functions.c \
../src/smc_gen/r_bsp/mcu/all/resetprg.c \
../src/smc_gen/r_bsp/mcu/all/sbrk.c 

LST += \
dbsct.lst \
lowlvl.lst \
lowsrc.lst \
mcu_locks.lst \
r_bsp_common.lst \
r_bsp_cpu.lst \
r_bsp_interrupts.lst \
r_bsp_locking.lst \
r_bsp_mcu_startup.lst \
r_bsp_software_interrupt.lst \
r_rx_intrinsic_functions.lst \
reset_program.lst \
resetprg.lst \
sbrk.lst 

C_DEPS += \
./src/smc_gen/r_bsp/mcu/all/dbsct.d \
./src/smc_gen/r_bsp/mcu/all/lowlvl.d \
./src/smc_gen/r_bsp/mcu/all/lowsrc.d \
./src/smc_gen/r_bsp/mcu/all/mcu_locks.d \
./src/smc_gen/r_bsp/mcu/all/r_bsp_common.d \
./src/smc_gen/r_bsp/mcu/all/r_bsp_cpu.d \
./src/smc_gen/r_bsp/mcu/all/r_bsp_interrupts.d \
./src/smc_gen/r_bsp/mcu/all/r_bsp_locking.d \
./src/smc_gen/r_bsp/mcu/all/r_bsp_mcu_startup.d \
./src/smc_gen/r_bsp/mcu/all/r_bsp_software_interrupt.d \
./src/smc_gen/r_bsp/mcu/all/r_rx_intrinsic_functions.d \
./src/smc_gen/r_bsp/mcu/all/resetprg.d \
./src/smc_gen/r_bsp/mcu/all/sbrk.d 

OBJS += \
./src/smc_gen/r_bsp/mcu/all/dbsct.o \
./src/smc_gen/r_bsp/mcu/all/lowlvl.o \
./src/smc_gen/r_bsp/mcu/all/lowsrc.o \
./src/smc_gen/r_bsp/mcu/all/mcu_locks.o \
./src/smc_gen/r_bsp/mcu/all/r_bsp_common.o \
./src/smc_gen/r_bsp/mcu/all/r_bsp_cpu.o \
./src/smc_gen/r_bsp/mcu/all/r_bsp_interrupts.o \
./src/smc_gen/r_bsp/mcu/all/r_bsp_locking.o \
./src/smc_gen/r_bsp/mcu/all/r_bsp_mcu_startup.o \
./src/smc_gen/r_bsp/mcu/all/r_bsp_software_interrupt.o \
./src/smc_gen/r_bsp/mcu/all/r_rx_intrinsic_functions.o \
./src/smc_gen/r_bsp/mcu/all/reset_program.o \
./src/smc_gen/r_bsp/mcu/all/resetprg.o \
./src/smc_gen/r_bsp/mcu/all/sbrk.o 

MAP += \
WolfSSLDemo.map 

S_UPPER_DEPS += \
./src/smc_gen/r_bsp/mcu/all/reset_program.d 


# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/r_bsp/mcu/all/%.o: ../src/smc_gen/r_bsp/mcu/all/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-O0 -ffunction-sections -fdata-sections -fdiagnostics-parseable-fixits -Wstack-usage=100 -g2 -mcpu=rx72t -misa=v3 -mlittle-endian-data -std=gnu99 -I"D:\\ORG\\WolfSSLDemo\\src\\wolfssl" -I"D:\\ORG\\WolfSSLDemo\\src\\r_socket_rx_v1.32\\r_socket_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\r_socket_rx_v1.32\\r_config" -I"D:\\ORG\\WolfSSLDemo\\src\\r_t4_dns_client_rx" -I"D:\\ORG\\WolfSSLDemo\\src" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\general" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_pincfg" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_bsp" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_config" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_ether_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_driver_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_driver_rx\\src" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_rx\\lib" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_cmt_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_cmt_rx\\src" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_sys_time_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_sys_time_rx\\src" -DWOLFSSL_USER_SETTINGS -DDEBUG_WOLFSSL -Wa,-adlnh="$(basename $(notdir $<)).lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" "$<" -c -o "$@")
	@echo $< && rx-elf-gcc @"$@.in"
src/smc_gen/r_bsp/mcu/all/%.o: ../src/smc_gen/r_bsp/mcu/all/%.S
	@echo 'Building file: $<'
	$(file > $@.in,-O0 -ffunction-sections -fdata-sections -fdiagnostics-parseable-fixits -Wstack-usage=100 -g2 -mcpu=rx72t -misa=v3 -mlittle-endian-data -x assembler-with-cpp -Wa,--gdwarf2 -I"D:/ORG/WolfSSLDemo/src" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\general" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_pincfg" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_bsp" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_config" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_ether_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_driver_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_driver_rx\\src" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_rx\\lib" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_cmt_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_cmt_rx\\src" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_sys_time_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_sys_time_rx\\src" -Wa,-adlhn="$(basename $(notdir $<)).lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c "$<" -o "$@")
	@echo $< && rx-elf-gcc @"$@.in"

