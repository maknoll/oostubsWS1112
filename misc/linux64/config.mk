CC = i586-pc-linux-gcc
CXX = i586-pc-linux-g++
ASM = i586-pc-linux-gcc
LD = i586-pc-linux-ld
EMU=qemu
EMUTARGET=${TARGET}
GDB=gdb
SED=sed
OBJDUMP=objdump
DOCGEN=doxygen

CFLAGS+=-fno-exceptions -m32 -fno-stack-protector
CXXFLAGS+=${CFLAGS} -fno-rtti -nostdinc++
LDFLAGS=-e entry -T misc/sections -melf_i386
ASMFLAGS=

OBJDUMPFLAGS=-Cxd
EMUFLAGS+= -kernel
DEBUGFLAGS+=-s -S
GDBFLAGS+=-x misc/gdb.script

LDHEAD := $(addprefix misc/linux64/build/, crti.o crtbegin.o)
LDTAIL := $(addprefix misc/linux64/build/, crtend.o crtn.o)
