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
* Fun??o: inserir_clientes
* Descri??o: Insere os dados de um cliente na lista.
* Par?metros:
* listaClientes: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* quantClientes: N?meros de Clientes Cadastrados
* Retorna:
* A Nova Quantidade de Clientes
Cadastrados
*/
int inserir_clientes(cliente listaClientes[], int quantClientes)
{
	printf("\nInsira as informa??es do Cliente: \n");
	printf("\nNome:");
	scanf(" %[^\n]", listaClientes[quantClientes].nome);
	
	printf("\nTelefone:");
	scanf(" %[^\n]", listaClientes[quantClientes].telefone);

	printf("\nEmpresa:");
	scanf(" %[^\n]", listaClientes[quantClientes].empresa);
	
	printf("\nEmail:");
	scanf(" %[^\n]", listaClientes[quantClientes].email);
	
	printf("\nCEP:");
	scanf(" %[^\n]", listaClientes[quantClientes].cep);
	
	printf("\nCelular:");
	scanf(" %[^\n]", listaClientes[quantClientes].celular);
	return quantClientes+1;
	
}

void alterar_dados(cliente listaClientes[], int quantClientes)
{
    if (quantClientes == 0)
    {
        printf("\nNao existe nenhum cliente cadastrado!\n");
        return;
    }
    
    int indice, opc, i;

    printf("\n===== Clientes Cadastrados =====\n");

    // Mostrar clientes começando do 1
    for (i = 0; i < quantClientes; i++)
    {
        printf("%d - %s\n", i + 1, listaClientes[i].nome);
    }

    printf("\nDigite o numero do cliente que voce deseja alterar: ");
    scanf("%d", &indice);

    // Validando escolha
    if (indice < 1 || indice > quantClientes)
    {
        printf("\nNao existe cliente nessa posicao!\n");
        return;
    }

    indice--; // Ajusta para índice real do vetor
    
    do
    {
        printf("\n===== Alterar Dados de %s =====\n", listaClientes[indice].nome);
        printf("1 - Alterar Nome\n");
        printf("2 - Alterar Telefone\n");
        printf("3 - Alterar Empresa\n");
        printf("4 - Alterar E-mail\n");
        printf("5 - Alterar CEP\n");
        printf("6 - Alterar Celular\n");
        printf("0 - Voltar ao Menu\n");
        printf("Opcao: ");
        scanf("%d", &opc);

        switch (opc)
        {
            case 1:
                printf("Novo Nome: ");
                scanf(" %[^\n]", listaClientes[indice].nome);
                break;

            case 2:
                printf("Novo Telefone: ");
                scanf(" %[^\n]", listaClientes[indice].telefone);
                break;

            case 3:
                printf("Nova Empresa: ");
                scanf(" %[^\n]", listaClientes[indice].empresa);
                break;

            case 4:
                printf("Novo Email: ");
                scanf(" %[^\n]", listaClientes[indice].email);
                break;

            case 5:
                printf("Novo CEP: ");
                scanf(" %[^\n]", listaClientes[indice].cep);
                break;

            case 6:
                printf("Novo Celular: ");
                scanf(" %[^\n]", listaClientes[indice].celular);
                break;

            case 0:
                printf("\nVoltando ao menu...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    } while (opc != 0);
}


void excluir_cliente()
{
	
}

/*
* Fun??o: listar_nomes
* Descri??o: Lista o .
* Par?metros:
* lista: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* Retorna:
* 1 se a inser??o for bem-sucedida, 0 caso
contr?rio.
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

void pesquisar_nome_empresa(cliente listaClientes[], int quantClientes)
{
	int i;
	char nomeempresa[50];
	
	printf("Digite o nome da empresa:");
	scanf("%s", nomeempresa);
	
	for(i = 0; i < quantClientes; i++)
	{
		if(strcmp(listaClientes[i].empresa, nomeempresa) == 0)
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
			case 2: alterar_dados(listaClientes, quantClientes); break;
			case 3: excluir_cliente(); break;
			case 4: listar_nomes(listaClientes, quantClientes); break;
			case 5: pesquisar_nome_empresa(listaClientes, quantClientes); break;
			case 6: pesquisar_nome_cliente(); break;
			default: printf("\nOpcao Invalida!!\n");
		}
	}while(opc!=0);
	printf("\nSaiu do Programa.");
	
	return 0;	
}
