#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<math.h>


// DECLARAÇÃO DAS ESTRUTURAS

struct pessoa{
   int codC;
   char nome[50];
   char cpf[15];
   char endereco[200];
   char telefone[30];
   char data[10];
   int vazio;
   int cod;
};
struct pessoa LOG[50];



struct produto
{
	int codproduto;
	char nome[50];
	int valor;
	char descricao[100];
	char fornecedor[30];
	int vazio,cod;
};
struct produto logP[100];



struct venda
{
	int codC;
	int codV; 
	int codproduto;
	int quantidade;
	float valort[10];
	char data[10];
	int vazio,cod;
	char np;
	float vp;
	
}logV[100];



//DECLARAÇÃO DAS VARIÁVEIS GLOBAIS

int optc,posicao, retorno;
int codx;

int posicao_prod, retorno_prod, codx_prod;

int posicao_venda, retorno_venda, codx_venda;

 
 
 
//DECLARAÇÃO DAS FUNÇÕES
 
 void login(void);
 void menu1(void);
 
 void menuclientes(void);
 void cadastroC(int cod, int pos);
 //void exluir_cliente(void);
 void consultacod(void);
 void list(void);
 int verifica_pos(void);
 int verifica_cod(int cod);
 
 void menuprodutos(void);
 void cadastroP(int cod, int pos);
 int verifica_pos_prod(void);
 int verifica_cod_prod(int cod);
 
 void menuvendas(void);
 void cadastroV(int cod, int pos);
 int verifica_pos_venda(void);
 int verifica_cod_venda(int cod);
 
 void menucaixa(void);
 
 int binary_search(int*array, int start, int end, int x);
 
// int verificacod_arq(int cod);






//MAIN
 
int main(void){
	system ("color 0F");
	login();
}


//DESENVOLVIMENTO DAS FUNÇÕES

//MENU 1

