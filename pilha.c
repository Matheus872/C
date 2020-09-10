#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define MAX 100



int Topo = -1, diamantes=0;


int cheia(void);
int vazia(void);
int pop(char c, char *pilha);
int push(int c, char *pilha);


int main(){
	
	setlocale(LC_ALL,"Portuguese");
	char *vet, c;
	int i;
	char *pilha;
	pilha = (char*)malloc(MAX*sizeof(char));
	vet = (char*)malloc(MAX*sizeof(char));
	
	printf("Insira a expressão: ");
	fflush(stdin);
	gets(vet);
	
	for(i=0;i<MAX-1;i++){
		if(vet[i]=='<'){
			push('<', pilha);
		}
		if(vet[i]=='>'){
			pop(c, pilha);
		}
	}
	
	printf("Número de diamantes: %d\n",diamantes);
	
	system("pause");
	return 0;
}




int cheia(void){
	return Topo == MAX-1;
}

int vazia(void){
	return Topo == -1;
}

int push(int c, char *pilha){
	if(cheia()){
		return -1;
	}else{
		Topo++;
		pilha[Topo] = c;
		return 1;
	}
}

int pop(char c, char *pilha){
	if(vazia()){
		return -1;
	}else{
		c = pilha[Topo];
		Topo--;
		diamantes++;
		return 1;
	}
}








