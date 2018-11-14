
#ifndef OPERATOR_H
#define OPERATOR_H

#include <stdio.h>
#include <string.h>
#include "boolean.h"

/*
S -> K | S+K | S-K      tambah kurang
K -> P | P*K | P/K      kali bagi
P -> I | I^P      pangkat
I -> (S) | A | -A | A.A | -A.A      simbol
A -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | AA angka
*/

extern int lenInput;

boolean isNumber(char x);
/*
  fungsi bernilai True jika karakter yang dimasukkan adalah bilangan
  dengan 0 <= x <= 9
*/
void BilanganKoma(char *persamaan, int *indeks, float *hasil);
/*
  I.S. persamaan dan indeks terdefinisi
  F.S. prosedur mengembalikan bilangan 0. yang diawali dari indeks
*/
void TambahKurang(char* st, int*idx, float * result, boolean *valid);
/*

*/
void KaliBagi(char* st,int* idx, float* result,boolean *valid);
void Pangkat(char* st,int* idx, float* result,boolean *valid);
void Simbol(char* st,int* idx, float* result,boolean *valid);
void Angka(char* st,int* idx, float* result);


#endif
