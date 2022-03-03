
CC = g++

BIN_PATH = ./bin
SRC_PATH = ./src
INCLIUDE_PATH = ./include
ARGS = -std=c++11 -Wall -I ${INCLIUDE_PATH}
VPATH += ${SRC_PATH} ${INCLIUDE_PATH} ${BIN_PATH}
_OBJS = number.o formula.o

main = ${SRC_PATH}/main.cpp
EXE_FILE = main

OBJS = ${patsubst %.o, ${BIN_PATH}/%.o, ${_OBJS}}

.PHONY:all

all: ${OBJS}
	${CC} ${ARGS} -o ${EXE_FILE} ${OBJS} ${main}


${BIN_PATH}/%.o: 
	-@mkdir "${BIN_PATH}"
	${CC} ${ARGS} -c -o ${BIN_PATH}/$*.o ${SRC_PATH}/$*.cpp



number.o: number.cpp number.h
formula.o: formula.cpp formula.h