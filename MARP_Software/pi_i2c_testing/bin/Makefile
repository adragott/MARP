CC=g++
CFLAGS=-c -w -std=c++14 -Wall -I$(INC) -I$(SRC)

SRC = ../src/
INC = ../inc/

LIBS = -lcurses
all: run

run: output
	@./marp_thermo_test

.PHONY: all run rebuild

build:
	@echo "Building..."
	@make -B --no-print-directory

rebuild:
	@make clean --no-print-directory
	@echo "Rebuilding..."
	@make -B --no-print-directory

output: main.o Project.o
	$(CC) main.o Project.o -o marp_thermo_test $(LIBS)

main.o: ../src/main.cpp
	$(CC) $(CFLAGS) ../src/main.cpp

Project.o: ../src/Project.cpp ../inc/Project.h
	$(CC) $(CFLAGS) ../src/Project.cpp

clean:
	@echo "Cleaning..."
	rm *.o output
