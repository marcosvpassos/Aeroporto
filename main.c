#include<stdio.h>
#include<stdlib.h>
#include"bibs.h"

int main(){
    pista* aeroporto=NULL;
    aviao* ceu=NULL;
    criar_pista(&aeroporto);
    criar_pista(&aeroporto);
    criar_pista(&aeroporto);
    criar_pista(&aeroporto);
    criar_pista(&aeroporto);

    add_to_pista(&aeroporto,0,1,"A230","ES",300000,2);
    add_to_pista(&aeroporto,2,2,"B400","RUSSIA",20,10000);

    imprime_pista(aeroporto);

    return 0;
}