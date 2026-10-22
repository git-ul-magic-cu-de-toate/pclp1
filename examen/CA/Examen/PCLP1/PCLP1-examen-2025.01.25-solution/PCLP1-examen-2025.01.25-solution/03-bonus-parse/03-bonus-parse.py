# Copyright 2024 Darius Neatu (darius.neatu@upb.ro)
# Se cere doar functia parse().
# Acesta este un program complet folosit pentru a testa functia parse().

# Functia primeste ca parametri un nume de fisier si un numar natural k.
# Afiseaza primele / ultimele k linii din fisier, in functie de valoarea lui k.
def parse(filename, k):
    # Pentru Python nu avem restrictii de timp / memorie. Putem citi tot fisierul deodata.
    with open(filename, "r") as fin:
        lines = fin.readlines()
        n = len(lines)
    
    if k > 0:
        # Afisam primele k linii: 0, 1, ..., k-1.
        k = min(k, n)     # Daca k este mai mare decat n, afisam toate liniile.
        lines = lines[:k] # Afisam primele k linii din lista/fisier.
    else:
        # Afisam ultimele k linii: n-k, n-k+1, ..., n-1.
        k = min(-k, n)
        lines = lines[-k:]
    
    for line in lines:
        print(line, end="") # Afisam linia fara newline aditional.


# Teste pentru functia parse()
if __name__ == "__main__":
    filename = "03-bonus-parse.in" # Continutul fisierului: "Line 1\nLine 2\n...\nLine 10\n".

    print("Afisam primele 5 linii din fisier. (k = 5)")
    parse(filename, 5)
    print("Afisam ultimele 5 linii din fisier. (k = -5)")
    parse(filename, -5)
    print("Afisam primele 10 linii din fisier. (k = 10)")
    parse(filename, 10)
    print("Afisam ultimele 10 linii din fisier. (k = -10)")
    parse(filename, -10)
    print("Afisam primele 15 linii din fisier. (k = 15)")
    parse(filename, 15)
    print("Afisam ultimele 15 linii din fisier. (k = -15)")
    parse(filename, -15)

# $ python3 03-bonus-parse.py
# Afisam primele 5 linii din fisier. (k = 5)
# Line 1
# Line 2
# Line 3
# Line 4
# Line 5
# Afisam ultimele 5 linii din fisier. (k = -5)
# Line 6
# Line 7
# Line 8
# Line 9
# Line 10
# Afisam primele 10 linii din fisier. (k = 10)
# Line 1
# Line 2
# Line 3
# Line 4
# Line 5
# Line 6
# Line 7
# Line 8
# Line 9
# Line 10
# Afisam ultimele 10 linii din fisier. (k = -10)
# Line 1
# Line 2
# Line 3
# Line 4
# Line 5
# Line 6
# Line 7
# Line 8
# Line 9
# Line 10
# Afisam primele 15 linii din fisier. (k = 15)
# Line 1
# Line 2
# Line 3
# Line 4
# Line 5
# Line 6
# Line 7
# Line 8
# Line 9
# Line 10
# Afisam ultimele 15 linii din fisier. (k = -15)
# Line 1
# Line 2
# Line 3
# Line 4
# Line 5
# Line 6
# Line 7
# Line 8
# Line 9
# Line 10
