CC=/usr/local/gcc-4.5.2-for-linux32/bin/i586-pc-linux-gcc
CXX=/usr/local/gcc-4.5.2-for-linux32/bin/i586-pc-linux-g++
ASM=/usr/local/gcc-4.5.2-for-linux32/bin/i586-pc-linux-gcc
LD=/usr/local/gcc-4.5.2-for-linux32/bin/i586-pc-linux-ld
EMU=/usr/local/bin/qemu
EMUTARGET=${TARGET}
GDB=gdb
SED=sed
OBJDUMP=objdump
DOCGEN=/Applications/Doxygen.app/Contents/Resources/doxygen

CFLAGS+=-fno-exceptions
CXXFLAGS+=${CFLAGS} -fno-rtti -nostdinc++
LDFLAGS=-e entry -T misc/sections -melf_i386

OBJDUMPFLAGS=-Cxd
EMUFLAGS+= -kernel
DEBUGFLAGS+=-s -S
GDBFLAGS+=-x misc/gdb.script

LDHEAD := $(shell $(CXX) --print-file-name=crti.o && $(CXX) --print-file-name=crtbegin.o)
LDTAIL := $(shell $(CXX) --print-file-name=crtend.o && $(CXX) --print-file-name=crtn.o)
