#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "operation.h"
#include <unistd.h>
  
bool isPilihanValid(String Kata)
//Fungsi mengeluarkan true jika pilihan yang dimasukan valid
{
  //Kamus lokal
  bool found;
  int digit;  

  //Algoritma
  digit = strlen(Kata);
  if(digit!=1)
    found = false;
  else
    if(Kata[0]=='1' || Kata[0]=='2')
      found = true;
    else
      found = false;
  return found;
}

int main(){
  //Kamus
  String pilihan;
  String input;
  int status; 
  float hasil;
  int indeks;

  // Algoritma Utama
  do{
    printf("CALCULATOR\n");
    printf("1. Calculate\n");
    printf("2. Exit\n");
    pilihan = (char*) malloc (100* sizeof(char));

    do{
      printf(">> ");
      scanf("\n%[^\n]s", pilihan);
      if(!isPilihanValid(pilihan)){
        printf("Input yang dimasukan tidak ada.\n");
      }
    }while(!isPilihanValid(pilihan));
    //input pilihan valid   
    
    if(pilihan[0]=='1'){
      status = 0;
      indeks = 0;
      printf("Calculate : ");     
      scanf("%s", input);
      lenInput = strlen(input);
      if(PDA(input)){
        TambahKurang(input,&indeks,&hasil,&status);
        if(status==0){
          printf("%f\n",hasil);      
        } else if (status == 1){
          printf("SYNTAX ERROR\n");
        } else if (status == 2){
          printf("MATH ERROR\n");
        }
      }else{
        printf("SYNTAX ERROR\n");
      }
      printf("\n");
    }
      
  } while(pilihan[0]!= '2');
  //pilihan[0] = 2

  printf("Terima Kasih!\n"); 
  sleep(0.75);
}
