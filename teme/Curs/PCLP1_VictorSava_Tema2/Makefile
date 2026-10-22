# SAVA Victor 311CA

# compiler setup
CC=gcc
CFLAGS=-g -Wall -Wextra -std=c99

# define targets
TARGETS=marching_squares

# define march and functions
MARCH=marching_squares.c
FUNCTIONS=change_pixel.c init_contour.c march_squares_functions.c

build: $(TARGETS)

marching_squares: marching_squares.c
	$(CC) $(CFLAGS) $(MARCH) -o marching_squares $(FUNCTIONS)

pack:
	zip -FSr 311CA_VictorSava_Tema2.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean
