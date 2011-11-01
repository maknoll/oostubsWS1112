CROSS_GCC_PATH=/local/apps/cross-gcc/bin

CC=${CROSS_GCC_PATH}/i386-elf-gcc
CXX=${CROSS_GCC_PATH}/i386-elf-g++
ASM=${CROSS_GCC_PATH}/i386-elf-gcc
LD=${CROSS_GCC_PATH}/i386-elf-ld
EMU=qemu
EMUTARGET=${TARGET}.iso
GDB=${CROSS_GCC_PATH}/i386-elf-gdb
SED=gsed
OBJDUMP=${CROSS_GCC_PATH}/i386-elf-objdump
DOCGEN=doxygen

CFLAGS+=-fno-exceptions
CXXFLAGS+=${CFLAGS} -fno-rtti -nostdinc++
LDFLAGS=-e entry -T misc/sections

OBJDUMPFLAGS=-Cxd
EMUFLAGS+=-L /local/usr/x86_64/share/qemu -boot d -cdrom 
DEBUGFLAGS+=-s -S
GDBFLAGS+=-x misc/gdb.script

LDHEAD := $(addprefix misc/sunpool/build/,crti.o crtbegin.o)
LDTAIL := $(addprefix misc/sunpool/build/,crtend.o crtn.o)
