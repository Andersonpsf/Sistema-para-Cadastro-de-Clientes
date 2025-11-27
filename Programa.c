#include <stdio.h>
#include <string.h>
#define MAX_CLIENTES 100
#define SENHA 123

typedef struct{
	int dia;
	int mes;
}data;

typedef struct{
	char nome[100];
	char telefone[15];
	char empresa[50];
	char email[100];
	char cep[15];
	char celular[15];
	data aniversario;
}cliente;


/*
* Função: verificarClientes
* Descrição: Verifica se existe Clientes cadastrados
* Parâmetros:
* quantClientes: quantidade de Clientes
* Retorna:
* 0 se não houver nenhum cliente cadastrado, caso contrário
retorna 1
*/
int verificarClientes(int quantClientes)
{
	if (quantClientes == 0)
    {
        printf("\nNao existe nenhum cliente cadastrado!\n");
        printf("Escolha outra Opcao!!\n"); 
		return 0;
    }else{
    	return 1;
	}
}


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

/*
* Função: email_existe
* Descrição: Verifica se o email já não foi cadastrado por outro usuário 
* Parâmetros:
* quantClientes: quantidade de Clientes
* listaClientes: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* email: email cadastrado
* Retorna:
* 0 se não houver nenhum cliente cadastrado, caso contrário
retorna 1
*/

int email_existe(cliente listaClientes[], int quantClientes, char email[])
{
	int i;
	for (i = 0; i < quantClientes; i++)
	{
		if (strcmp(listaClientes[i].email, email) == 0)
		{
			return 1; // Email jÃ¡ existe
		}
	}
	return 0; // Email nÃ£o existe
}


/*
* Fun??o: inserir_clientes
* Descri??o: Insere os dados de um cliente na lista.
* Par?metros:
* listaClientes: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* quantClientes: N?meros de Clientes Cadastrados
* Retorna:
* 1 se o email já está registrado
e 0 caso contrário
*/
int inserir_clientes(cliente listaClientes[], int quantClientes)
{
	char emailTeste[100];
	
	printf("\nInsira as informacoes do Cliente: \n");
	printf("\nNome: ");
	scanf(" %[^\n]", listaClientes[quantClientes].nome);
	
	printf("\nTelefone: ");
	scanf(" %[^\n]", listaClientes[quantClientes].telefone);

	printf("\nEmpresa: ");
	scanf(" %[^\n]", listaClientes[quantClientes].empresa);
	
	do{
		printf("\nEmail: ");
		scanf(" %[^\n]", emailTeste);

		if(email_existe(listaClientes, quantClientes, emailTeste))
		{
			printf("\nEmail ja cadastrado! Tente novamente.\n");
		}

	} while(email_existe(listaClientes, quantClientes, emailTeste));
	
	strcpy(listaClientes[quantClientes].email, emailTeste);

	printf("\nCEP: ");
	scanf(" %[^\n]", listaClientes[quantClientes].cep);
	
	printf("\nCelular: ");
	scanf(" %[^\n]", listaClientes[quantClientes].celular);

	printf("\nDia do aniversario: ");
	scanf("%d", &listaClientes[quantClientes].aniversario.dia);

	printf("\nMes do aniversario: ");
	scanf("%d", &listaClientes[quantClientes].aniversario.mes);
	
	printf("\nCliente Cadastrado com Sucesso!\n");
	return quantClientes+1;
	
}

/*
* Função: alterar_dados
* Descrição: Altera os dados desejados pelo usiário 
* Parâmetros:
* quantClientes: quantidade de Clientes
* listaClientes: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* Retorna:
* nada
*/

