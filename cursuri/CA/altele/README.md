# Demo modularizare, headers, macros

Link-uri utile: 
* https://ocw.cs.pub.ro/courses/programare/coding-style
* https://ocw.cs.pub.ro/courses/programare/laboratoare/lab13
  
Să presupunem că avem mai multe operatii cu vectori si matrice. Fiecare tip de date are mai multe operatii, si vom
incerca sa simulam "o biblioteca" pentru fiecare tip de date. 

In acest demo aratam doar primul pas, care arata o **posibila** organizare a codului in directoare, 
fisiere etc. Verificati Makefile. Cititi incepand cu main.c, apoi vector.h/c, apoi matrix.h/c.

* Task0:
  * Rezolvare in `task00.c`.
  * Compilare + rulare
```bash
$ make && ./task0 < data/task0.in 
gcc -Wall -Wextra -o task0 task0.c vector.c matrix.c util.c
10 20 -1 20 5 
1 2 
0 1 
0 5
```

* Task1:
  * Rezolvare in `task01.c`.
  * Compilare + rulare
```bash
$ make && ./task1 < data/task1.in 
gcc -Wall -Wextra -o task1 task1.c vector.c matrix.c util.c
-1 5 10 20 20  # vectorul sortat
20 20 10 5 -1  # vectorul inversat (dupa ce a fost sortat)
0 0 1          # A^5 == A 
0 1 0 
1 0 0 
```

TODOs: Puteți încerca și mai multe ierarhii de directoare. De exemplu:
* `include/` - conține toate fișierele header ( `vector.h`, `matrix.h`, `util.h`).
* `src/` - conține toate fișierele în care avem codul reutilizabil ( `vector.c`, `matrix.c`, `util.c`).
* În directorul rădăcină păstrăm fișierele `task1.c`, `task0.c` și Makefile.
TODO1: Luați ca exercițiu o astfel de ierarhie și actualizați Makefile astfel încât să compileze.
TODO2: Ce trebuie să actualizați în Makefile pentru putea folosi `#include "vector.h"` în continuare? (vs `#include "include/vector.h`)
