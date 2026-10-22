# all:
# 	gcc -o hello hello.c
# run:
# 	./hello

# Declaratiile de variabile
CC = gcc
CFLAGS = -Wall -lrt
SRC = test1_ocw.c
EXE = test1_ocw
COMP = ./test1_ocw
 
# Regula de compilare
all:
	$(CC) -o $(EXE) $(SRC) $(CFLAGS) && $(COMP)
 
# Regulile de "curatenie" (se folosesc pentru stergerea fisierelor intermediare si/sau rezultate)
.PHONY : clean
clean :
	rm -f $(EXE) *~