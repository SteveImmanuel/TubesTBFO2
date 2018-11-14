
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "operation.h"

#define ValUndeff -999

int castInt(String kata)
//fungsi yang menghasilkan nilai integer
{
  //Kamus Lokal
  int value;
  int digit;
  int i;

  //Algoritma
  value = 0;i
  
  digit = strlen(kata);
  if(digit==0)
    return ValUndeff;
  else{
    while(i<digit)
  }

}
  

int main(){
  //Kamus
  int pilihan;
  String input;
  int panjangKata;

  //Algoritma Utama
  do{
    printf("CALCULATOR\n");
    printf("1. Calculate\n");
    printf("2. Exit\n");

    printf(">> ");
    scanf("%s, &input");

    while(input!=1 && input!=2){
      printf("Input yang dimasukan salah.\n");
      printf(">> ");
      scanf("%s",&input);
    } //input = 1 atau input = 2

    if(input==1){

      panjanginput = strlen(input)
    }
      
  } while(input!= 2);

  return 0;
}
