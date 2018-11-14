
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "operation.h"
  
// bool isPilihanValid(String Kata)
// //Fungsi mengeluarkan true jika pilihan yang dimasukan valid
// {
//   //Kamus lokal
//   bool found;
//   int digit;  

//   //Algoritma
//   digit = str.len(Kata);
//   if(digit!=1)
//     found = false;
//   else
//     if()
//   return found;
// }

int main(){
  //Kamus
  int pilihan;
  String input;
  int status; 
  float hasil;
  int indeks;

  // Algoritma Utama
  do{
    printf("CALCULATOR\n");
    printf("1. Calculate\n");
    printf("2. Exit\n");

    printf(">> ");
    scanf("%d", &pilihan);

    while(pilihan!=1 && pilihan!=2){
      printf("Input yang dimasukan tidak ada.\n");
      printf(">> ");
      scanf("%d",&pilihan);
    } //pilihan = 1 atau pilihan = 2

    if(pilihan==1){
      status = 0;
      indeks = 0;
      printf("Calculate : ");     
      scanf("%s", input);
      lenInput = strlen(input);
      TambahKurang(input,&indeks,&hasil,&status);
      if(status==0){
        printf("%f\n",hasil);      
      } else if (status == 1){
        printf("SYNTAX ERROR\n");
      } else if (status == 2){
        printf("MATH ERROR\n");
      }
      printf("\n");
    }
      
  } while(pilihan!= 2);
  
  
  // digit = strlen(kata);
  // if(digit==0)
  //   return ValUndeff;
  // else{
  //   while(i<digit)
  // }

}
