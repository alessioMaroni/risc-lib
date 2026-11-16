CMAKE_BUILD_DIR:= ./.build

CSR_PERL_GENERATED:= include/riscv/csr_def.h
CSR_PERL:= codegen/csr.pl

.PHONY: clean
clean:
	rm -rf	$(CMAKE_BUILD_DIR)
	rm 		$(CSR_PERL_GENERATED)

build:
	perl $(CSR_PERL)