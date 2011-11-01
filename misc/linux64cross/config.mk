CC=i686-pc-linux-gnu-gcc
CXX=i686-pc-linux-gnu-g++
ASM=i686-pc-linux-gnu-gcc
LD=i686-pc-linux-gnu-ld
EMU=qemu
EMUTARGET=${TARGET}
GDB=i686-pc-linux-gnu-gdb
SED=sed
OBJDUMP=i686-pc-linux-gnu-objdump
DOCGEN=doxygen

CFLAGS+=-fno-exceptions
CXXFLAGS+=${CFLAGS} -fno-rtti -nostdinc++
LDFLAGS=-e entry -T misc/sections
ASMFLAGS=

OBJDUMPFLAGS=-Cxd
EMUFLAGS+=-no-kvm -net none -vga std -kernel
DEBUGFLAGS+=-s -S
GDBFLAGS+=-x misc/gdb.script

LDHEAD := $(shell $(CXX) --print-file-name=crti.o && $(CXX) --print-file-name=crtbegin.o)
LDTAIL := $(shell $(CXX) --print-file-name=crtend.o && $(CXX) --print-file-name=crtn.o)
