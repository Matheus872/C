#include<stdio.h>
#include<stdbool.h>
#include<time.h>


bool subset_sum(int *vet, int n, int sum);


bool main(){
	
	clock_t Ticks[2];
	int tamanhos[] = {1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
	int custos [] = {5, 20, 40, 70, 90, 110};
	int i, j, k, x, n, *vet;
	bool y;
	
	Ticks[0] = clock();
	for(i=0;i<11;i++){
		x = tamanhos[i];
		vet = (int*)malloc(x*sizeof(int));
		n = sizeof(vet)/sizeof(vet[0]);
		for(k=0;k<n;k++){
			vet[k] = rand() %20;
		}
		
		for(j=0;j<6;j++){
			y = subset_sum(vet, n,custos[j]);
		}
	}
	Ticks[1] = clock();
	double tempo = (Ticks[1]-Ticks[0])*1000.0/CLOCKS_PER_SEC;
	printf("Tempo gasto: %g ms.",tempo);
	return 0;
}


bool subset_sum(int *vet, int n, int sum){
	
	if(sum == 0){
		return true;
	}
	if(n==0 && sum !=0){
		return false;
	}
	
	if(vet[n-1] > sum){
		return subset_sum(vet, n-1, sum);
	}
	
	return subset_sum(vet, n-1, sum) || subset_sum(vet, n-1, sum - vet[n-1]);
}

