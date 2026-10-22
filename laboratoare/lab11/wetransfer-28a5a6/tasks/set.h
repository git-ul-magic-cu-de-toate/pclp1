#pragma once

#include <stdio.h>

#define SET_SIZE 100
#define NMAX (SET_SIZE * 8)

// definim tipul byte_t ca fiind un alias catre unsigned char (8 biti)
typedef unsigned char byte_t;

// definesc tipul SET, care este un vector cu maxim 100 de elemente
// de tip unsigned char
typedef byte_t SET[SET_SIZE];

// is_set
// byte    - byte de intrare pentru care vreau sa verific un bit
// bit     - indexul bitului din byte
// @return - 1, daca bitul este 1
//           0, daca bitul este 0
int is_set(byte_t byte, int bit);

// set_bit
// byte    - byte de intrare pentru care vreau sa setez un bit
// bit     - indexul bitului din byte
// @return - noul byte
byte_t set_bit(byte_t byte, int bit);

// reset_bit
// byte    - byte de intrare pentru care vreau sa resetez un bit
// bit     - indexul bitului din byte
// @return - noul byte
byte_t reset_bit(byte_t byte, int bit);


// is_in_set(s, n) - returneaza 1 daca n este in s, 0 altfel
int is_in_set(SET s, unsigned int n);

// insert_in_set(s,n) - adauga numarul n in multimea s
void insert_in_set(SET s, unsigned int n);

// delete_from_set(s,n) - scoate numarul n din multime s
void delete_from_set(SET s, unsigned int n);

// delete_all_from_set(s) - elimina toate elementele din multime
void delete_all_from_set(SET s);

// card_set(s) - returneaza cardinalul multimii s
int card_set(SET s);

// is_empty_set(s) - returneaza 1 daca s = {}, 0 alfel
int is_empty_set(SET s);

// print_set(s) - functia printeaza elementele multimii s
void print_set(SET s);

// read_set(s) - functia citeste numarul n de elemente care se afla in a
// apoi citeste cele n numere si le insereaza in a
// va returna numarul n citit (numarul de elemente)
int read_set(SET s);

// c = AUB
void merge_set(SET a, SET b, SET c);

// c = AnB
void intersect_set(SET a, SET b, SET c);

// c = a - b
void diff_set(SET a, SET b, SET c);
