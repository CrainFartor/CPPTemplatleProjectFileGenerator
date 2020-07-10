CC=g++
CFLAGS= -Wall
DEFS_FOLDER=./def
LIBS_FOLDER=./lib
LIBS=lib.cpp
EXE=
MAIN=main.cpp
SRC_FOLDER=./src

default: main

main: $(SRC_FOLDER)/$(MAIN)  $(DEFS_FOLDER)/*.h
	$(CC) $(CFLAGS) -o $(EXE) $(SRC_FOLDER)/$(MAIN) $(LIBS_FOLDER)/$(LIBS)

clean:
	rm -f $(EXE)

all: clean main
