#include <stdio.h>
#include <stdbool.h>
#define MAXPRENOTAZIONI 100
/* il ristorante ha 5 tavoli ognuno da 4 persone, creare una struct prenotazione con: cognome cliente ( char 50 caratteri),numero di ospiti al massimo 4, giorno del mese(30),e turno di tipo enumerativo Pranzo o Cena
il programma permette di vedere se c'e disponibilita, per giorno e turno indicati,inserire nuova prenotazione, stampare giorno con maggiore affluenza di persone
funzioni richieste 
stampaPrenotazioni(prenotazione): 10 aprile-pranzo-4persone ok
verificaDispponibilita(prenotazioni[],giorno,turno) output: bool ok
inserisciPrenotazione(prenotazioni[]):bool ok 
frequenza(prenotazioni[],int  quantitaprenotazioni)
*/
enum turno{
	PRANZO,
	CENA,
};
typedef struct{
	char  cognome[50];
	int persone;
	int giorno;
 turno orario;
}prenotazione;
void stampaPrenotazione(prenotazione prenotazione1);
bool verificaDisponibilita(prenotazione Prenotazioni[],int *giornoScelto,turno *turnoScelto);
bool inserisciPrenotazione(prenotazione Prenotazioni[], int *ptrQuantita);
void frequenza(prenotazione Prenotazioni[], int quantita);




