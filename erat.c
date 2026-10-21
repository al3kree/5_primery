#include <stdio.h>
#include <stdlib.h>

int loepikkus(void){
	printf("Sisesta massiivi pikkus: ");
	int x;
	if(scanf("%d", &x) < 1){
		printf("Pikkuse lugemine ebaõnnestus.\n");
		exit(0);
	}
	if(x <= 1){
		printf("Pikkus peab olema suurem kui 1.\n");
		exit(0);
	}
	return x;
}

#define ALGUS 2

void erat(int n, char M[]){
	int i;
	for(i = 0; i < ALGUS && i < n; i++)
		M[i] = 0;
	if(n < ALGUS)
		return;
	for(i = ALGUS; i < n; i++)
		M[i] = 1; // oletame, et on algarv	
	for(i = ALGUS; i * i < n; i++){
		if(M[i] == 0) // ei ole
			continue; 
		for(int j = i * i; j < n; j = j + i)
			M[j] = 0; // j ei saa olla algarv
	}
}

void kuva(int n, char M[]){
	int count = 0;
	for(int i = 0; i < n; i++)
		if(M[i] == 1){
			printf("%4d\n", i);
			count++;
		}
	printf("Kokku %d algarvu.\n", count);
}

int main(void){
	int n = loepikkus();
	n++; // teeme ühe võrra pikemaks, et max väärtus ära mahuks
	char arvud[n];
	erat(n, arvud);
	kuva(n, arvud);
}
