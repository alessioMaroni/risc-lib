CMAKE_BUILD_DIR         := ./.build
CMAKE_TOOLCHAIN_FILE    := cmake/toolchains/rv32-toolchain.cmake
CMAKE_TEST_LIB_OBJ      := $(CMAKE_BUILD_DIR)/CMakeFiles/riscvlib_tests.dir/tests/toolchain/lib_test.c.obj
CMAKE_APP_ELF           := $(CMAKE_BUILD_DIR)/riscvlib_app

.PHONY: clean
clean:
	rm -rf $(CMAKE_BUILD_DIR)

.PHONY: verify_test_lib
verify_test_lib:
	@echo "Verifying library..."
	file $(CMAKE_TEST_LIB_OBJ)

.PHONY: build_test
build_test:
	@echo "Building library..."
	@if [ ! -f $(CMAKE_BUILD_DIR)/CMakeCache.txt ]; then \
		cmake -S . -B $(CMAKE_BUILD_DIR) -DCMAKE_TOOLCHAIN_FILE=$(CMAKE_TOOLCHAIN_FILE); \
	fi
	cmake --build $(CMAKE_BUILD_DIR) --target riscvlib_tests

.PHONY: build_app
build_app:
	@echo "Building bare-metal app..."
	@if [ ! -f $(CMAKE_BUILD_DIR)/CMakeCache.txt ]; then \
		cmake -S . -B $(CMAKE_BUILD_DIR) -DCMAKE_TOOLCHAIN_FILE=$(CMAKE_TOOLCHAIN_FILE); \
	fi
	cmake --build $(CMAKE_BUILD_DIR) --target riscvlib_app

.PHONY: verify_app
verify_app:
	@echo "Verifying bare-metal ELF..."
	file $(CMAKE_APP_ELF)
	riscv64-linux-gnu-objdump -h $(CMAKE_APP_ELF)

.PHONY: run_app
run_app: build_app
	qemu-system-riscv32 -machine virt -nographic -bios none -kernel $(CMAKE_APP_ELF)