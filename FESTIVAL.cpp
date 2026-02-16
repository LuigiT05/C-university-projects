/*struttura dati scaletta che contiene l'elenco delle esibizioni e per ciascuna struttura dai esibizione memorizzare i seguenti campi:
-nome del gruppo [50]
-sottogenere (THRASH,DEATH,EPIC,PROGRESSIVE,NU)
-UN VETTORE DI 3 VOTI:
MUSICA(FLOAT),TESTO,COINVOLGIMENTO
FUNZIONI POSSIBILI
-INSERISCI NUOVA ESIBIZIONE
-STAMPA PER SOTTOGENERE
-STAMPA IL MIGLIORE PER SOTTOGENERE
BONUS LISTA A PUNTATORI */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define NUMEROBAND 100
#define MAXCHAR 50
#define MAXVOTI 3
enum sottogeneri{
	THRASH,
	DEATH,
	EPIC,
	PROGRESSIVE,
	NU,
};
typedef struct{
	char nomeband[MAXCHAR];
	sottogeneri sottogenere;
	float voti[MAXVOTI];
}esibizioni;
struct gruppo{
	esibizioni esibizione;
	struct gruppo*next;
};
int inserimentodati(struct gruppo **head){  //passiamo l'indirizzo di un puntatore(puntatore di puntatore)(&head)
	esibizioni datiBand[8]={
		{"Screaming Shadows", THRASH, {8.5, 7.2, 9.0}},
        {"Eternal Agony", DEATH, {9.0, 8.7, 7.5}},
        {"Thunderstorm", EPIC, {7.8, 9.5, 8.2}},
        {"Metal Titans", PROGRESSIVE, {8.0, 8.0, 8.0}},
        {"Dark Symphony", NU, {7.5, 9.0, 7.8}},  
        {"Chaos Reign", THRASH, {8.2, 7.8, 8.5}},
        {"Bloodbath", DEATH, {9.5, 8.9, 7.0}},
        {"Immortal Legion", EPIC, {8.7, 8.3, 8.8}},
	};
	struct gruppo *concatena= *head;  //creo un nuovo puntatore che punta ad head
    for(int i=0;i<8;i++){
    	concatena->esibizione = datiBand[i]; //  concatena->esibizione e un dato, non un indirizzo equavale a scrivere (*head)->esibizione=...
    	concatena=concatena->next; // l'indirizzo di concatena diventa uguale a quello di concatena->next che e uguale a nodo2....
    	//il metodo utilizzando head non si puo fare perche alla head e uguale a null
	}
	return 0;
}
bool stampaValori(struct gruppo *head){
	while(head !=NULL){  //finquando l'indirizzo di head non e nullo l'operazione prosegue
	printf("%s %.2f %.2f %.2f\n", head->esibizione.nomeband, head->esibizione.voti[0],head->esibizione.voti[1],head->esibizione.voti[2]);
	head=head->next;  //l'indirizzo di head diventa uguale ad un altro puntatore (next) che nel main e dichiarato come l'indirizzo del nodo successivo
	}
	return true;
}

int main(){
    struct gruppo*testa;
	struct gruppo*nodo1,*nodo2,*nodo3,*nodo4,*nodo5,*nodo6,*nodo7,*nodo8 = NULL;
	nodo1= (struct gruppo*)malloc(sizeof(struct gruppo));
	nodo2 = (struct gruppo*)malloc(sizeof(struct gruppo));
	nodo3 = (struct gruppo*)malloc(sizeof(struct gruppo));
	nodo4 = (struct gruppo*)malloc(sizeof(struct gruppo));
	nodo5 = (struct gruppo*)malloc(sizeof(struct gruppo));
	nodo6 = (struct gruppo*)malloc(sizeof(struct gruppo));
	nodo7 = (struct gruppo*)malloc(sizeof(struct gruppo));
	nodo8 = (struct gruppo*)malloc(sizeof(struct gruppo));
	if(nodo1 == NULL || nodo2 == NULL || nodo3 == NULL || nodo4==NULL || nodo5 == NULL || nodo6 == NULL || nodo7 == NULL || nodo8 == NULL ){
		printf("operazione non riuscita");
		return 5;
	}
	testa = nodo1;
	nodo1->next = nodo2;
	nodo2->next = nodo3;
	nodo3->next = nodo4;
	nodo4->next = nodo5;
	nodo5->next = nodo6;
	nodo6->next=nodo7;
	nodo7->next=nodo8;
	nodo8->next=NULL;
	inserimentodati(&testa);
	stampaValori(testa);
	return 0;
	
}
