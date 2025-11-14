#include <stdio.h>
#include <string.h>
#define MAX_CLIENTES 100
#define SENHA 123


typedef struct{
	char nome[100];
	char telefone[15];
	char empresa[50];
	char email[100];
	char cep[15];
	char celular[15];
}cliente;



typedef struct Data{
	int dia;
	int mes;
}data;


/*
* Função: inserir_clientes
* Descrição: Insere os dados de um cliente na lista.
* Parâmetros:
* listaClientes: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* quantClientes: Números de Clientes Cadastrados
* Retorna:
* A Nova Quantidade de Clientes
Cadastrados
*/
int inserir_clientes(cliente listaClientes[], int quantClientes)
{
	printf("\nInsira as informações do Cliente: \n");
	printf("\nNome:");
	scanf(" %s", listaClientes[quantClientes].nome);
	
	printf("\nTelefone:");
	scanf(" %s", listaClientes[quantClientes].telefone);

	printf("\nEmpresa:");
	scanf(" %s", listaClientes[quantClientes].empresa);
	
	printf("\nEmail:");
	scanf(" %s", listaClientes[quantClientes].email);
	
	printf("\nCEP:");
	scanf(" %s", listaClientes[quantClientes].cep);
	
	printf("\nCelular:");
	scanf(" %s", listaClientes[quantClientes].celular);
	return quantClientes+1;
	
}

void alterar_dados()
{
	
}

void excluir_cliente()
{
	
}

/*
* Função: listar_nomes
* Descrição: Lista o .
* Parâmetros:
* lista: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* Retorna:
* 1 se a inserção for bem-sucedida, 0 caso
contrário.
*/

void listar_nomes(cliente listaClientes[], int quantClientes)
{

	int i;
	for(i=0; i<quantClientes; i++)
	{
		printf("\nCliente %d:", i+1);
		printf("\nNome: %s", listaClientes[i].nome);
		
		printf("\nTelefone: %s", listaClientes[i].telefone);
	
		printf("\nEmpresa: %s", listaClientes[i].empresa);
		
		printf("\nEmail: %s", listaClientes[i].email);
		
		printf("\nCEP: %s", listaClientes[i].cep);
		
		printf("\nCelular: %s\n", listaClientes[i].celular);
	}
}

void pesquisar_nome_empresa()
{
	
}

void pesquisar_nome_cliente()
{
	
}

int main()
{
    cliente listaClientes[MAX_CLIENTES];
	int quantClientes = 0;
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
			case 1: quantClientes = inserir_clientes(listaClientes, quantClientes); break;
			case 2: alterar_dados(); break;
			case 3: excluir_cliente(); break;
			case 4: listar_nomes(listaClientes, quantClientes); break;
			case 5: pesquisar_nome_empresa(); break;
			case 6: pesquisar_nome_cliente(); break;
			default: printf("\nOpcao Invalida!!\n");
		}
	}while(opc!=0);
	printf("\nSaiu do Programa.");
	
	return 0;	
}
