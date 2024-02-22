################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
middleware/src/%.obj: ../middleware/src/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --idiv_support=idiv0 --tmu_support=tmu0 --include_path="C:/Users/User/Desktop/BMS/Prototips/3/Code" --include_path="C:/ti/C2000Ware_5_00_00_00" --include_path="C:/Users/User/Desktop/BMS/Prototips/3/Code/device" --include_path="C:/ti/C2000Ware_5_00_00_00/driverlib/f28002x/driverlib" --include_path="C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=DEBUG --define=_FLASH --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="middleware/src/$(basename $(<F)).d_raw" --include_path="C:/Users/User/Desktop/BMS/Prototips/3/Code/CPU1_FLASH/syscfg" --obj_directory="middleware/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


