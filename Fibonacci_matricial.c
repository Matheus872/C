#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* OBS: pelo que eu vi, se for rodar o programa no linux, tem que mudar o
   "I64d", que está na linha 28 por "lld"
*/


long long int fibonacci(int n);
void multiplica_mtr(long long int mtr1[2][2], long long int mtr2[2][2], long long int mtr_res[2][2]);



int main(){
	
	clock_t Ticks[2];		
	
	int n;
	long long int resposta;
	
	scanf("%d", &n);
	
	Ticks[0] = clock();
	resposta = fibonacci(n);
	Ticks[1] = clock();	
	
	printf("%I64d\n", resposta);
	
	double tempo = (Ticks[1]-Ticks[0])*1000.0/CLOCKS_PER_SEC;
	printf("Tempo gasto: %g ms.",tempo);
	
	return 0;
}



long long int fibonacci(int n){
	
	if(n < 2){
		return n;
	}
	
	long long int mtr_base[2][2] = {{0, 1},{1, 1}};
	long long int mtr_pa[2][2] = {{1, 0}, {0, 1}};
	
	while(n > 0){
		
		if((n%2) != 0){
			multiplica_mtr(mtr_pa, mtr_base, mtr_pa);
		}
		
		multiplica_mtr(mtr_base, mtr_base, mtr_base);
		n = n/2;
	}
	
	return mtr_pa[0][1];	
}


void multiplica_mtr(long long int mtr1[2][2], long long int mtr2[2][2], long long int mtr_res[2][2]){
	
	long long int mtr_aux[2][2];
	
	mtr_aux[0][0] = mtr1[0][0] * mtr2[0][0] + mtr1[0][1] * mtr2[1][0];  	
	mtr_aux[0][1] = mtr1[0][0] * mtr2[0][1] + mtr1[0][1] * mtr2[1][1];						 	
	mtr_aux[1][0] = mtr1[1][0] * mtr2[0][0] + mtr1[1][1] * mtr2[1][0];
	mtr_aux[1][1] = mtr1[1][0] * mtr2[0][1] + mtr1[1][1] * mtr2[1][1];
	mtr_res[0][0] = mtr_aux[0][0];
	mtr_res[0][1] = mtr_aux[0][1];
	mtr_res[1][0] = mtr_aux[1][0];
	mtr_res[1][1] = mtr_aux[1][1];
	return;
}

/*

00  =00	*00	+01 *10
01	00	01	01	11
10	10	00	11	10
11	10	01	11	11

*/



