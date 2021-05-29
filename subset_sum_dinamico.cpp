#include<stdio.h>
#include<stdlib.h>

bool subset_sum(int *vet, int n, int sum);


int main(){
	
	int vet[] = {4,2,1,3};
	int sum = 5;
	int n = sizeof(vet)/sizeof(vet[0]);
	
	return subset_sum(vet, n, sum);

}

bool subset_sum(int *vet, int n, int sum){
	
	int i, j, b;
	int tabela[n][sum];
	
	for(i=0;i<=n;i++){
		tabela[i][0] = 1;		
	}
	
	for(j=1;j<=sum;j++){
		
		tabela[0][j] = 0;
		
		for(i=1;i<n;i++){
			
			b = tabela[i-1][j];
			
			if(b == 0 && vet[i] <= j){
				
				b = tabela[i-1][j-vet[i]];
			}
			
			tabela[i][j]= b;
		}
	}
	
	return tabela[n][sum];
}

