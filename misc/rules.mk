BUILD=./build
BIN=./bin
SRC=./src
SRCASM=${SRC}/asm
DOC=./doc
INCLUDE=./include

CXX:=@${CXX}
CC:=@${CC}
ASM:=@${ASM}
LD:=@${LD}
EMU:=@${EMU}
SED:=@${SED}
OBJDUMP:=@${OBJDUMP}

SOURCES   = ${SRCASM}/boot.S $(filter-out ${SRCASM}/boot.S, $(wildcard ${SRC}/*/*.cc ${SRC}/*.cc ${SRC}/*/*.c ${SRCASM}/*.S ))
HEADERS  := $(filter %.h, $(wildcard ${INCLUDE}/*/*.h))
DOXS     := $(wildcard ${DOC}/*.dox)
DEPS     := $(addprefix ${BUILD}/,$(addsuffix .d,$(basename $(notdir ${SOURCES}))))
SYSTEM_OBJECTS:=$(addprefix ${BUILD}/,$(filter-out ${OBJECT_IGNORE}, $(addsuffix .o,$(basename $(notdir ${SOURCES})))))
OBJECTS  := ${LDHEAD} ${SYSTEM_OBJECTS} ${LDTAIL}
TARGET   := ${BIN}/${TARGET}
EMTARGET := ${BIN}/${EMUTARGET}
INCPATHS := $(addprefix -I,${INCLUDE} ${INCPATHS})
LIBPATHS := $(addprefix -L,${LIBPATHS})
LIBS     := $(addprefix -l,${LIBS})
ASMFLAGS := $(foreach VAR, ${ASMFLAGS}, -Wa,${VAR})
GARBAGE   = $(wildcard *~ *.sw?) ${BIN} ${BUILD} ${DOC}/html ${DOC}/log $(wildcard *.dump)

.PHONY: all clean run debug doc dump

all: ${TARGET}

${TARGET}: ${OBJECTS} | ${BIN}
	@echo "(LD   ) $@ <- [$(notdir ${SYSTEM_OBJECTS})]"
	${LD} ${LDFLAGS} ${OBJECTS} -o $@

${BUILD}/%.o: ${SRC}/*/%.cc ${BUILD}/%.d Makefile | ${BUILD}
	@echo "(CXX  ) $@ <- $<"
	${CXX} -c ${CXXFLAGS} $< ${INCPATHS} -o $@

${BUILD}/%.o: ${SRC}/*/%.c ${BUILD}/%.d Makefile | ${BUILD}
	@echo "(CXX  ) $@ <- $<"
	${CC} -c ${CFLAGS} $< ${INCPATHS} -o $@

${BUILD}/%.o: ${SRC}/%.cc ${BUILD}/%.d Makefile | ${BUILD}
	@echo "(CC   ) $@ <- $<"
	${CXX} -c ${CXXFLAGS} $< ${INCPATHS} -o $@

${BUILD}/%.o: ${SRCASM}/%.S  Makefile | ${BUILD}
	@echo "(ASM  ) $@ <- $<"
	${CC} -c ${ASMFLAGS} $< ${INCPATHS} -o $@

${BUILD}/%.d: ${SRCASM}/%.S | ${BUILD}
	${CC} -M ${ASMFLAGS} $< ${INCPATHS}  -o $@.temp
	${SED} "s!\($(notdir $(basename $@)).o\)!${BUILD}/\1!g" $@.temp > $@
	@rm -f $@.temp

${BUILD}/%.d: ${SRC}/*/%.cc | ${BUILD}
	${CXX} -M ${CXXFLAGS} $< ${INCPATHS} -o $@.temp
	${SED} "s!\($(notdir $(basename $@)).o\)!${BUILD}/\1!g" $@.temp > $@
	@rm -f $@.temp

${BUILD}/%.d: ${SRC}/*/%.c | ${BUILD}
	${CC} -M ${CFLAGS} $< ${INCPATHS} -o $@.temp
	${SED} "s!\($(notdir $(basename $@)).o\)!${BUILD}/\1!g" $@.temp > $@
	@rm -f $@.temp

${BUILD}/%.d: ${SRC}/%.cc | ${BUILD}
	${CXX} -M ${CXXFLAGS} $< ${INCPATHS} -o $@.temp
	${SED} "s!\($(notdir $(basename $@)).o\)!${BUILD}/\1!g" $@.temp > $@
	@rm -f $@.temp

dump: $(notdir ${TARGET}).dump

$(notdir ${TARGET}).dump: ${TARGET}
	@echo "(DUMP ) $@ <- $<"
	${OBJDUMP} ${OBJDUMPFLAGS} $< > $@

%.dump:	${BUILD}/%.o
	@echo "(DUMP ) $@ <- $<"
	${OBJDUMP} ${OBJDUMPFLAGS} $< > $@

${BIN} ${BUILD}:
	@mkdir -p $@

clean:
	@echo "(CLEAN)"
	@rm -rf ${GARBAGE}

run: ${EMUTARGET}
	@echo "(EMU  )"
	${EMU} ${EMUFLAGS} $< 

debug: ${TARGET}
	@echo "(DEBUG)"
	${EMU} ${EMUFLAGS} $< ${EMUDEBUG} -S -s & sleep 1 && ${GDB} ${TARGET} ${GDBFLAGS}

doc: ${DOC}/html/index.html
	
${DOC}/html/index.html: ${DOC}/Doxyfile ${DOXS} ${SOURCES} ${HEADERS}
	@echo "(DOC  )"
	@${DOCGEN} $< > ${DOC}/log

-include ${DEPS}
