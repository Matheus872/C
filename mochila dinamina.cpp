#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int mochila(int peso_max, int n, int *pesos, int *valores);
int maior(int a, int b){return (a>b)? a:b;}
int* popula(int n);

int main(){
	clock_t Ticks[2];
	int *valores, *pesos, peso_max, n, resultado;
	register int i;
	printf("Entre com o numeros de objetos e o peso maximo (x y)\n");
	scanf("%d %d",&n ,&peso_max);
	printf("Pesos: ");
	pesos = popula(n);
	printf("Valores: ");
	valores = popula(n);
	Ticks[0] = clock();
	Ticks[1] = clock();
	resultado = mochila(peso_max, n, pesos, valores);
	printf("\nresultado: %d\n\n",resultado);
	double tempo = (Ticks[1]-Ticks[0])*1000.0/CLOCKS_PER_SEC;
	printf("Tempo gasto: %g ms.",tempo);
	system("pause");
	return 0;
}

int mochila(int peso_max, int n, int *pesos, int *valores){
	
register int i, w;
int K[n+1][peso_max+1];

for(i=0;i<=n;i++){
	for(w=0;w<=peso_max;w++){
		if(i == 0 || w == 0){
			K[i][w] = 0;
		}else if(pesos[i-1] <= w){
			K[i][w] = maior(valores[i-1]+K[i-1][w-pesos[i-1]], K[i-1][w]); 
		}else
		K[i][w] = K[i-1][w];
	}
}
return K[n][peso_max];
}

int* popula(int n){
	
	int *novo;
	register int i;
	novo = (int*)malloc(n*sizeof(int*));
	printf("[");
	for(i=0;i<n;i++){
		novo[i] = rand() %10;
		printf("%d ",novo[i]);
	}
	printf("] ");
	return novo;
}
