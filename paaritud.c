#include <stdio.h>
#include <stdlib.h>

void kuva(int n, int M[n], const char *msg){
	printf("\n%s\n", msg);
	for(int i = 0; i < n; i++)
		printf("%4d ", M[i]);
	printf("\n");
}

int leiaPaaritud(int n, int M[], int P[]){
	int i = 0, k = 0;
	for( ; i < n; i++){
		int x = M[i];
		if(M[i] % 2 != 0){ //paaritu
			P[k] = x;
			k++;
		}
	}
	return k;
}

#define N 10

int main(void){
	int Arvud[N] = {13, 22, -7, 8, 3, 4, 0, -11, 28, 3};
	int Paaritud[N]; // oletame, et sama pikk
	int k = leiaPaaritud(N, Arvud, Paaritud);
	kuva(N, Arvud, "Arvud");
	kuva(k, Paaritud, "Paaritud");
}
