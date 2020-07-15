CC=g++
CFLAGS= -Wall
LIBS=./lib/lib.cpp
MAIN=./src/main.cpp
EXE=EXE

default: main

main:
	$(CC) $(CFLAGS) -o $(EXE) $(MAIN) $(LIBS)

clean:
	rm -f $(EXE)

all: clean main
