#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/* OBS: pelo que eu vi, se for rodar o programa no linux, tem que mudar o
   "I64d", que está na linha 20 por "lld"
*/


long long int fibonacci(int n);



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
	
	if(n < 0){
		return -1;  //Erro, ñ tem fibonacci -1
	}
	
	if(n < 2){
		return n;
	}
	
	return fibonacci(n-1)+fibonacci(n-2);	
}

