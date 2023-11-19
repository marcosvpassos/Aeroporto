#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aviao{
    int codigo;
    char modelo[10];
    char destino[10];
    int distancia;
    int tempo_de_voo;
    int x;
    int y;
    int z;
    int velocidade;
    int estado;
    
    struct aviao* prox;

}aviao;

typedef struct pista{
    aviao *head;
    struct pista* prox;
}pista;

void criar_pista(pista** a);
void add_to_pista(pista** a,int pos,int codigo, char modelo[], char destino[], int distancia, int tempo_de_voo);
void del_pista(pista** a,int pos);
void rem_from_pista(pista** a,int pos);
void imprime_pista(pista* a);
void add_aviao(aviao** a, int codigo, char modelo[], char destino[], int distancia, int tempo_de_voo);
void del_aviao(aviao** a,int pos);
void del_all_aviao(aviao** a);
void del_all_pista(pista** a);
void imprime_aviao(aviao* a);

//*****************************************
void criar_pista(pista** a){
    pista* novo=malloc(sizeof(pista));
	if(!*a){
        *a=novo;
	}
    else{
        while((*a)->prox){
            a=&((*a)->prox);
        }
        (*a)->prox=novo;
    }
    novo->prox=NULL;
    novo->head=NULL;
}

void add_to_pista(pista** a,int pos,int codigo, char modelo[], char destino[], int distancia, int tempo_de_voo){
    if(!(*a))return;
	int i;
		for(i=0;i<pos;i++){//achar pista correta
			a=&((*a)->prox);
			if(!*a)return;
		}
    // adiciona o avião
    add_aviao(&((*a)->head), codigo, modelo, destino, distancia, tempo_de_voo);
}

void del_pista(pista** a,int pos){
    if(!*a||pos<0)return;
    int i;
    pista *aux;

    for(i=0;i<pos;i++){//achar pista correta
        a=&((*a)->prox);
        if(!*a)return;
    }
    aux=*a;

    if(aux->head)return;//se tiver aviões na pista

    *a=aux->prox;//remover elemento
    free(aux);
}

void rem_from_pista(pista** a,int pos){
    if(!*a||pos<0)return;
    int i;

    for(i=0;i<pos;i++){//achar pista correta
        a=&((*a)->prox);
        if(!*a)return;
    }
  
    if(!((*a)->head))return;//verificar se há aviao

    del_aviao(&((*a)->head), 0);
}

void imprime_pista(pista* a){
    printf("\e[1;32mAeroporto:\n");
    if(!a){printf("vazio!\e[0m\n");return;}
    int cont=0;

    while(a){ 
        printf("\e[1;32mPista %d:\n",cont+1);
            imprime_aviao(a->head);
        printf("\n");
        cont++;a=a->prox;
    }
    printf("\e[0m");
}

void add_aviao(aviao** a, int codigo, char modelo[], char destino[], int distancia, int tempo_de_voo){
    aviao *novo = malloc(sizeof(aviao));
	if(!*a){
		*a=novo;
	}
    else {
        while((*a)->prox){
            a=&((*a)->prox);
        }
		(*a)->prox=novo;
    }
        novo->prox=NULL;
		novo->x=0;novo->y=0;novo->z=0;
        novo->codigo=codigo;
        strcpy(novo->modelo, modelo);
        strcpy(novo->destino, destino);
        novo->distancia=distancia;
        novo->tempo_de_voo=tempo_de_voo;
        novo->velocidade=0;
        novo->estado=0;
}

void del_aviao(aviao** a, int pos){
    if(!*a||pos<0)return;
    int i;
    aviao* aux;

    for(i=0;i<pos;i++){//achar pista correta
        a=&((*a)->prox);
        if(!*a)return;
    }
    aux=*a;

    *a=aux->prox;//remover elemento
    free(aux);
}

void del_all_aviao(aviao**a){
    if(!*a)return;
    aviao *aux=(*a)->prox,*aux1;
    free(*a);
    *a=NULL;

    while (aux){
        aux1=aux->prox;
        free(aux);
        aux=aux1;
    }
}
void del_all_pista(pista** a){
    if(!*a)return;
    pista *aux=(*a)->prox,*aux1;
    del_all_aviao(&((*a)->head));
    free(*a);
    *a=NULL;

    while (aux){
        aux1=aux->prox;
        del_all_aviao(&(aux->head));
        free(aux);
        aux=aux1;
    }
}

void imprime_aviao(aviao* a){
    printf("\e[1;32m");
    if(!a){printf("vazia!\e[0m\n");return;}
 
    for(;a;){
        printf("%d ",a->codigo);
        printf("%s ",a->modelo);
        printf("%s ",a->destino);
        printf("%d ",a->distancia);
        printf("%d ",a->tempo_de_voo);
        printf("%d ",a->x);
        printf("%d ",a->y);
        printf("%d ",a->z);
        printf("%d ",a->velocidade);
        printf("%d\n",a->estado);

        a=a->prox;
    }
    printf("\e[0m");
    return;
}