void alterar_dados(cliente listaClientes[], int quantClientes)
{

    
    int indice, opc, i;

	indice = listar_nomes(listaClientes, quantClientes); 

    printf("\nDigite o numero do cliente que voce deseja alterar: ");
    scanf("%d", &indice);

    // Validando escolha
    if (indice < 1 || indice > quantClientes)
    {
        printf("\nNao existe cliente nessa posicao!\n");
        return;
    }

    indice--; // Ajusta para Ã­ndice real do vetor
    
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

/*
* Função: excluir_cliente
* Descrição: Exclui o cliente
* Parâmetros:
* quantClientes: quantidade de Clientes
* listaClientes: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* Retorna:
* A nova quantidade de clientes (quantClientes-1)
*/

int excluir_cliente(cliente listaClientes[], int quantClientes)
{
	int indice, i, senha;
	listar_nomes(listaClientes, quantClientes); 

	printf("\nDigite o numero do cliente que voce deseja excluir: ");
	scanf("%d", &indice);

	printf("Digite a senha para confirmar a exclusao: ");
	scanf("%d", &senha);

	if (senha != SENHA)
	{
		printf("\nSenha incorreta! Exclusao cancelada.\n");
		return quantClientes;
	}

	if (indice < 1 || indice > quantClientes)
	{
		printf("\nNao existe cliente nessa posicao!\n");
		return;
	}

	indice--;

	// Desloca os clientes para "remover" o cliente selecionado
	for (i = indice; i < quantClientes - 1; i++)
	{
		listaClientes[i] = listaClientes[i + 1];
	}

	printf("\nCliente excluido com sucesso!\n");
	return quantClientes - 1;
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

int listar_nomes(cliente listaClientes[], int quantClientes)
{

	int i;
	printf("\n===== Clientes Cadastrados =====\n");
	for(i=0; i<quantClientes; i++)
	{
		printf("\nCliente %d:", i+1);
		printf("\nNome: %s \n", listaClientes[i].nome);
	}
	return i;
	
}


/*
* Função: pesquisar_nome_empresa
* Descrição: Pesquisa o nome da empresa entre os clientes cadastrados
* Parâmetros:
* quantClientes: quantidade de Clientes
* listaClientes: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* nomeEmpresa: vetor que contém o nome da Empresa
* Retorna:
* nada
*/

void pesquisar_nome_empresa(cliente listaClientes[], int quantClientes, char nomeEmpresa[])
{
	int i;
	for(i = 0; i < quantClientes; i++)
	{
		if(strcmp(listaClientes[i].empresa, nomeEmpresa) == 0)
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

/*
* Função: ler_nome_empresa
* Descrição: Lê o nome da empresa
* Parâmetros:
* quantClientes: quantidade de Clientes
* listaClientes: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* Retorna:
* Chama a função pesquisar_nome_cliente no final
*/
char ler_nome_empresa(cliente listaClientes[], int quantClientes){
	char nomeEmpresa[50];
	
	printf("Digite o nome da empresa:");
	scanf("%s", nomeEmpresa);
	pesquisar_nome_empresa(listaClientes, quantClientes, nomeEmpresa);
	
}

/*
* Função: pesquisar_nome_cliente
* Descrição: Pesquisa o nome do Cliente cadastrado
* Parâmetros:
* quantClientes: quantidade de Clientes
* listaClientes: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* nomeCliente: nome do cliente cadastrado
* Retorna:
* retorna nada
*/
void pesquisar_nome_cliente(cliente listaClientes[], int quantClientes, char nomeCliente[])
{
	int i;

	if(strcmp(nomeCliente, listaClientes[0].nome) != 0)
	{
		printf("\nCliente nao encontrado!\n");
		printf("Tente a opcao de nome parcial.\n");
		return;
	}

	for(i = 0; i < quantClientes; i++)
	{
		if(strcmp(listaClientes[i].nome, nomeCliente) == 0)
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

/*
* Função: ler_nome_cliente
* Descrição: Lê o nome do cliente
* Parâmetros:
* quantClientes: quantidade de Clientes
* listaClientes: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* Retorna:
* Chama a função pesquisar_nome_cliente no final
*/
char ler_nome_cliente(cliente listaClientes[], int quantClientes)
{
	char nomeCliente[50];
	printf("Digite o Nome do Cliente: ");
	scanf("%s", &nomeCliente);
	pesquisar_nome_cliente(listaClientes, quantClientes, nomeCliente);
	
}

/*
* Função: pesquisar_nome_parcial
* Descrição: Pesquisa os usuarios que tenham uma parte do nome
* Parâmetros:
* quantClientes: quantidade de Clientes
* listaClientes: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* nomeParcial: parte do nome a ser pesquisado
* Retorna:
* nada
*/
void pesquisar_nome_parcial(cliente listaClientes[], int quantClientes, char nomeParcial[])
{
	int i, encontrou = 0;
	for(i = 0; i < quantClientes; i++)
	{
		if(strstr(listaClientes[i].nome, nomeParcial) != NULL)
		{
			printf("\nCliente %d:", i+1);
			printf("\nNome: %s", listaClientes[i].nome);
			
			printf("\nTelefone: %s", listaClientes[i].telefone);
			
			printf("\nEmpresa: %s", listaClientes[i].empresa);
				
			printf("\nEmail: %s", listaClientes[i].email);
				
			printf("\nCEP: %s", listaClientes[i].cep);
				
			printf("\nCelular: %s\n", listaClientes[i].celular);
			encontrou = 1;
		}
	}

	if(!encontrou)
	{
		printf("\nNenhum cliente encontrado com o nome parcial fornecido.\n");
	}
}

/*
* Função: ler_nome_parcial
* Descrição: Lê uma parte do nome do cliente 
* Parâmetros:
* quantClientes: quantidade de Clientes
* listaClientes: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* Retorna:
* Chama a função pesquisar_nome_parcial no final
*/
void ler_nome_parcial(cliente listaClientes[], int quantClientes)
{
	char nomeParcial[50];
	
	printf("Digite o nome parcial do cliente:");
	scanf("%[^\n]", nomeParcial);
	pesquisar_nome_parcial(listaClientes, quantClientes, nomeParcial);
}


/*
* Função: aniversariantes_mes
* Descrição: Mostra quais são os aniversariantes do mês
* Parâmetros:
* quantClientes: quantidade de Clientes
* listaClientes: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* mes: mes do aniversário do cliente cadastrado
* Retorna:
* nada
*/
void aniversariantes_mes(cliente listaClientes[], int quantClientes, int mes)
{
	int i, encontrou = 0;
	printf("\n===== Aniversariantes do Mes %d =====\n", mes);
	for(i = 0; i < quantClientes; i++)
	{
		if(listaClientes[i].aniversario.mes == mes)
		{
			printf("\nCliente %d:", i+1);
			printf("\nNome: %s", listaClientes[i].nome);
			printf("\nData de Aniversario: %02d/%02d\n", listaClientes[i].aniversario.dia, listaClientes[i].aniversario.mes);
			encontrou = 1;
		}
	}

	if(!encontrou)
	{
		printf("\nNenhum aniversariante encontrado neste mes.\n");
	}
}

/*
* Função: ler_mes_aniversario
* Descrição: Lê o mes de aniversario do cliente
* Parâmetros:
* quantClientes: quantidade de Clientes
* listaClientes: vetor de clientes.
* cliente: estrutura contendo os dados do cliente.
* Retorna:
* Chama a função aniversariantes_mes no final
*/
void ler_mes_aniversario(cliente listaClientes[], int quantClientes)
{
	int mes;
	
	printf("Digite o mes para ver os aniversariantes (1-12): ");
	scanf("%d", &mes);
	
	if(mes < 1 || mes > 12)
	{
		printf("\nMes invalido! Por favor, insira um valor entre 1 e 12.\n");
		return;
	}
	
	aniversariantes_mes(listaClientes, quantClientes, mes);
}

int main()
{
    cliente listaClientes[MAX_CLIENTES];
	int quantClientes = 0;
	int opc;
	do{
		printf("\n======== MENU ========\n");
		printf("1 - Inserir Cliente\n");
		printf("2 - Alterar Dados do Cliente\n");
		printf("3 - Excluir Cliente\n");
		printf("4 - Listar Clientes\n");
		printf("5 - Pesquisar por Nome da Empresa\n");
		printf("6 - Pesquisar por Nome do Cliente\n");
		printf("7 - Pesquisar por Nome Parcial do Cliente\n");
		printf("8 - Listar Aniversariantes do Mes\n");
		printf("0 - Sair\n");
		printf("\nDigite a opcao desejada: ");
		scanf("%d", &opc);
		
		switch(opc)
		{
			case 1: 
				quantClientes = inserir_clientes(listaClientes, quantClientes); 
				break;
			
			case 2:
				if(verificarClientes(quantClientes))
					alterar_dados(listaClientes, quantClientes); 
				break;
			
			case 3: 
				if(verificarClientes(quantClientes))
					quantClientes = excluir_cliente(listaClientes, quantClientes);
				break;
			
			case 4: 
				if(verificarClientes(quantClientes))
					listar_nomes(listaClientes, quantClientes); 
				break;
			
			case 5:
				if(verificarClientes(quantClientes))
					ler_nome_empresa(listaClientes,  quantClientes); 
				break;
			
			case 6:
				if(verificarClientes(quantClientes))
					ler_nome_cliente(listaClientes,  quantClientes);
				break;
			
			case 7:
				if(verificarClientes(quantClientes))
					ler_nome_parcial(listaClientes,  quantClientes);
				break;

			case 8:
				if(verificarClientes(quantClientes))
					ler_mes_aniversario(listaClientes,  quantClientes);
				break;

			default: printf("\nOpcao Invalida!!\n");
		}
	}while(opc!=0);
	printf("\nSaiu do Programa.");
	
	return 0;	
}
