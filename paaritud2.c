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

int main(void){
	int n;
	printf("Sisesta massiivi pikkus: ");
	if(scanf("%d", &n) < 1 || n < 1) // kriitiline, et lugemine õnnestuks ja n oleks vähemalt 1
		return 0;
	int Arvud[n];
	int Paaritud[n]; // oletame, et sama pikk
	printf("Sisesta elemendid: ");
	for(int i = 0; i < n; i++)
		scanf("%d", &Arvud[i]);
	int k = leiaPaaritud(n, Arvud, Paaritud);
	kuva(n, Arvud, "Arvud");
	kuva(k, Paaritud, "Paaritud");
}
