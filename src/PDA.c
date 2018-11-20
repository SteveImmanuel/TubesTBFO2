

// int isOperator (char x)
// /*
//   fungsi bernilai 1 jika jumlah x adalah +,-,*,/,atau^
// */
// {
//     return x=='*' || x=='/' || x=='^' || x=='+' || x=='-';
// }

// int isNumber(char x)
// /*
//   fungsi bernilai 1 jika karakter yang dimasukkan adalah bilangan
//   dengan 0 <= x <= 9 dan 0 jika tidak
// */
// {
//     //algoritma
//     if(x>='0' && x<='9'){
//         return 1;
//     }else{
//         return 0;
//     }
// }

#include "PDA.h"

void makeProduksi(Aturan *list, int indeks, char dari, char input, char top, char ke, char stack)
{
    (*list).listProduksi[indeks].stateNow = dari;
    (*list).listProduksi[indeks].input = input;
    (*list).listProduksi[indeks].topOfStack = top;
    (*list).listProduksi[indeks].stateGo = ke;
    (*list).listProduksi[indeks].stack=stack;
}

int Search(Aturan list ,char input, char current,char top){
    int found = 0;
    int i = 0;
    char kar;
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

void DoSomething(Stack *s, char stack){
    if (stack == 'u'){
        (*s).top++;
        (*s).memory[(*s).top]= 'X';
        // printf("DS.top= %c\n",(*s).memory[(*s).top]);
        // printf("push\n");
    } else if (stack == 'o'){
        (*s).top--;
    }
}



int PDA(String persamaan){
    Aturan aturan;
    char current;
    Stack s;
    int indeks,temp=0;

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
        // printf("input= %c\n",persamaan[indeks]);
        // printf("top= %c\n",s.memory[s.top]);
        // printf("current= %c\n",current);
        // printf("indeks= %d\n\n",indeks);
        temp=Search(aturan,persamaan[indeks],current,s.memory[s.top]);
        // printf("aturanke= %d\n\n",temp);
        if(temp!=-1){
            DoSomething(&s,aturan.listProduksi[temp].stack);
            current = aturan.listProduksi[temp].stateGo;
            
        }
        indeks++;                         
    }
    if (current == 'a' && s.memory[s.top]=='Z'&& indeks == strlen(persamaan)){
        // printf("accepted\n");
        return 1;
    }else {
        // printf("top= %c\n",s.memory[s.top]);
        // printf("current= %c\n",current);
        // printf("indeks= %d\n",indeks);
        // printf("refused\n");
        return 0;
    }

}