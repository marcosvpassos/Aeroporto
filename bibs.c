#include <stdio.h>
#include <stdlib.h>
typedef struct aviao{
    int x,y,z;
    struct aviao* prox;

}aviao;
typedef struct pista{
    aviao *head;
    struct pista* prox;
}pista;
//*****************************************
//FUNÇÕES NO AEROPORTO
void addfPista(pista** a){
	if(!(*a)){
        *a=(pista*)malloc(sizeof(pista));
		(*a)->prox=*a;
		(*a)->head=NULL;
        return;
	}
		pista* ult=*a;
		pista* novo=malloc(sizeof(pista));

		novo->prox=ult->prox;
		ult->prox=novo;
		novo->head=NULL;
		*a=novo;
	return;
}

void addpin(pista** a,int pos){
	if(!(*a))return;
	int i;
		pista *novo=malloc(sizeof(pista)),*ult=*a;
		for(i=0;i<pos;i++){//achar pista correta
			a=&((*a)->prox);
			if(ult==*a)return;
		}
		novo->prox=(*a)->prox;
		(*a)->prox=novo;
		novo->head=NULL;
	return;
}

void addfAviao(pista** a,int pos,aviao info){
    if(!(*a))return;
	int i;
    // entra na pista correta
	pista *ult=*a;
		for(i=0;i<=pos;i++){//achar pista correta
			a=&((*a)->prox);
			if((ult==*a)&&i!=pos)return;
		}
    aviao* ultavi=(*a)->head;
    aviao* novo=malloc(sizeof(aviao));
    // adiciona o avião
	if(!ultavi){
		novo->prox=novo;
        (*a)->head=novo;
	}
    else {
		novo->prox=ultavi->prox;
        ultavi->prox=novo;
        (*a)->head=novo;
    }
		novo->x=(info.x);novo->y=(info.y);novo->z=(info.z);
	return;
}

void delPista(pista** b,int n){//não deleta o ultimo
    if(!*b||n<0)return;
    int i;
    pista**a=b;
    pista* res=*a,*ult=*a;
    for(i=0;i<n;i++){//achar pista correta
        a=&((*a)->prox);
        if((*a)==ult)return;
    }
    res=(*a)->prox;
    if(res->head)return;
    if(res==(*a))*b=NULL;
    if(res==ult)*b=(pista*)a;//problemas para incluir o ultimo, eu desisto
    else (*a)->prox=res->prox;
    free(res);
    return;
}

void delAviao(pista** a,int n){
    if(!*a||n<0)return;
    int i;
    pista* ult=*a;//ultima pista

    a=&((*a)->prox);
    for(i=0;i<n;i++){//achar pista correta
        if((ult==(*a)))return;
        a=&((*a)->prox);
    }
    if(!(*a)->head)return;//verificar se há avioes
//deletar avioes
    aviao* prim=((*a)->head)->prox;
    if((*a)->head==prim){//caso só tenha 1 aviao
        free((*a)->head);
        (*a)->head=NULL;
        return;
    }//caso tenha mais
    ((*a)->head)->prox=prim->prox;
    free(prim);
    return;
}

aviao* info(pista* a,int n,int posA){//devolve aviao para ver informacoes
    if(n<0||posA<0||!a)return NULL;
    pista* ult=a;
    int i;

    a=a->prox;
    for(i=0;i<n;i++){
        if(ult==a)return NULL;
    	a=a->prox;
    }
    aviao* ultavi=a->head;
    aviao* prim=ultavi->prox;

    for(i=0;i<posA;i++){
        if(ultavi==prim)return NULL;
    	prim=prim->prox;
    }

    return prim;
}

void imprime(pista* a){
    printf("\e[1;32mAeroporto:\n");
    if(!a){printf("vazia!\e[0m\n");return;}
    pista* ult=a;
    int i=0;
    do{
        a=a->prox;
        printf("Pista %d:\n",i+1);
        if(a->head){
            aviao* avi=a->head;
            aviao* ultavi=a->head;
            do{
                avi=avi->prox;
                printf("%d %d %d\n",avi->x,avi->y,avi->z);
            }while(avi!=ultavi); 
        }
        else printf("vazia!\n");
        printf("\n");
        i++;

    }while(a!=ult);
    printf("\e[0m");
    return;
}

//*****************************************************************
//FUNÇÕES NO VOO
void addV(aviao** a,aviao info){
    aviao* ult=*a;
    aviao* novo=malloc(sizeof(aviao));
    // adiciona o avião
	if(!ult){
		novo->prox=novo;
        *a=novo;
	}
    else {
		novo->prox=ult->prox;
        ult->prox=novo;
        *a=novo;
    }
		novo->x=(info.x);novo->y=(info.y);novo->z=(info.z);
	return;
}

void delV(aviao** a){
    if(!*a)return;

//deletar avioes
    aviao* prim=(*a)->prox;
    if((*a)==prim){     //caso só tenha 1 aviao
        free(*a);
        (*a)=NULL;
        return;
    }                   //caso tenha mais
    (*a)->prox=prim->prox;
    free(prim);
    return;
}

aviao* infoV(aviao* a,int posA){//devolve aviao para ver informacoes
    if(posA<0||!a)return NULL;
    aviao* ult=a;
    aviao* prim=a->prox;
    int i;

    for(i=0;i<posA;i++){
        if(ult==prim)return NULL;
    	prim=prim->prox;
    }
    return prim;
}

void imprimeV(aviao* avi){
    printf("\e[1;32mVoando:\n");
    if(!avi){printf("Nenhum!\e[0m\n");return;}
    aviao* ult=avi;

    do{
        avi=avi->prox;
        printf("%d %d %d\n",avi->x,avi->y,avi->z);
    }while(avi!=ult);

    printf("\e[0m");
    return;
}
