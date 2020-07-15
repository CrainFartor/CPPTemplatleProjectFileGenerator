CC=gcc
CFLAGS= -Wall -Wno-missing-braces -Wno-discarded-qualifiers
DEFS_FOLDER=./def
LIBS_FOLDER=./lib
LIBS=lib.c template_strings.c
EXE=GenTemplate
MAIN=main.c
SRC_FOLDER=./src

default: main

main: $(SRC_FOLDER)/$(MAIN)  $(DEFS_FOLDER)/*.h
	$(CC) $(CFLAGS) -o $(EXE) $(SRC_FOLDER)/$(MAIN) $(LIBS_FOLDER)/lib.c $(LIBS_FOLDER)/template_strings.c

clean:
	rm -f $(EXE)

all: clean main
