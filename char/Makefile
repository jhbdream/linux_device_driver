export CROSS_COMPILE=
export ARCH=x86
CONFIG_MODULE_SIG=n

KVERS = $(shell uname -r)

obj-m += char.o

build: kernel_modules

kernel_modules:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) modules

clean:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) clean