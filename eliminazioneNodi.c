#include <stdlib.h>
#include <stdio.h>
struct nodo{
    int data;
    struct nodo *next;
};
int eliminaNodo(struct nodo **testa,int key){ //passo l'indirizzo di testa e una key che identifica l'elemento da eliminare.
       struct nodo *nodoEliminato = *testa;
       struct nodo *salto = NULL;
       if(nodoEliminato->data ==key){
           *testa=nodoEliminato->next;   //cambio testa in nodo2 ;)
            printf("nodo eliminato con successo\n");
           return 0;
           
          
           
       }
       while(nodoEliminato !=NULL && nodoEliminato->data !=key){
           salto=nodoEliminato;        
           nodoEliminato=nodoEliminato->next;  
       };
       if(nodoEliminato !=NULL){
           salto->next=nodoEliminato->next;
           free(nodoEliminato);
           printf("nodo eliminato con successo\n");
           return 0;
       };
       if(nodoEliminato ==NULL){
           printf("il nodo che stai cercando di eliminare non esiste\n");
       }
};
void stampaNodi(struct nodo *testa){
    while(testa !=NULL){
        printf("%d\n", testa->data);
        testa=testa->next;
    }
}
int main()
{
    struct nodo *testa;
    struct nodo *nodo1;
    struct nodo* nodo2;
    struct nodo* nodo3;
    nodo1=(struct nodo*)malloc(sizeof(struct nodo));
    nodo2=(struct nodo*)malloc(sizeof(struct nodo));
    nodo3=(struct nodo*)malloc(sizeof(struct nodo));
    testa=nodo1;
    nodo1->next=nodo2;
    nodo2->next=nodo3;
    nodo3->next=NULL;
    nodo1->data =20;
    nodo2->data=10;
    nodo3->data=16;
    eliminaNodo(&testa,20);
    stampaNodi(testa);
    

    return 0;
}
