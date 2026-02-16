//liste concatenate;
#include <stdio.h>
#include <stdlib.h>
struct nodo{
    int data;
    struct nodo *next;
};
void stampaNodi(struct nodo *head){
    while(head !=NULL){
        printf("d=%d\n", head->data);
        head=head->next;
    };
}
void aggiungiNodo(struct nodo **head){   //puntatore di puntatore
    struct nodo *nodo0=NULL;
    nodo0=(struct nodo*)malloc(sizeof(struct nodo));
    if(nodo0==NULL){
        printf("vaffanculo");
    }
    nodo0->data=32;
    nodo0->next = (*head);   //nodo0.next punta a  l'indirizzo di testa head(nodo1)
    (*head)=nodo0;    //ora l'indirizzo di testa == nodo0, quindi la costruzione sara del tipo head->nodo0->nodo1 
}
int ricercaValore(struct nodo **head,int valore){ //passiamo l'indirizzo del puntatore testa e il valore da cercare 
    struct nodo *cercatore = (*head);  //creiamo un nuovo puntatore che punta al puntatore head, in modo che abbia i suoi stessi valori,
    while(cercatore !=NULL){  //finquando cercatore non e null
        if(cercatore->data==valore){  //se il valore di cercatore e uguale al valore cercato allora il programma finisce
            return 1;
        }
        cercatore=cercatore->next; //cercatore= head= nodo1, okay nodo1=(nodo1->next)=nodo2 e cosi via;
    }
    return 0;
}
int main()
{
    struct nodo*testa;
    struct nodo *nodo1 = NULL;
    struct nodo *nodo2 =NULL;
    struct nodo*nodo3 =NULL;
    nodo1 = (struct nodo*)malloc(sizeof(struct nodo)); //alloco la memoria al puntatore 
    nodo2 = (struct nodo*)malloc(sizeof(struct nodo));  //alloco la memoria al puntatore
    nodo3 = (struct nodo*)malloc(sizeof(struct nodo)); //alloco memroia al puntatore
    if(nodo1 ==NULL || nodo2 ==NULL ||nodo3== NULL){
        printf("operazione non riuscita");
        return 10;
    };
    nodo1->data=20;
    nodo2->data=30;
    nodo3->data=40;
    testa=nodo1; //l'indirizzo della testa diventa uguale a quello di nodo1;
    nodo1->next=nodo2;// il puntatore next presente in nodo1 punta a nodo2;
    nodo2->next=nodo3;
    nodo3->next=NULL;
   // aggiungiNodo(&testa); //passo l'indirizzo di un puntatore
   // stampaNodi(testa);
    int valoreCercato;
    scanf("%d",&valoreCercato);
   if( ricercaValore(&testa,valoreCercato)){
       printf("valore trovato");
   }else{
       printf("valore non trovato");
   }
    
    
    
    return 0;
}
