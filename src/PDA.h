#include <stdio.h>
#include <string.h>
#include "operation.h"

#define N 13

//rule
typedef struct{
    char stateNow;
    char input; // '(', ')', 'o' = operator, 'n' = number, '.'
    char topOfStack; // X = '(', Z = empty
    char stateGo;
    char stack;
    // 'u' = push
    // 'o' = pop
    // 'e' = unchange
}Produksi; //tipe data produksi

typedef struct{
    Produksi listProduksi[N]; //aturan produksi
}Aturan; //tipe data aturan = kumpulan produksi

typedef struct{
  char memory[100]; //memori menyimpan data stack
  int top;          //indeks posisi top of stack
}Stack;

void makeProduksi(Aturan *list, int indeks, char dari, char input, char top, char ke, char stack);
/*
    I.S. semua parameter terdefinisi
    F.S. *list berisi semua aturan produksi
*/

int Search(Aturan list ,char input, char current,char top);
/*
    mengembalikan indeks aturan di list jika ditemukan, -1 jika tidak ditemukan
*/

void DoSomething(Stack *s, char stack);
/*
    melakukan operasi ke stack sesuai dengan karakter stack
*/

int PDA(String persamaan);
/* 
    melakukan validasi input, bernilai 1 jika jumlah ( sama dengan ),
    tidak diakhiri operasi ataupun . dan tidak ada 2 operator yang bersebelahan
    0 jika tidak
*/


