#include <stdio.h>

int main(void){
	int a = 10;
	int c;
	int *p;
	p = &c;
	*p = 12;
	int **q = &p;
	int x;
	x = a + **q;
	printf("%d\n", x);
	//*/	
	int M[3] = {10, 12, 33};
	int *p1, *p2;
	p1 = M;
	p2 = M + 2;
	int z = *p1 + *p2;
	p2--;
	(*p2)--;
	printf("%d %d\n", z, *p2);
	//*/
}
