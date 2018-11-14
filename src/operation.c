#include "operation.h"

int isNumber(char x)
/*
  fungsi bernilai 1 jika karakter yang dimasukkan adalah bilangan
  dengan 0 <= x <= 9 dan 0 jika tidak
*/
{
    //algritma
    if(x>='0' && x<='9'){
        return 1;
    }else{
        return 0;
    }
}
void BilanganKoma(String persamaan, int *indeks, float *hasil)
/*
  I.S. persamaan dan indeks terdefinisi, persamaan[*indeks] berada di satu angka setelah koma
  F.S. prosedur mengembalikan bilangan 0. yang diawali dari indeks
*/
{
    //kamus
    float temphasil;
    int tempidx;
    //algoritma
    temphasil=0;    
    tempidx=*indeks;
    *hasil=0;
    Angka(persamaan,indeks,&temphasil);
    while(isNumber(persamaan[*indeks])){
        temphasil/=10;
        *indeks++;                        
    }
    *hasil=temphasil;    
}
void Angka(String persamaan, int *indeks, float *hasil)
/*
  I.S. persamaan dan indeks terdifinisi
  F.S. hasil berisi hasil konversi persamaan ke float
*/
{
    //algoritma
    *hasil=0;
    while(isNumber(persamaan[*indeks])){
        *hasil=(*hasil)*10+(float)(persamaan[*indeks]-'0');
        *indeks++;
    }
}
void Simbol(String persamaan, int *indeks, float *hasil, int *status)
/*
  I.S. persamaan dan indeks terdefinisi
  F.S. hasil berisi float hasil cek bilangan  di dalam persamaan
       status berisi kondisi input persamaan
       0 = valid
       1 = “SYNTAX ERROR”
       2 = “MATH ERROR”
*/
{
    int sign=1;

    if(persamaan[*indeks]=='('){
        *indeks++;
        TambahKurang(persamaan,indeks,hasil,status);
        if(persamaan[*indeks]==')'){
            *indeks++;                                    
        }else{
            *status=1;
        }                                                                    
    }else{
        if(persamaan[*indeks]=='-'){
            sign=-1;            
        }
        if(isNumber(persamaan[*indeks])){
            Angka(persamaan,)
        }

        
    }
}
void Pangkat(String persamaan, int *indeks, float *hasil, int *status)
/*
  I.S. persamaan dan indeks terdefinisi
  F.S. hasil berisi hasil perpangkatan bilangan di dalam persamaan
       status berisi kondisi input persamaan
       0 = valid
       1 = “SYNTAX ERROR”
       2 = “MATH ERROR”
*/
{

}
void KaliBagi(String persamaan, int *indeks, float *hasil, int *status)
/*
  I.S. persamaan dan indeks terdefinisi
  F.S. hasil berisi hasil perkalian dan pembagian bilangan di dalam persamaan
       status berisi kondisi input persamaan
       0 = valid
       1 = “SYNTAX ERROR”
       2 = “MATH ERROR”
*/
{
    //kamus
    float temp;
    //algoritma
    if (*indeks<lenInput){
        Pangkat(persamaan,indeks,hasil,status);
        if (!(*status)){ /* status == 0, valid */
            while((persamaan[*indeks]=='*' || persamaan[*indeks]=='/') && !(*status)){
                (*indeks)++;
                Pangkat(persamaan,indeks,&temp,status);
                if (!(*status)){
                    if (persamaan[*indeks]=='*'){
                        *hasil *= temp;
                    } else if (persamaan[*indeks]=='/'){
                        if (temp!= 0){
                            *hasil /= temp;
                        } else {
                            *status = 2;
                        }
                    }
                }
            }
        } 
    }
}
void TambahKurang(String persamaan, int *indeks, float *hasil, int *status)
/*
  I.S. persamaan dan indeks terdefinisi
  F.S. hasil berisi hasil penambahan dan pengurangan bilangan di dalam persamaan
       status berisi kondisi input persamaan
       0 = valid
       1 = “SYNTAX ERROR”
       2 = “MATH ERROR”
*/
{
    //kamus
    float temp;
    //algoritma
    if (*indeks<lenInput){
        KaliBagi(persamaan,indeks,hasil,status);
        if (!(*status)){ /* status == 0, valid */
            while((persamaan[*indeks]=='+' || persamaan[*indeks]=='-') && !(*status)){
                (*indeks)++;
                KaliBagi(persamaan,indeks,&temp,status);
                if (!(*status)){
                    if (persamaan[*indeks]=='+'){
                        *hasil += temp;
                    } else if (persamaan[*indeks]=='-'){
                        *hasil -= temp;
                    }
                }
            }
        } 
    }
}