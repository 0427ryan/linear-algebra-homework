
CC = g++

BIN_PATH = ./bin
SRC_PATH = ./src
INCLIUDE_PATH = ./include
ARGS = -std=c++11 -Wall -I ${INCLIUDE_PATH}
VPATH += ${SRC_PATH} ${INCLIUDE_PATH} ${BIN_PATH}
OBJS = number.o formula.o

.PHONY:all

all: ${OBJS}
	${CC} ${ARGS} -B"${BIN_PATH}";"${SRC_PATH}" -o main ${OBJS} main.cpp


%.o: 
	-@mkdir "${BIN_PATH}"
	${CC} ${ARGS} -c -o ${BIN_PATH}/$*.o ${SRC_PATH}/$*.cpp



number.o: number.cpp number.h
formula.o: formula.cpp formula.h