#include <stdio.h>
#include <stdbool.h>
#define MAX 5
#define STORAGE 4
int magazzino[MAX]={2,3,4,5};
int occupati = STORAGE;
bool inserisciElemento(int nuovoElemento){
    if(occupati == MAX){
        printf("magazzino pieno.\n");
        return false;
    };
    magazzino[occupati]=nuovoElemento;
    occupati++;
    return true;
};
bool eliminaElemento(){
    if(occupati==0){
      printf("la pila e vuota\n");
      return false;
    };
    occupati--;
    return true;
    
    
}
int main(){
   eliminaElemento();
   for(int i =0;i<occupati;i++){
       printf("%d ", magazzino[i]);
   }
    
    return 0;
}
