#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>


void mergesort(int* v, int inicio, int fim);
void merge(int* v, int inicio, int meio, int fim);



int main(){
	int i;
	setlocale(LC_ALL,"Portuguese");
	
	int *v;
	v = (int*)malloc(10*sizeof(int));
	
	printf("Vetor bagunçado: ");
	
	for(i=0;i<10;i++){
		v[i] = rand() %100;
		printf("%d, ",v[i]);
	}
	printf("\n");
	mergesort(v, 0, 9);
	
	printf("Vetor ordenado: ");
	for(i=0;i<10;i++){
		printf("%d, ",v[i]);
	}
	printf("\n");
	
	system("pause");
	return 0;
}


void mergesort(int* v, int inicio, int fim){
	
	int meio;
	
	if(inicio<fim){
		meio = floor((inicio+fim)/2 );
		mergesort(v, inicio, meio);
		mergesort(v, meio+1, fim);
		merge(v, inicio, meio, fim);
	}
}

void merge(int* v, int inicio, int meio, int fim){
	
	int *temp, p1, p2, tamanho, i, j, k, fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio+1;
	
	temp = (int*)malloc(tamanho*sizeof(int));
	
	for(i=0;i<tamanho;i++){
		if(temp!=NULL){
			if(!fim1&&!fim2){
				if(v[p1]<v[p2]){
					temp[i] =v[p1];
					p1++;
				}else{
					temp[i] = v[p2];
					p2++;
				}
				if(p1>meio){fim1 = 1;}
				if(p2>fim){fim2 = 1;}
			}else{
				if(!fim1){
					temp[i] = v[p1];
					p1++;	
				}else{
					temp[i] = v[p2];
					p2++;
				}
			}
		}
	}
	
	for(j=0, k=inicio;j<tamanho;j++, k++){
		v[k] = temp[j];
	}
	free(temp);
}

