#include<stdio.h>
#include<stdlib.h>

int mochila(int peso_max, int n, int *pesos, int *valores);
int maior(int a, int b){return (a>b)? a:b;}
int* popula(int n);

int main(){
	
	int *valores, *pesos, peso_max, n, resultado;
	register int i;
	printf("Entre com o numeros de objetos e o peso maximo (x y)\n");
	scanf("%d %d",&n ,&peso_max);
	printf("Pesos: ");
	pesos = popula(n);
	printf("Valores: ");
	valores = popula(n);
	resultado = mochila(peso_max, n, pesos, valores);
	printf("\nresultado: %d\n\n",resultado);
	system("pause");
	return 0;
}

int mochila(int peso_max, int n, int *pesos, int *valores){
	
	if(n==0||peso_max==0){
		return 0;
	}
	
	if(pesos[n-1]>peso_max){
		return mochila(peso_max, n-1, pesos, valores);
	}else{
		return maior(valores[n-1]+ mochila(peso_max-pesos[n-1], n-1, pesos, valores),
					 mochila(peso_max, n-1, pesos, valores));        
	}
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





