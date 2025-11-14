#include <stdio.h>
#include <string.h>
#define MAX_CLIENTES 100
#define SENHA 123


typedef struct Cliente{
	char nome;
	char telefone;
	char empresa;
	char email;
	char cep;
	char celular;
}cliente;



typedef struct Data{
	int dia;
	int mes;
}data;



void inserir_clientes()
{
	
}

void alterar_dados()
{
	
}

void excluir_cliente()
{
	
}

void listagem_nome()
{
	
}

void pesquisar_nome_empresa()
{
	
}

void pesquisar_nome_cliente()
{
	
}

int main()
{
	int opc;
	do{
		printf("\n=====MENU=====\n");
		printf("1 - Inserir Cliente\n");
		printf("2 - Alterar Dados do Cliente\n");
		printf("3 - Excluir Cliente\n");
		printf("4 - Listar Clientes por Nome\n");
		printf("5 - Pesquisar por Nome da Empresa\n");
		printf("6 - Pesquisar por Nome do Cliente\n");
		printf("0 - Sair\n");
		printf("\nDigite a opcao desejada: ");
		scanf("%d", &opc);
		
		switch(opc)
		{
			case 1: inserir_clientes(); break;
			case 2: alterar_dados(); break;
			case 3: excluir_cliente(); break;
			case 4: listagem_nome(); break;
			case 5: pesquisar_nome_empresa(); break;
			case 6: pesquisar_nome_cliente(); break;
			default: printf("\nOpcao Invalida!!\n");
		}
	}while(opc!=0);
	printf("\nSaiu do Programa.");
	
	return 0;	
}
