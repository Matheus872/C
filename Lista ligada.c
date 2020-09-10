#include<stdio.h>
#include<stdlib.h>
#include<locale.h>



typedef struct lista{
	int qnt;
	struct registro *inicio;
}lista;


typedef struct registro{
	int valor;
	struct registro *prox;
}registro; 


lista* aloca_lista(void);
registro* aloca_reg(void);
void menu(lista *l);
void inserir_inicio(int x, lista *l);
void inserir_fim(int x, lista *l);
void mostrar(lista *l);
int buscar (int x, lista *l);
int remover(int x, lista *l);



int main(){
	
	setlocale(LC_ALL,"Portuguese");	
	lista *l1;
	l1 = aloca_lista();	
	menu(l1);	
	system("pause");
	return 0;
}


lista* aloca_lista(void){
	lista *novo;
	novo = (lista*)malloc(sizeof(lista));
	novo->inicio = NULL;	
	novo->qnt = 0;
	return(novo);
}


registro* aloca_reg(void){
	registro *novo;
	novo = (registro*)malloc(sizeof(registro));
	novo->prox = NULL;
	novo->valor = NULL;
	return(novo);
}

void incluir_inicio(int x, lista *l){
	registro *novo, *aux;
	novo = aloca_reg();
	novo->valor = x;
	
	if(l->qnt== 0){
		l->inicio = novo;
	}else{
		aux = l->inicio;
		l->inicio = novo;
		novo->prox = aux;
	}
	l->qnt++;
	printf("Registro inserido com sucesso!\n");
	system("pause");
}


void incluir_fim(int x, lista *l){
	registro *novo, *aux;
	novo = aloca_reg();
	novo->valor = x;
	
	if (l->qnt == 0){
		l->inicio = novo;
	}else{
		aux = l->inicio;
		while(aux->prox!=NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
	}
	l->qnt++;
	printf("Registro inserido com sucesso!\n");
	system("pause");
}

int buscar(int x, lista *l){	
	if(l->inicio == 0){
		printf("Não há registros na lista!\n");
		system("pause");
		return -1;
	}else{
		registro *aux;
		aux = l->inicio;
		while(aux!=NULL){
			if(aux->valor == x){
				printf("Registro encontrado!\n");
				system("pause");
				return 1;
			}else{
				aux = aux->prox;
			}
		}
		printf("Registro não encontrado!\n");
		system("pause");
		return -1;
	}
}


int remover(int x, lista *l){
	registro *aux, *ant = NULL;
	
	if(l->qnt == 0){
		printf("Não há registros na lista!\n");
		system("pause");
		return -1;
	}else{
		aux = l->inicio;
		while(aux!=NULL){
			if(aux->valor == x){
				if(ant == NULL){
					l->inicio = aux->prox;
				}else{
					ant->prox = aux->prox;
				}
				free(aux);
				l->qnt--;
				printf("Registro removido com sucesso!\n");
				system("pause");
				return 1;
			}
			ant = aux;
			aux = aux->prox;
		}
		return -1;
	}
}



void mostrar(lista *l){
	if(l->qnt == 0){
		printf("Não há nenhum registro na lista!\n");
	}else{
		registro *aux;
		aux = l->inicio;
		while(aux!=NULL){
			printf("%d\n",aux->valor);
			aux = aux->prox;
		}
	}
	system("pause");
}




void menu(lista *l){
	
	int opt, x, v;
	
	do{
		system("cls");
		printf("Entre com a opção:\n1 - Inserir no inicio\n2 - Inserir no fimn\3 - Buscar\n4 - Remover\n5 - Mostrar\n6 - SAIR\n--------------------------------\n\n\t");
		scanf("%d",&opt);		
		switch(opt){
			case 1: system("cls");printf("Entre com o valor que deseja inserir: ");scanf("%d",&x);incluir_inicio(x, l);break;
			case 2: system("cls");printf("Entre com o valor que dejesa inserir: ");scanf("%d",&x);incluir_fim(x, l);break;
			case 3: system("cls");printf("Entre com o valor que deseja buscar: ");scanf("%d",&x);buscar(x, l);break;
			case 4: system("cls");printf("Entre com o valor que deseja remover: ");scanf("%d",&v);remover(v, l);break;
			case 5: system("cls");mostrar(l);break;
			case 6: system("cls");printf("SAIU!");system("pause");exit(0);break;
			default: printf("Opção invlálida!\n");system("pause");system("cls");break;
		}
	}while(opt>0&&opt<7);
	
	
}













