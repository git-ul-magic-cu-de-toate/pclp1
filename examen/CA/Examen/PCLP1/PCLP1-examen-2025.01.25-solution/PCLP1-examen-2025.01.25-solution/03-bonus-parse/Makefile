# Copyright 2024 Darius Neatu (darius.neatu@upb.ro)

CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lm

SRCS = $(sort $(wildcard *.c))
TARGETS = $(patsubst %.c,%,$(SRCS))
TARGET = $(src:.c=)

# build all targets
build: $(TARGETS)

# general rule for building a target
%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

# run a single target
run: $(TARGET)
	./$(TARGET)

# clean all related target files
clean:
	rm -rf *.o $(TARGETS) *.dSYM

# pack directory
pack:
	zip -FS $(ZIP).zip *.c *.h Makefile README

.PHONY: pack clean
