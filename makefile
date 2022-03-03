
CC = g++

BIN_PATH = ./bin
SRC_PATH = ./src
INCLIUDE_PATH = ./include
ARGS = -std=c++11 -Wall -I ${INCLIUDE_PATH}
VPATH += ./${SRC_PATH} ./${INCLIUDE_PATH}
OBJS = 

%.o: 
	${CC} ${ARGS} -c ${SRC_PATH}/$*.cpp


number.o: number.cpp number.h
formula.o: number.o formula.cpp formula.h