int main(){
	int giorno_scelto=0;
	turno turno_scelto = PRANZO;
	int *ptrGiorno = &giorno_scelto;
	turno *ptrTurno = &turno_scelto;
	int quantitaPrenotazioni = 40;
	int *quantita = &quantitaPrenotazioni;
	prenotazione prenotazioni[MAXPRENOTAZIONI]={
{"Esposito", 1, 1, PRANZO},
{"DeGennaro", 2, 1, PRANZO},
{"Celentano", 2, 1, PRANZO},
{"Mori", 1, 1, PRANZO},
{"Rossi", 2, 1, PRANZO},
{"Bianchi", 1, 6, CENA},
{"Ferrari", 2, 1, CENA},
{"Russo", 1, 1, CENA},
{"Romano", 2, 1, CENA},
{"Gallo", 1, 1, CENA},
{"Conti", 2, 2, PRANZO},
{"Costa", 1, 2, CENA},
{"Fontana", 2, 2, PRANZO},
{"Ricci", 1, 27, CENA},
{"Marino", 2, 13, PRANZO},
{"Greco", 1, 2, CENA},
{"Moretti", 2, 19, PRANZO},
{"Barbieri", 1, 6, CENA},
{"Lombardi", 2, 30, PRANZO},
{"Santoro", 1, 14, CENA},
{"Rossi", 1, 15, PRANZO},
{"Bianchi", 2, 28, CENA},
{"Ferrari", 1, 7, PRANZO},
{"Russo", 2, 14, PRANZO},
{"Romano", 2, 30, PRANZO},
{"Gallo", 1, 12, CENA},
{"Costa", 2, 5, PRANZO},
{"Fontana", 1, 19, CENA},
{"Conti", 1, 25, PRANZO},
{"Marino", 2, 3, PRANZO},
{"Greco", 2, 18, PRANZO},
{"Bruno", 1, 11, PRANZO},
{"Galli", 1, 27, CENA},
{"Rizzi", 2, 9, PRANZO},
{"Santoro", 1, 16, CENA},
{"Ferri", 1, 2, CENA},
{"Caruso", 2, 21, PRANZO},
{"Barbieri", 2, 6, PRANZO},
{"Moretti", 1, 23, PRANZO},
{"Mazza", 2, 8, PRANZO}	
	};
	verificaDisponibilita(prenotazioni,ptrGiorno,ptrTurno);
    inserisciPrenotazione(prenotazioni,quantita);
    frequenza(prenotazioni,quantitaPrenotazioni);
};
void stampaPrenotazione(prenotazione prenotazione1){
	printf("%d Aprile", prenotazione1.giorno);
    if(prenotazione1.orario ==0){
    	printf("-pranzo");
	}else{
		printf("-cena");
	}
	printf("-%d persone\n",prenotazione1.persone);
}
bool verificaDisponibilita(prenotazione Prenotazioni[],int *giornoScelto,turno *turnoScelto){
	int giorno;
	turno turnodeciso;
	int posti=5;
    bool controllo = true;
	do{
		if(controllo == false)
		printf("scegli delle opzioni valide\n");
	printf("scegli un giorno\n");
	scanf("%d", &giorno);
	printf("scegli un turno:\n");
	printf("1. Pranzo\n");
	printf("2. Cena\n");
	scanf("%d", &turnodeciso);
	if(giorno > 30 || giorno<1 ||turnodeciso <1 || turnodeciso>2){
	controllo = false;
	}else{
		controllo = true;
	};
	}while(controllo==false);
	if(turnodeciso==1){
		turnodeciso = PRANZO;
	}else{
		turnodeciso= CENA;
	}
	for(int i =0; i<MAXPRENOTAZIONI;i++){
		if(Prenotazioni[i].giorno==giorno){
			if(Prenotazioni[i].orario == turnodeciso){
				posti=posti-1;
			}
		}
	};
	*giornoScelto = giorno;
	*turnoScelto = turnodeciso;
	if(posti<=0){
		printf("non c'e disponibilita per il giorno %d aprile\n", *giornoScelto);
		return false;
	}else{
		printf("c e disponibilita per il giorno scelto\n");
		return true;
	}
	
}
bool inserisciPrenotazione(prenotazione Prenotazioni[], int *ptrQuantita){
	int giorno=7;
	turno orario=PRANZO;
	int *ptrGiorno  = &giorno;
	turno* ptrOrario = &orario;
	bool possibilita=verificaDisponibilita(Prenotazioni,ptrGiorno,ptrOrario);
	if(possibilita == true){
		printf("qual'e  il cognome del cliente:\n");
		scanf("%s", &Prenotazioni[*ptrQuantita].cognome);
		printf("quante persone:\n");
		scanf("%d", &Prenotazioni[*ptrQuantita].persone);
		Prenotazioni[*ptrQuantita].giorno = giorno;
		Prenotazioni[*ptrQuantita].orario = orario;
		prenotazione Prenotazione = Prenotazioni[*ptrQuantita];
		printf("ecco i dettagli della tua prenotazione:\n");
		stampaPrenotazione(Prenotazione);
		*ptrQuantita = *ptrQuantita+1;
		
		return true;
	}else{
		printf("Non e possibile prenotare per il giorno scelto\n");
		return false;
	}
}
void frequenza(prenotazione Prenotazioni[],int quantita){
	const int MESE= 30;
	typedef struct{
		int giorno;
		int frequenza;
	}giornata;
	giornata giorni[MESE]={
	{1,0},
	{2,0},
	{3,0},
	{4,0},
    {5,0},
    {6,0},
	{7,0},
	{8,0},
	{9,0},
    {10,0},
    {11,0},
	{12,0},
	{13,0},
	{14,0},
    {15,0},
    {16,0},
	{17,0},
	{18,0},
	{19,0},
    {20,0},
    {21,0},
	{22,0},
	{23,0},
	{24,0},
    {25,0},
    {26,0},
    {27,0},
	{28,0},
	{29,0},
	{30,0},
};
    for(int n=0;n<MESE;n++){
    	for(int i=0;i<quantita;i++){
    		if(Prenotazioni[i].giorno ==giorni[n].giorno){
    			giorni[n].frequenza= giorni[n].frequenza+1;
			}
		}
	}
for(int n=0;n<MESE;n++){
	for(int i=0;i<MESE;i++){
		if(giorni[n].frequenza>giorni[i].frequenza){ 
			giornata t=giorni[n];
			giorni[n]=giorni[i];
			giorni[i]=t;
		}
	}
}
	printf("i giorni dove il ristorante e piu occupato sono:\n");
	for(int i=0;i<3;i++){
		printf("%d. %d Aprile,  frequenza: %d\n", i+1,giorni[i].giorno,giorni[i].frequenza);
		
	} 
}
