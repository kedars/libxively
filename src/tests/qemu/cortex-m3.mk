A := cortex-m3

CC := arm-none-eabi-gcc
AR := arm-none-eabi-ar
LD := arm-none-eabi-ld

QEMU_CFLAGS := -mcpu=$A -mthumb -g -DXI_USER_AGENT='"qemu-$A"' -DNEVER_FORK
#QEMU_LDFLAGS := -Ttext=0x0 -Tdata=0x20000000
QEMU_LDFLAGS := -T generic-hosted.ld

XI_COMM_LAYER := dummy
XI_EXTRA_CFLAGS := $(QEMU_CFLAGS)

XI_OBJDIR := $(CURDIR)/$A.obj


export CC AR LD XI_COMM_LAYER XI_EXTRA_CFLAGS XI_BINDIR XI_OBJDIR

unit.$A.elf: $(CURDIR)/$A.obj/libxively.a
	$(CC) $(QEMU_CFLAGS) $(QEMU_LDFLAGS) \
		-I../../../src/libxively \
		-I../../ext/tinytest/ \
		../unit/main.c ../../ext/tinytest/tinytest.c $^ -o $@

$(CURDIR)/$A.obj/libxively.a: libxively

libxively:
	$(MAKE) -C ../../ $@

clean:
	$(RM) -rf $(XI_OBJDIR) unit.$A.elf

#$(XI_OBJDIR)/unit.o: $(CURDIR)/$A.obj/libxively.a
#	$(CC) $(QEMU_CCFLAGS) -I../../../src/libxively -I../../ext/tinytest/ ../unit/main.c $^ -o $@
#
#unit.$A.elf: $(XI_OBJDIR)/unit.o
#	$(LD) $(QEMU_LDFLAGS) $^ -o $@

