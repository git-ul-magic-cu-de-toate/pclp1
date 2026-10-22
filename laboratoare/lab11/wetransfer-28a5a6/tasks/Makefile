# Copyright 2020 Darius Neatu (neatudarius@gmail.com)

CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lm

SRCS = $(sort $(wildcard *.c))
TARGET = set

# build all targets
all: $(TARGET)

# general rule for building a target
set: main.c set.c
	$(CC) $(CFLAGS) main.c set.c -o $@ $(LDFLAGS)

# run a single target
run: $(TARGET)
	./$(TARGET)

# clean all related target files
clean:
	rm -f *.o $(TARGET)

# pack directory
pack:
	zip -FS $(ZIP).zip *.c *.h Makefile README

.PHONY: pack clean