void menu1(void){
int opt;
do{
printf("*******************************************************\n*     SISTEMA GERENCIAMENTO                           *\n*******************************************************\n");
printf(" 1 - Clientes\n");
printf(" 2 - Produtos\n");
printf(" 3 - Vendas\n");
printf(" 4 - Caixa\n");
printf(" 5 - Sair\n*******************************************************\n\n");
printf(" Selecione uma opcao por favor: ");
scanf("%d", &opt);
getchar();

if(opt == 1){
	system("cls");
	menuclientes();
}else{
}
if(opt == 2){
	system("cls");
	menuprodutos();
}else{
}
if(opt == 3){
	system("cls");
	menuvendas();
}else{
}
if(opt == 4){
system("cls");
menucaixa();
}else{
	printf("Opcao invalida!");
	system("pause");
	system("cls");
}
}
while(opt != 5||opt < 5);
printf("saiu\n");
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------
//LOGIN

void login(){

char usuario[20], senha[20];
int vpos;
do{
printf("*******************************************************\n* SISTEMA GERENCIAMENTO_LOGIN                         *\n*******************************************************\n");
printf(" Nome do usuario: ");
scanf("%s",usuario);
printf(" Senha: ");
scanf("%s",senha);



if(!strcmp(usuario,"1")&&!strcmp(senha,"1")){
printf("\n*******************************************************\n  O lOGIN FOI EFETUADO COM SUCESSO!\n\n");
vpos=1;
}else{
	printf("\n*******************************************************\n  USUARIO OU SENHA INCORRETOS, TENTE NOVAMENTE!\n\n\a");
	system("color 0C");
	system("pause");
	system ("color 0F");
	system("cls");
}
}while(vpos!=1);
system("cls");
menu1();
}

//******************** FUNÇÕES CLIENTES ************************************** FUNÇÕES CLIENTES *************************************************************
//MENU CLIENTES

void menuclientes(void)
{
printf("*******************************************************\n*   Voce selecionou a opcao 1 - Clientes              *\n*******************************************************\n");
printf(" 1 - cadastrar cliente\n");
printf(" 2 - alterar cliente\n"); 
printf(" 3 - excluir cliente\n"); 
printf(" 4 - Pesquisar cliente\n");
printf(" 5 - listar cliente\n");
printf(" 6 - Voltar ao menu principal\n*******************************************************\n");
printf("Selecione uma opcao por favor: ");
scanf("%d", &optc);
getchar();

	if(optc == 1){
   	posicao = verifica_pos();

		if ( posicao != -1 ){
   		printf("\nEntre com um codigo de 1 a 200 para seu cadastro (Formato xxx): \n");
   		scanf("%d",&codx);
   		retorno = verifica_cod(codx);

			if ( retorno == 1 )
			cadastroC( codx, posicao );
    		else{
        		printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
        		system("pause");
        		getchar();
        		system("cls");
        		menu1();
        	}
		}
	
	
		else{
    		printf("\nNao e possivel realizar mais cadastros!\n");
    		getchar();
    		system("cls");
    		menu1();
    	}
    }else{
	}

if(optc == 2){
}else{
}
if(optc == 3){
//	excluir_cliente();
}else{
}

if(optc == 4){
	consultacod();
}else{
}
if(optc == 5){
	printf("\n\ncod    nome       cpf      data      endereco     telefone\n");
	list();
}else{
}
if(optc == 6){
	system("cls");
	menu1();
}else{
}
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//Cadastro das pessoas
void cadastroC(int cod, int pos){ 

    int i,optc;
    
    pos = verifica_pos();
    LOG[pos].codC = cod;
    printf("\nDigite seu nome: ");
    scanf("%s",LOG[pos].nome);
    printf("\nDigite seu CPF: ");
    scanf("%s",LOG[pos].cpf);
    printf("\nDigite a data de nascimento (formato xx/xx/xxxx):");
    scanf("%s",LOG[pos].data);
    printf("\nDigite seu Endereco: ");
    scanf("%s",LOG[pos].endereco);
    printf("\nDigite seu Telefone: ");
    scanf("%s",LOG[pos].telefone);
    LOG[pos].vazio = 1;
    
FILE*file;
file = fopen("C:\\ProgramaC\\ClientesC.txt","a");
fprintf(file,"\n%d %s %s %s %s %s",LOG[pos].codC,LOG[pos].nome,LOG[pos].cpf,LOG[pos].data,LOG[pos].endereco,LOG[pos].telefone);
fclose(file);
printf("\nCadastro realizado com sucesso!\nEntre com 1 para realizar um novo cadastro ou 2 para voltar ao menu!\n");
scanf("%d",&optc);

	if(optc==1){
   	system("cls");
   	posicao = verifica_pos();

		if (posicao != -1 ){
   		printf("\nEntre com um codigo de 1 a 200 para seu cadastro: \n");
   		scanf("%d",&codx);
  		retorno = verifica_cod(codx);

			if ( retorno == 1 )
            	cadastroC( codx, posicao );
        	else{
            	printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
            	system("pause");
            	getchar();
            	system("cls");
            	menu1();
            }
		}
else{
    printf("\nNao e possivel realizar mais cadastros!\n");
    getchar();
    system("cls");
    menu1();

        }
}

system("cls");
menu1();
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
// EXLUI CLIENTE CADASTRADO
/*int excluir_cliente (){

    int cod, cont = 0;
    char resp;
    printf("\nEntre com o codigo do registro que deseja excluir: \n");
    scanf("%d", &cod );

    while ( cont <= 200 )
    {

        if ( LOG[cont].codC == cod )
        {

            if (LOG[cont].vazio == 1 )
            {
                printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", LOG[cont].codC,LOG[cont].nome,LOG[cont].cpf,LOG[cont].endereco,LOG[cont].telefone);
                getchar();
                printf("\nDeseja realmente exlucir? s/n: ");
                scanf("%s",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    LOG[cont].vazio=0;
                    (LOG[cont].codC) == NULL;
                    printf("\nExclusao feita com sucesso\n");
                    system("pause");
                    system("cls");
                    menu1();
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclusao cancelada!\n");
                        break;
                    }
                }

            }

        }

        cont++;

        if ( cont > 200 )
            printf("\nCodigo nao encontrado\n");
			system("pause");
			system("cls");
			menu1();
    }
printf("\nCodigo nao encontrado\n");
system("pause");
system("cls");
menu1();
}*/


//-------------------------------------------------------------------------------------------------------------------------------------------------------
void consultacod (void) 
{
    int cont = 0, cod;
	char codigo[3];
	char linha[100];
	
	
    printf("\nEntre com o codigo\n");
    scanf("%d",&cod);

	FILE*abre;
	abre = fopen("C:\\ProgramaC\\ClientesC.txt","r");
	
	if(abre==NULL){
	printf("nao foi possivel abrir");
	getchar();
}else{
}
	
	/*while (fgets(codigo,4,abre)!=cod){
	cont++;
}
	fgets(linha,100,abre);
	printf("%s",linha);*/


  /*  while ( cont <= 200 )
    {

        if (LOG[cont].codC==cod)
        {
            if (LOG[cont].vazio==1)
            {
               
                printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", LOG[cont].codC,LOG[cont].nome,LOG[cont].cpf,LOG[cont].endereco,LOG[cont].telefone);
               

                system ("pause");

                system("cls");

                menu1();

            }
        }

        cont++;*/

        if ( cont > 200 ){
            printf("\nCodigo nao encontrado, pressione enter para volar ao menu principal\n");
            getchar();
            system("cls");
        }

}
//}
//----------------------------------------------------------------------------------------------------------------------------------------------------
// LISTA USUÁRIOS CADASTRADOS
void list(){ 
  
  FILE*file;
  file = fopen("C:\\ProgramaC\\ClientesC.txt","r");
  if(file==NULL){
  	printf("O Arquivo não pode ser aberto, o programa sera encerrado!");
  	system("pause");
  }else{
}
  char Leitura[200];
  while(fgets(Leitura,200,file)!=NULL){
  	printf("%s\n",Leitura);
}
system("pause");
system("cls");
}
  
//-------------------------------------------------------------------------------------------------------------------------------------------------------
//VERIFICADOR DA POSIÇÃO
int verifica_pos( void ){
    int pos = 0;

    while ( pos <= 5 )
    {

        if ( LOG[pos].vazio == 0 )
            return(pos);

        pos++;

    }

    return(-1);

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
// VERIFICADOR DE CÓDIGO
int verifica_cod( int cod )
{
    int pos = 0;

    while ( pos <= 5 ){
        if ( LOG[pos].codC == cod ){
   return(0);
       }
       pos++;
    }
    
    return(1);

}

//************************** FUNÇÕES PRODUTOS ******************************************* FUNÇÕES PRODUTOS *******************************************************************
//MENU PRODUTOS

void menuprodutos(void){

printf("*******************************************************\n*   Voce selecionou a opcao 2 - Produtos              *\n*******************************************************\n");
printf(" 1 - cadastrar produto\n");
printf(" 2 - alterar produto\n"); 
printf(" 3 - excluir produto\n"); 
printf(" 4 - Pesquisar produto por codigo\n");
printf(" 5 - Listar todos os produtos\n");
printf(" 6 - Voltar ao menu principal\n*******************************************************\n");
printf("Selecione uma opcao por favor: ");
scanf("%d", &optc);
getchar();

if(optc == 1){
   posicao_prod = verifica_pos_prod();

if ( posicao_prod != -1 ){
   printf("\nEntre com um codigo de 1 a 200 para seu cadastro: \n");
   scanf("%d",&codx_prod);
   retorno_prod = verifica_cod_prod(codx_prod);

if ( retorno_prod == 1 )
    cadastroP( codx_prod, posicao_prod );
        else{
            printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
            system("pause");
            getchar();
            system("cls");
            menu1();
            }}
else{
    printf("\nNao e possivel realizar mais cadastros!\n");
    getchar();
    system("cls");
    menu1();
        }
}else{
}

if(optc == 2){
	
}else{
}
if(optc == 3){
	
}else{
}

if(optc == 4){
	
}else{
}
if(optc == 5){
	
}else{
}
if(optc == 6){
	system("cls");
	menu1();
}else{
}
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//CADASTRO DE PRODUTOS

void cadastroP(int cod, int pos){ 

    int i,optc;
    
    
    pos = verifica_pos_prod();
    logP[pos].codproduto = cod;
    printf("\nDigite o nome do produto: ");
    scanf("%s",logP[pos].nome);
    printf("\nDigite o fornecedor: ");
    scanf("%s",logP[pos].fornecedor);
    printf("\nDigite uma descricao: ");
    scanf("%s",logP[pos].descricao);
    printf("\nDigite o valor do produto: ");
    scanf("%d",logP[pos].valor);
    logP[pos].vazio = 1;
    
	FILE*produto;
	produto = fopen("C:\\ProgramaC\\ProdutosC.txt","a");
	fprintf(produto,"\n%d %s %s %s %d",logP[pos].codproduto,logP[pos].nome,logP[pos].fornecedor,logP[pos].descricao,logP[pos].valor);
	fclose(produto);
	
	printf("\nCadastro realizado com sucesso!\nEntre com 1 para realizar um novo cadastro ou 2 para voltar ao menu!\n");
	scanf("%d",&optc);
	
	if(optc==1){
		system("cls");
		posicao_prod = verifica_pos_prod();
	
	if ( posicao_prod != -1 ){
	printf("\nEntre com um codigo de 1 a 200 para seu cadastro: \n");
	scanf("%d",&codx_prod);
	retorno_prod = verifica_cod_prod(codx);
	
		if ( retorno == 1 )
            cadastroP( codx_prod, posicao_prod );
        else{
            printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
            system("pause");
            getchar();
            system("cls");
            menu1();
            }}
	else{
    printf("\nNao e possivel realizar mais cadastros!\n");
    getchar();
    system("cls");
    menu1();
}
		
	}

	system("cls");
	menu1();
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------
//VERIFICADOR DA POSIÇÃO PRODUTO
int verifica_pos_prod( void ){
    int pos = 0;

    while ( pos <= 5 )
    {

        if ( LOG[pos].vazio == 0 )
            return(pos);

        pos++;

    }

    return(-1);

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
// VERIFICADOR DE CÓDIGO PRODUTO
int verifica_cod_prod( int cod )
{
    int pos = 0;

    while ( pos <= 5 ){
        if ( logP[pos].codproduto == cod ){
   return(0);
       }
       pos++;
    }
    
    return(1);

}

//***************** FUNÇÕES VENDAS ****************************************** FUNÇÕES VENDAS ***************************************************************
// MENU VENDAS

void menuvendas(void){

printf("*******************************************************\n*   Voce selecionou a opcao 3 - Vendas              *\n*******************************************************\n");
printf(" 1 - lancar venda\n");
printf(" 2 - alterar venda\n"); 
printf(" 3 - excluir venda\n"); 
printf(" 4 - Pesquisar venda por codigo\n");
printf(" 5 - Listar todos as vendas\n");
printf(" 6 - Voltar ao menu principal\n*******************************************************\n");
printf("Selecione uma opcao por favor: ");
scanf("%d", &optc);
getchar();

if(optc == 1){
   posicao_venda = verifica_pos_venda();

if ( posicao_venda != -1 ){
   printf("\nEntre com um codigo de 1 a 200 para seu cadastro: \n");
   scanf("%d",&codx_venda);
   retorno_venda = verifica_cod_venda(codx_venda);

if ( retorno_venda == 1 )
    cadastroV( codx_venda, posicao_venda );
        else{
            printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
            system("pause");
            getchar();
            system("cls");
            menu1();
            }}
else{
    printf("\nNao e possivel realizar mais cadastros!\n");
    getchar();
    system("cls");
    menu1();
        }
}else{
}

if(optc == 2){
	
}else{
}
if(optc == 3){
	
}else{
}

if(optc == 4){
	
}else{
}
if(optc == 5){
	
}else{
}
if(optc == 6){
	system("cls");
	menu1();
}else{
}
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//CLANÇAMENTO DE VENDAS

void cadastroV(int cod, int pos){ 

    int i,optc,vp,quant;
    
    
    pos = verifica_pos_venda();
    logV[pos].codV == cod;
    printf("\nDigite o codigo do cliente (se nao for um cliente cadastrado digite 999): \n");
    scanf("%d",logV[pos].codV);
    printf("\nDigite o codigo do produto: ");
    scanf("%d",logV[pos].codproduto);
    printf("\nDigite a quantidade: ");
    scanf("%d",logV[pos].quantidade);
    printf("\nDigite a data (formato xx/xx/xxxx): ");
    scanf("%s",logV[pos].data);
    quant == (logV[pos].quantidade);
	//logV[pos].valort = vp*quant;
    logV[pos].vazio = 1;
    
//FILE*produto
//produto = fopen("C:\\ProgramaC\\ProdutosC.txt","a")

    
    
    
	FILE*file;
	file = fopen("C:\\ProgramaC\\Vendas.txt","a");
	fprintf(file,"\n%d %d %d %d %s %d",logV[pos].codV,logV[pos].codC,logV[pos].codproduto,logV[pos].quantidade,logV[pos].data,logV[pos].valort);
	fclose(file);
	
	printf("\nLancamento realizado com sucesso!\nEntre com 1 para realizar um novo lancamento ou 2 para voltar ao menu!\n");
	scanf("%d",&optc);
	
	if(optc==1){
		system("cls");
		posicao = verifica_pos_venda();
	
	if ( posicao != -1 ){
	printf("\nEntre com um codigo de 1 a 200 para o lançamento: \n");
	scanf("%d",&codx);
	retorno = verifica_cod_venda(codx_venda);
	
		if ( retorno == 1 )
            cadastroV( codx_venda, posicao_venda );
        else{
            printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
            system("pause");
            getchar();
            system("cls");
            menu1();
            }}
	else{
    printf("\nNao e possivel realizar mais lançamentos!\n");
    getchar();
    system("cls");
    menu1();
}
		
	}

	system("cls");
	menu1();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//VERIFICADOR DA POSIÇÃO VENDA
int verifica_pos_venda( void ){
    int pos = 0;

    while ( pos <= 5 )
    {

        if ( logV[pos].vazio == 0 )
            return(pos);

        pos++;

    }

    return(-1);

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
// VERIFICADOR DE CÓDIGO VENDA
int verifica_cod_venda( int cod )
{
    int pos = 0;

    while ( pos <= 5 ){
        if ( logV[pos].cod == cod ){
   return(0);
       }
       pos++;
    }
    
    return(1);

}
//****************** FUNÇÕES CAIXA *************************************** FUNÇÕES CAIXA ****************************************************************
// MENU CAIXA
void menucaixa(void){
	

printf("*******************************************************\n*   Voce selecionou a opcao 1 - Caixa                 *\n*******************************************************\n");
printf(" 1 - Abrir caixa do dia\n");
printf(" 2 - Visualizar caixa do dia\n"); 
printf(" 3 - Fechar caixa do dia\n"); 
printf(" 4 - Pesquisar caixa\n");
printf(" 5 - Listar todos os dias\n");
printf(" 6 - Voltar ao menu principal\n*******************************************************\n");
printf("Selecione uma opcao por favor: ");
scanf("%d", &optc);
getchar();

if(optc == 1){
	
	
char datacaixa[15], nomearq[30];
float mont;
	
	
printf("Insira a data (formato xx/xx/xxxx):");
scanf("%s",&datacaixa);
printf("Insira o montante inicial:");
scanf("%f",&mont);


FILE*caixa;
caixa = fopen("C:\\ProgramaC\\caixa.txt","a");
if(caixa==NULL){
printf("Não foi possivel abrir o arquivo!");
system("pause");
main();
}
fprintf(caixa,"Data: %s\nMontante inicial: %f\n",&datacaixa,&mont);
fclose(caixa);


}
else{
}

if(optc == 2){
	
}else{
}
if(optc == 3){
	
}else{
}

if(optc == 4){
	
}else{
}
if(optc == 5){
	
}else{
}
if(optc == 6){
	
}else{
}
}


//*******************************************  BUSCA BINÁRIA ***************************************************************************
int binary_search(int*array, int start, int end, int x){
	
	
	int mid;
	
	
	if(start<=end){
		
		mid = ((start+end)/2);	
		
		if(mid == x){
			return mid;
		}else
		
		if(array[mid]<x){
			return binary_search(array, mid+1, end, x);
		}else
		
		if(array[mid]>x){
			return binary_search(array, start, mid-1, x);
		}else{
		}
	}
	
	
	
	return -1;
}
	



/*int verificacod_arq(int cod){
	
	FILE*arq;
	char linha[100];
	char *resultado;
	char digito[3];

	
	arq = fopen("C:\\ProgramaC\\ClientesC.txt", "r");
	
	while(!feof(arq)){
	resultado = fgets(linha,100,arq);
	digito[3] = (resultado[1]);
	if (digito[3]= cod );
	printf("deu certo pode cadastrar");
	
	
	
	
}
}
*/


