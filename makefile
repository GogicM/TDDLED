all: unity LedDriver_Test main

.PHONY: all unity LedDriver_Test

unity:
	$(MAKE) -C unity all

LedDriver_Test:
	$(MAKE) -C tests all

main:
	$(MAKE) -C build all

