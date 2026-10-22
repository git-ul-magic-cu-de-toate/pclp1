# SAVA Victor 311CA

# compiler setup
CC=gcc
CFLAGS=-g -Wall -Wextra -std=c99

# define targets
TARGETS=image_editor

# define march and functions
EDITOR=image_editor.c
FUNCTIONS=utils.c

build: $(TARGETS)

image_editor: image_editor.c
	$(CC) $(CFLAGS) $(EDITOR) -o image_editor $(FUNCTIONS) -lm

pack:
	zip -FSr 311CA_VictorSava_Tema3.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean
