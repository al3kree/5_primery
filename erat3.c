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

const unsigned char maskoff[8] = { 
	0b11111110, 0b11111101, 0b11111011, 0b11110111, 
	0b11101111, 0b11011111, 0b10111111, 0b01111111 }; // nullimiseks
const unsigned char maskon[8]  = { 
	0b00000001, 0b00000010, 0b00000100, 0b00001000, 
	0b00010000, 0b00100000, 0b01000000, 0b10000000 }; // kontrollimiseks

#define ALGUS 2
#define SHIFT 3
#define OFFSET(a) i2 = a >> SHIFT; j2 = a & 0b111;

int erat(int n, char M[]){
	int i;
	int count = 0;
	int i2, j2;
	for(i = 0; i < ALGUS && i < n; i++){
		OFFSET(i) // see on makro
		M[i2] = M[i2] & maskoff[j2];
	}
	if(n < ALGUS)
		return 0;
	for(i = ALGUS; i < n; i++){
		OFFSET(i) 
		M[i2] = M[i2] | maskon[j2]; // oletame, et on algarv
	}
	for(i = ALGUS; i * i < n; i++){
		OFFSET(i)
		if((M[i2] & maskon[j2]) == 0) // ei ole
			continue; 
		for(int j = i * i; j < n; j = j + i){
			OFFSET(j)
			M[i2] = M[i2] & maskoff[j2]; // j ei saa olla algarv
			count++;
		}
	}
	return count;
}

void kuva(int n, char M[]){
	int count = 0;
	int i2, j2;
	for(int i = 0; i < n; i++){
		OFFSET(i)
		if((M[i2] & maskon[j2]) > 0){
			printf("%4d\n", i);
			count++;
		}
	}
	printf("Kokku %d algarvu.\n", count);
}

int main(void){
	int n = loepikkus();
	n++; // teeme ühe võrra pikemaks, et max väärtus ära mahuks
	int n2 = n >> SHIFT;
	n2++; // teeme ühe võrra pikemaks, et poolik bait ära mahuks
	char arvud[n2];
	int c = erat(n, arvud);
	kuva(n, arvud);
	printf("Vaja läks %d operatsiooni\n", c);
}