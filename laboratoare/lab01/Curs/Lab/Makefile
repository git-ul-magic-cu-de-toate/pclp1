# all:
# 	gcc -o hello hello.c
# run:
# 	./hello

# Declaratiile de variabile
CC = gcc
CFLAGS = -Wall -lm
SRC = pb7.c
EXE = pb7
COMP = ./pb7
 
# Regula de compilare
all:
	$(CC) -o $(EXE) $(SRC) $(CFLAGS) && $(COMP)
 
# Regulile de "curatenie" (se folosesc pentru stergerea fisierelor intermediare si/sau rezultate)
.PHONY : clean
clean :
	rm -f $(EXE) *~