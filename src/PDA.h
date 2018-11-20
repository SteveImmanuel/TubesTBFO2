#include <stdio.h>
#include <string.h>
#include "operation.h"

#define N 13

//rule
typedef struct{
    char stateNow;
    char input;
    // '(', ')', 'o' = operator, 'n' = number, '.'
    char topOfStack;
    // X = '(', Z = empty
    char stateGo;
    char stack; //hasilnya push apa pop
    // 'u' = push
    // 'o' = pop
    // 'e' = unchange
}Produksi;

typedef struct{
    Produksi listProduksi[N]; //aturan produksi
}Aturan;

typedef struct{
  char memory[100]; //memori menyimpan data stack
  int top;          //indeks posisi top of stack
}Stack;

void makeProduksi(Aturan *list, int indeks, char dari, char input, char top, char ke, char stack);

int Search(Aturan list ,char input, char current,char top);

void DoSomething(Stack *s, char stack);

int PDA(String persamaan);



