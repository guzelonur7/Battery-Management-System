################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-1579775777: ../Battery_Management_System.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs1230/ccs/utils/sysconfig_1.16.1/sysconfig_cli.bat" -s "C:/ti/C2000Ware_5_00_00_00/.metadata/sdk.json" -d "F28002x" --script "C:/Users/User/Desktop/BMS/Prototips/3/Code/Battery_Management_System.syscfg" -o "syscfg" --package 80QFP --part F28002x_80QFP --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-1579775777 ../Battery_Management_System.syscfg
syscfg/board.h: build-1579775777
syscfg/board.cmd.genlibs: build-1579775777
syscfg/board.opt: build-1579775777
syscfg/pinmux.csv: build-1579775777
syscfg/adc.dot: build-1579775777
syscfg/c2000ware_libraries.cmd.genlibs: build-1579775777
syscfg/c2000ware_libraries.opt: build-1579775777
syscfg/c2000ware_libraries.c: build-1579775777
syscfg/c2000ware_libraries.h: build-1579775777
syscfg/clocktree.h: build-1579775777
syscfg/: build-1579775777

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --idiv_support=idiv0 --tmu_support=tmu0 -Ooff --include_path="C:/Users/User/Desktop/BMS/Prototips/3/Code" --include_path="C:/ti/C2000Ware_5_00_00_00" --include_path="C:/Users/User/Desktop/BMS/Prototips/3/Code/device" --include_path="C:/ti/C2000Ware_5_00_00_00/driverlib/f28002x/driverlib" --include_path="C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/User/Desktop/BMS/Prototips/3/Code/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --idiv_support=idiv0 --tmu_support=tmu0 -Ooff --include_path="C:/Users/User/Desktop/BMS/Prototips/3/Code" --include_path="C:/ti/C2000Ware_5_00_00_00" --include_path="C:/Users/User/Desktop/BMS/Prototips/3/Code/device" --include_path="C:/ti/C2000Ware_5_00_00_00/driverlib/f28002x/driverlib" --include_path="C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/User/Desktop/BMS/Prototips/3/Code/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


