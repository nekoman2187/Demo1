################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../src/T4_src/checksum/rx_gcc/cksum_rx_gcc_little.asm 

LST += \
cksum_rx_gcc_little.lst 

OBJS += \
./src/T4_src/checksum/rx_gcc/cksum_rx_gcc_little.o 

ASM_DEPS += \
./src/T4_src/checksum/rx_gcc/cksum_rx_gcc_little.d 

MAP += \
WolfSSLDemo.map 


# Each subdirectory must supply rules for building sources it contributes
src/T4_src/checksum/rx_gcc/%.o: ../src/T4_src/checksum/rx_gcc/%.asm
	@echo 'Building file: $<'
	$(file > $@.in,-O0 -ffunction-sections -fdata-sections -fdiagnostics-parseable-fixits -Wstack-usage=100 -g2 -mcpu=rx72t -misa=v3 -mlittle-endian-data -x assembler-with-cpp -Wa,--gdwarf2 -I"D:/ORG/WolfSSLDemo/src" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\general" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_pincfg" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_bsp" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_config" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_ether_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_driver_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_driver_rx\\src" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_rx\\lib" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_cmt_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_cmt_rx\\src" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_sys_time_rx" -I"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_sys_time_rx\\src" -Wa,-adlhn="$(basename $(notdir $<)).lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c "$<" -o "$@")
	@echo $< && rx-elf-gcc @"$@.in"

