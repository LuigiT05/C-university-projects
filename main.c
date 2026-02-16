//oragnizzazione di un array con Sort;
#include <stdio.h>
void sistema(int array[],int dimensione);
int main()
{
	int dimensione = 9;
	int array[]= {1,3,5,7,9,2,4,6,8};
	sistema(array,dimensione);
	for(int i=0; i<dimensione; i++) {
		printf("%d", array[i]);
	}

	return 0;
}
void sistema(int array[],int dimensione) {
	for(int n=0; n<dimensione; n++) {
		for(int i=0; i<dimensione-1; i++) {
			if(array[n]<array[i]) {
				int t = array[n];
				array[n]=array[i];
				array[i]=t;
			}
		}
	}
}


