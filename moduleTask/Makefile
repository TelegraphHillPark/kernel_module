obj-m += moduleTask.o

KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

MODULE_NAME = moduleTask
CONFIG_FILE = progTask/parameters.conf

all:
	make -C $(KERNELDIR) M=$(PWD) modules

clean:
	make -C $(KERNELDIR) M=$(PWD) clean

load:
	insmod $(MODULE_NAME).ko filename=`grep -oP 'filename="\K[^"]+' $(CONFIG_FILE)` \
		interval=`grep -oP 'interval=\K\d+' $(CONFIG_FILE)`

unload:
	rmmod $(MODULE_NAME)
