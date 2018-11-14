
#ifndef OPERATOR_H
#define OPERATOR_H

#include <stdio.h>
#include <string.h>

/*
S -> K | S+K | S-K      tambah kurang
K -> P | K*P | K/P      kali bagi
P -> I | I^P      pangkat
I -> (S) | A | -A | A.A | -A.A      simbol
A -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | AA angka
*/

#define String char* /* tipe bentukan string dari char* */

extern int lenInput; /* variabel untuk menyatakan panjang dari persamaan input */

int isNumber(char x);
/*
  fungsi bernilai 1 jika karakter yang dimasukkan adalah bilangan
  dengan 0 <= x <= 9 dan 0 jika tidak
*/
void BilanganKoma(String persamaan, int *indeks, float *hasil);
/*
  I.S. persamaan dan indeks terdefinisi
  F.S. prosedur mengembalikan bilangan 0. yang diawali dari indeks
*/
void Angka(String persamaan, int *indeks, float *hasil);
/*
  I.S. persamaan dan indeks terdifinisi
  F.S. hasil berisi hasil konversi persamaan ke float
*/
void Simbol(String persamaan, int *indeks, float *hasil, int *status);
/*
  I.S. persamaan dan indeks terdefinisi
  F.S. hasil berisi float hasil cek bilangan  di dalam persamaan
       status berisi kondisi input persamaan
       0 = valid
       1 = “SYNTAX ERROR”
       2 = “MATH ERROR”
*/
void Pangkat(String persamaan, int *indeks, float *hasil, int *status);
/*
  I.S. persamaan dan indeks terdefinisi
  F.S. hasil berisi hasil perpangkatan bilangan di dalam persamaan
       status berisi kondisi input persamaan
       0 = valid
       1 = “SYNTAX ERROR”
       2 = “MATH ERROR”
*/
void KaliBagi(String persamaan, int *indeks, float *hasil, int *status);
/*
  I.S. persamaan dan indeks terdefinisi
  F.S. hasil berisi hasil perkalian dan pembagian bilangan di dalam persamaan
       status berisi kondisi input persamaan
       0 = valid
       1 = “SYNTAX ERROR”
       2 = “MATH ERROR”
*/
void TambahKurang(String persamaan, int *indeks, float *hasil, int *status);
/*
  I.S. persamaan dan indeks terdefinisi
  F.S. hasil berisi hasil penambahan dan pengurangan bilangan di dalam persamaan
       status berisi kondisi input persamaan
       0 = valid
       1 = “SYNTAX ERROR”
       2 = “MATH ERROR”
*/
#endif
