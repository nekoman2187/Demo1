################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

-include makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/wolfDemo/subdir.mk
-include src/smc_gen/r_t4_rx/src/subdir.mk
-include src/smc_gen/r_t4_driver_rx/src/subdir.mk
-include src/smc_gen/r_sys_time_rx/src/subdir.mk
-include src/smc_gen/r_pincfg/subdir.mk
-include src/smc_gen/r_ether_rx/src/targets/rx72n/subdir.mk
-include src/smc_gen/r_ether_rx/src/phy/subdir.mk
-include src/smc_gen/r_ether_rx/src/subdir.mk
-include src/smc_gen/r_cmt_rx/src/subdir.mk
-include src/smc_gen/r_bsp/mcu/rx72n/subdir.mk
-include src/smc_gen/r_bsp/mcu/all/subdir.mk
-include src/smc_gen/r_bsp/board/generic_rx72n/subdir.mk
-include src/smc_gen/general/subdir.mk
-include src/r_t4_dns_client_rx/src/subdir.mk
-include src/r_socket_rx_v1.32/r_socket_rx/src/subdir.mk
-include src/T4_src/checksum/rx_gcc/subdir.mk
-include src/T4_src/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(JMP_DEPS)),)
-include $(JMP_DEPS)
endif
ifneq ($(strip $(FSY_DEPS)),)
-include $(FSY_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(SRC_UPPER_DEPS)),)
-include $(SRC_UPPER_DEPS)
endif
ifneq ($(strip $(P_UPPER_DEPS)),)
-include $(P_UPPER_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(PP_UPPER_DEPS)),)
-include $(PP_UPPER_DEPS)
endif
ifneq ($(strip $(P_DEPS)),)
-include $(P_DEPS)
endif
ifneq ($(strip $(FSY_UPPER_DEPS)),)
-include $(FSY_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SRC_DEPS)),)
-include $(SRC_DEPS)
endif
ifneq ($(strip $(JMP_UPPER_DEPS)),)
-include $(JMP_UPPER_DEPS)
endif
ifneq ($(strip $(PP_DEPS)),)
-include $(PP_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif
ifneq ($(strip $(SX_UPPER_DEPS)),)
-include $(SX_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS += \

OBJCOPY += \
WolfSSLDemo.mot \

PRINT_SIZE += \
WolfSSLDemo.siz \


# All Target
all: WolfSSLDemo.elf secondary-outputs

# Tool invocations
WolfSSLDemo.elf: $(OBJS) $(USER_OBJS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) $(LINKER_SCRIPT)
	$(file > WolfSSLDemo.elf.in,-O0 -ffunction-sections -fdata-sections -fdiagnostics-parseable-fixits -Wstack-usage=100 -g2 -mcpu=rx72t -misa=v3 -mlittle-endian-data -o "WolfSSLDemo.elf" $(OBJS) $(USER_OBJS) $(LIBS) -T "D:/ORG/WolfSSLDemo/src/linker_script.ld" -L"D:\\ORG\\WolfSSLDemo\\src\\smc_gen\\r_t4_rx\\lib\\ccrx" -Wl,--start-group -lm -lc -lgcc -lwolflib -lT4_Library_ether_ccrx_rxv1_little -lasp -Wl,--end-group -nostartfiles -Wl,-e_PowerON_Reset -Wl,-M=WolfSSLDemo.map)
	@echo Building target: $@ && rx-elf-gcc @"WolfSSLDemo.elf.in"
: 
	rx-elf-libgen  --select-lib=newlib --compiler-options=-O0,-ffunction-sections,-fdata-sections,-mcpu=rx72t,-misa=v3,-mlittle-endian-data --assembler-options=-mlittle-endian-data -o
WolfSSLDemo.mot: WolfSSLDemo.elf
	rx-elf-objcopy "WolfSSLDemo.elf" -O srec -I elf32-rx-be-ns  "WolfSSLDemo.mot"
WolfSSLDemo.siz: WolfSSLDemo.elf
	rx-elf-size --format=berkeley "WolfSSLDemo.elf"
# Other Targets
clean:
	-$(file > clean_file.tmp,  $(PRINT_SIZE)  $(JMP_DEPS)  $(FSY_DEPS)  $(C_UPPER_DEPS)  $(SRC_UPPER_DEPS)  $(P_UPPER_DEPS)  $(LST)  $(S_DEPS)  $(PP_UPPER_DEPS)  $(P_DEPS)  $(FSY_UPPER_DEPS)  $(C_DEPS)  $(SRC_DEPS)  $(OBJCOPY)  $(JMP_UPPER_DEPS)  $(PP_DEPS)  $(ASM_UPPER_DEPS)  $(SX_DEPS)  $(OBJS)  $(SX_UPPER_DEPS)  $(ASM_DEPS)  $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS)  $(MAP)  $(S_UPPER_DEPS) )
	-@ xargs -P 2 -s 32000 -t -a clean_file.tmp $(RM)
	-@$(RM) clean_file.tmp
	-$(RM)  WolfSSLDemo.elf
	-@echo ' '

secondary-outputs: $(OBJCOPY) $(PRINT_SIZE)

.PHONY: all clean dependents 

-include ../makefile.targets
