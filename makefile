all: unity LedDriver LedDriver_Test main

.PHONY: all unity LedDriver LedDriver_Test

unity:
	$(MAKE) -C unity all

LedDriver_Test:
	$(MAKE) -C tests all

LedDriver:
	$(MAKE) -C src all

main:
	$(MAKE) -C build all

