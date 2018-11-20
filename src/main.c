#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include "operation.h"
#include "PDA.h"


bool isExit(String Kata)
//fungsi mengeluarkan true jika string yang dimasukkan adalah 'exit'
{
  //Kamus lokal
  bool found;
  int huruf,i;

  //Algoritma
  huruf = strlen(Kata);
  for(i=0;i<huruf;i++){
    Kata[i]=tolower(Kata[i]);
  }
  if(huruf!=4)
    found = false;
  else
    if(strcmp(Kata,"exit")==0)
      found = true;
    else
      found = false;
  return found;
}

int main(){
  //Kamus
  String persamaan;
  String input;
  int status,indeks;
  float hasil;
  

  // Algoritma Utama
  do{
    printf("CALCULATOR\n");
    printf("==========\n");
    printf("\n");

    //alokasi
    input = (char*) malloc (100* sizeof(char));
    printf(">> ");
    scanf("\n%[^\n]s", input); //membaca input

    if(!isExit(input)){ //menghitung
      //inisialisasi
      status = 0;
      indeks = 0;
      if(input[indeks]=='-'){ //input diawali '-'
        strcpy(persamaan,"0");
        strcat(persamaan,input);
      } else{ //input awal bukan '-'
        strcpy(persamaan,input);
      }
      lenInput = strlen(persamaan);

      if(PDA(persamaan)){ //validasi dengan PDA
        TambahKurang(persamaan,&indeks,&hasil,&status);
        if(status==0){ //berhasil terhitung
          printf("%f\n",hasil);
        } else if (status == 1){
          printf("SYNTAX ERROR\n");
        } else if (status == 2){
          printf("MATH ERROR\n");
        }
      }else{ //gagal validasi PDA
        printf("SYNTAX ERROR\n");
      }
      printf("\n");
    }

  } while(!isExit(input));
  //input = 'exit'

  printf("Terima Kasih!\n");
  sleep(0.75);
  return 0;
}
