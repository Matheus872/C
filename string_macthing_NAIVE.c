#include<stdio.h>
#include<stdlib.h>
#include<string.h>



char* popula(char *string, int n);
void imprime(char *string, int n);
int NAIVE(char *string, char *pattern,  int n);

int main(){
	


	int n;
	char *string;
	char *pattern;
	
	scanf("%d",&n);
	string = (char*)malloc(n*sizeof(char));
	

	char buffer[1000];
	scanf("%s", buffer);
	int m = strlen(buffer);
	pattern = (char*)malloc(n*sizeof(char));
	
	popula(string, n);
	NAIVE(string, pattern, n);
	
	
	system("pause");
	return 0;
}


char* popula(char *string, int n){
	
	register int i;
	for(i=0;i<n;i++){
		string[i] = 97 + (char)(rand()%26);
	}
}


void imprime(char *string, int n){
	
	register int i;
	for(i=0;i<n;i++){
		printf("%c", string[i]);
	}
}

int NAIVE(char *string, char *pattern,  int n){
	
	int patlen, stringlen;
	stringlen = strlen(string);
	patlen = strlen(patlen);
	
	register int i, j;
	for(i=0;i<stringlen - patlen;i++){
		for(j=0;j<patlen;j++){
			if(string[i+j] != pattern){
				break;
			}
		}
		if( j == patlen){
			return 1;
		}
	}
	
	return 0;	
}













