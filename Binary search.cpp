#include<stdlib.h>
#include<stdio.h>
#include<math.h>


//Declaração de funções


int binary_search(int*array, int start, int end, int x);




//Corpo do programa
int main(){
	
int vetor[5] = {1, 2, 3, 4, 5}, resposta;
	
resposta = binary_search(vetor,0, 5, 30);

	if(resposta == -1){
		printf("deu merda\n");
	}else{
		printf("%d\n",resposta);
	}
	
	
	
system("pause");
return 0;
}

//Funções

int binary_search(int*array, int start, int end, int x){
	
	int mid;	
	
	
	if(start<=end){
		
		mid = ((start+end)/2);
		
		
		if(array[mid] == x){
			return mid;
		}
		else if(array[mid] < x){
			return binary_search(array, mid+1, end, x);	
		}else if(array[mid] > x){
				return binary_search(array, start, mid-1, x);
		}
	}	
	
	return -1;
}








