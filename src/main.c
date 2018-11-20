#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "operation.h"
#include <unistd.h>
#include <ctype.h>

bool isExit(String Kata)
//fungsi mengeluarkan true jika string yang dimasukkan adalah 'exit'
{
  //Kamus lokal
  bool found;
  int huruf;

  //Algoritma
  huruf = strlen(Kata);

  for(int i=0; Kata[i];i++){
    Kata[i] = tolower(Kata[i]);
  }

  if(huruf!=4)
    found = false;
  else
    if((Kata[0]=='e') && (Kata[1]=='x') && (Kata[2]=='i') && (Kata[3]=='t'))
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
    printf("==========\n");
    printf("\n");
    pilihan = (char*) malloc (100* sizeof(char));

    printf(">> ");
    scanf("\n%[^\n]s", input);

    if(!isExit(input)){
      status = 0;
      indeks = 0;
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

  } while(!isExit(input));
  //input = 'exit'

  printf("Terima Kasih!\n");
  sleep(0.75);
}
