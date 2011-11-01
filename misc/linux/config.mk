CC=gcc
CXX=g++
ASM=gcc
LD=ld
EMU=qemu
EMUTARGET=${TARGET}
GDB=gdb
SED=sed
OBJDUMP=objdump
DOCGEN=doxygen

CFLAGS+=-fno-exceptions
CXXFLAGS+=${CFLAGS} -fno-rtti -nostdinc++
LDFLAGS=-e entry -T misc/sections

OBJDUMPFLAGS=-Cxd
EMUFLAGS+=-no-kvm -kernel
DEBUGFLAGS+=-s -S
GDBFLAGS+=-x misc/gdb.script

LDHEAD := $(shell $(CXX) --print-file-name=crti.o && $(CXX) --print-file-name=crtbegin.o)
LDTAIL := $(shell $(CXX) --print-file-name=crtend.o && $(CXX) --print-file-name=crtn.o)
