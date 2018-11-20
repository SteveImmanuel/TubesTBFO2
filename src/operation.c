#include "operation.h"

int lenInput;

int isOperator (char x)
/*
  fungsi bernilai 1 jika jumlah x adalah +,-,*,/,atau^
*/
{
    //algoritma
    return x=='*' || x=='/' || x=='^' || x=='+' || x=='-';
}

int isNumber(char x)
/*
  fungsi bernilai 1 jika karakter yang dimasukkan adalah bilangan
  dengan 0 <= x <= 9 dan 0 jika tidak
*/
{
    //algoritma
    if(x>='0' && x<='9'){
        return 1;
    }else{
        return 0;
    }
}

int isFloat(float x)
/*
  fungsi bernilai 1 jika float yang dimasukkan adalah bilangan koma
  dan 0 jika tidak
*/
{
    //algoritma
    if (trunc(x)==x){
        return 0;
    } else {
        return 1;
    }
}
int isPangkatValid(float op1, float op2)
/*
  fungsi bernilai 1 jika pangkat valid, dan 0 jika tidak
  op1 ^ op2
*/
{
    //algoritma
    if (op1 < 0 && isFloat(op2)){
        return 0;
    } else if (op1 == 0 && op2 <=0){
        return 0;
    } else {
        return 1;
    }
}

void BilanganKoma(String persamaan, int *indeks, float *hasil, int *status)
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
    if(isNumber(persamaan[*indeks])){
        Angka(persamaan,indeks,&temphasil);
        while(isNumber(persamaan[tempidx])){
            temphasil/=(float)10;
            tempidx++;
        }
        *hasil=temphasil;
    }else{
        *status=1;
    }
    
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
        (*indeks)++;
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
{   //kamus
    int sign;
    float tempfloat;
    //algoritma
    sign =1;
    tempfloat = 0;
    if(persamaan[*indeks]=='('){
        (*indeks)++;
        TambahKurang(persamaan,indeks,hasil,status);
        if(persamaan[*indeks]==')'){
            (*indeks)++;
        }else{
            *status=1;
        }
    }else{
        if(persamaan[*indeks]=='-'){
            sign=-1;
            (*indeks)++;
        }
        if(isNumber(persamaan[*indeks])){
            Angka(persamaan,indeks,hasil);
            if(persamaan[*indeks]=='.'){ //kasus float
                (*indeks)++;
                BilanganKoma(persamaan,indeks,&tempfloat,status);
            }
            (*hasil)=((*hasil)+tempfloat)*sign;
        }else if(persamaan[*indeks]=='('){ //kasus -()
            (*indeks)++;
            TambahKurang(persamaan,indeks,hasil,status);
            if(persamaan[*indeks]==')'){
                (*hasil)*=sign;
                (*indeks)++;
            }else{
                *status=1;
            }
        }else{
            *status=1;
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
    //kamus
    float tempHasil;
    int tempIndeks;
    //algoritma
    if (*indeks<lenInput){
        Simbol(persamaan,indeks,hasil,status);
        if (!(*status)){ /* status == 0, valid */
            while(persamaan[*indeks]=='^' && !(*status)){
                tempIndeks = *indeks;
                (*indeks)++;
                Pangkat(persamaan,indeks,&tempHasil,status);
                if (!(*status)){
                    if (isPangkatValid(*hasil,tempHasil)) {
                        *hasil = pow(*hasil,tempHasil);
                    } else {
                        *status = 2;
                    }
                }
            }
        }
    }
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
    float tempHasil;
    int tempIndeks;
    //algoritma
    if (*indeks<lenInput){
        Pangkat(persamaan,indeks,hasil,status);
        if (!(*status)){ /* status == 0, valid */
            while((persamaan[*indeks]=='*' || persamaan[*indeks]=='/') && !(*status)){
                tempIndeks = *indeks;
                (*indeks)++;
                Pangkat(persamaan,indeks,&tempHasil,status);
                if (!(*status)){
                    if (persamaan[tempIndeks]=='*'){
                        *hasil *= tempHasil;
                    } else if (persamaan[tempIndeks]=='/'){
                        if (tempHasil!= 0){
                            *hasil /= tempHasil;
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
    float tempHasil;
    int tempIndeks;
    //algoritma
    if (*indeks<lenInput){
        KaliBagi(persamaan,indeks,hasil,status);
        if (!(*status)){ /* status == 0, valid */
            while((persamaan[*indeks]=='+' || persamaan[*indeks]=='-') && !(*status)){
                tempIndeks = *indeks;
                (*indeks)++;
                KaliBagi(persamaan,indeks,&tempHasil,status);
                if (!(*status)){
                    if (persamaan[tempIndeks]=='+'){
                        *hasil += tempHasil;
                    } else if (persamaan[tempIndeks]=='-'){
                        *hasil -= tempHasil;
                    }
                }
            }
        }
    }
}
