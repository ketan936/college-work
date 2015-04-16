obj-m += hello_world.o

#KDIR is the environment variable
ifndef KDIR
KDIR = /usr/src/linux-headers-$(shell uname -r)
endif

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order