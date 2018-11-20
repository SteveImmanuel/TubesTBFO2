#include "PDA.h"

void makeProduksi(Aturan *list, int indeks, char dari, char input, char top, char ke, char stack)
/*
    I.S. semua parameter terdefinisi
    F.S. *list berisi semua aturan produksi
*/
{
    //algoritma
    (*list).listProduksi[indeks].stateNow = dari;
    (*list).listProduksi[indeks].input = input;
    (*list).listProduksi[indeks].topOfStack = top;
    (*list).listProduksi[indeks].stateGo = ke;
    (*list).listProduksi[indeks].stack=stack;
}

int Search(Aturan list ,char input, char current,char top)
/*
    mengembalikan indeks aturan di list jika ditemukan, -1 jika tidak ditemukan
*/
{
    //kamus
    int found = 0;
    int i = 0;
    char kar;
    //algoritma
    while(i<N && !found){
        if (isNumber(input)) {
            kar = 'n';
        } else if (isOperator(input)){
            kar = 'o';
        } else {
            kar = input;
        }
        if(list.listProduksi[i].input == kar && list.listProduksi[i].topOfStack == top && list.listProduksi[i].stateNow == current){
            found = 1;
        } else {
            i++;
        }
    }
    if (found){
        return i;
    } else {
        return -1;
    }
}

void DoSomething(Stack *s, char stack)
/*
    melakukan operasi ke stack sesuai dengan karakter stack
*/
{
    //algoritma
    if (stack == 'u'){
        (*s).top++;
        (*s).memory[(*s).top]= 'X';
    } else if (stack == 'o'){
        (*s).top--;
    }
}


int PDA(String persamaan)
/* 
    melakukan validasi input, bernilai 1 jika jumlah ( sama dengan ),
    tidak diakhiri operasi ataupun . dan tidak ada 2 operator yang bersebelahan
    0 jika tidak
*/
{
    //kamus
    Aturan aturan;
    char current;
    Stack s;
    int indeks,temp=0;
    //algoritma
    //aturan produksi
    makeProduksi(&aturan,0,'a','(','Z','a','u');
    makeProduksi(&aturan,1,'a','(','X','a','u');
    makeProduksi(&aturan,2,'a','n','Z','a','e');
    makeProduksi(&aturan,3,'a','n','X','a','e');
    makeProduksi(&aturan,4,'a',')','X','a','o');
    makeProduksi(&aturan,5,'a','.','Z','b','e');
    makeProduksi(&aturan,6,'a','.','X','b','e');
    makeProduksi(&aturan,7,'a','o','Z','b','e');
    makeProduksi(&aturan,8,'a','o','X','b','e');
    makeProduksi(&aturan,9,'b','n','X','a','e');
    makeProduksi(&aturan,10,'b','n','Z','a','e');
    makeProduksi(&aturan,11,'b','(','X','a','u');
    makeProduksi(&aturan,12,'b','(','Z','a','u');
    s.top = 1;
    s.memory[s.top] = 'Z';
    current = 'a';
    indeks = 0;

    while(indeks < strlen(persamaan)&&temp!=-1){
        temp=Search(aturan,persamaan[indeks],current,s.memory[s.top]);
        if(temp!=-1){
            DoSomething(&s,aturan.listProduksi[temp].stack);
            current = aturan.listProduksi[temp].stateGo;
        }
        indeks++;                         
    }
    if (current == 'a' && s.memory[s.top]=='Z'&& indeks == strlen(persamaan)){
        return 1;
    }else {
        return 0;
    }
}