#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define NOME 50
#define CPF 11
#define END 60
#define TEL 11
#define EMAIL 50
#define CLI 500
#define CONTAS 500

typedef struct
{
	int agencia;
	int nCont;
	float saldo;
	char cpf[CPF];

} tConta;

typedef struct tCliente
{
	char nome[NOME];
	char cpf[CPF];
	char endereco[END];
	char telefone[TEL];
	char email[EMAIL];
	int numConta;
} tCliente;


tCliente cliente[CLI];
tConta contas[CONTAS];

//FUNÇÕES REFENTES AO À FUNÇÃO MENU PRINCIPAL

//AQUI INICIAMOS O MENU CLIENTE E SUAS FUNÇÕES

void menuAlterarCliente(tCliente cliente[CLI], int i, int *x)
{
	int option;
	char cpf3[CPF];
	int aux;

	do
	{
		system("cls");
		printf("<<<<<<<<<<<<<<  O QUE DESEJA ALTERAR?  >>>>>>>>>>>>>>\n");
		setlocale(LC_ALL, "Portuguese");
		printf("--------------------------------------------\n");
		printf("| 1- Nome                                  |\n");
		printf("| 2- CPF                                   |\n");
		printf("| 3- Endereço                              |\n");
		printf("| 4- Telefone                              |\n");
		printf("| 5- Email                                 |\n");
		printf("| 0- Sair                                  |\n");
		printf("--------------------------------------------\n");


		scanf("%d", &option);


		switch(option)
		{
		case 1:
			printf("Digite o novo Nome: \n");
			scanf("%s", cliente[i].nome);
			printf("NOME ALTERADO COM SUCESSO!\n"); //O nome não pede validação pois, em um mundo com tantas pessoas,
			system("pause");                        //pode acontecer de existirem nomes iguais.
			break;
		case 2:
			printf("Digite o novo Cpf: \n");
			int h = 0; // Variável criada com único propósito de validação do cpf.
			scanf("%s", cpf3);
			for(aux = 0; aux <= (*x); aux++)
			{

				if((strcmp(cpf3, cliente[aux].cpf )) == 0)
				{
					h = 1; //se "h" deu 1, é porque já existe este numero de cpf. Passamos para os "if".
				}
			}
			if(h == 1) // se "h" for 1, acusa que já existe e não altera.
			{
				printf("Erro. CPF já cadastrado\n");
				system("pause");
				break;
			}
			if(h == 0) // se "h" for 0, é porque não existe, logo, pode ser alterado com sucesso.
			{
				strcpy(cliente[i].cpf, cpf3);
				printf("CPF ALTERADO COM SUCESSO!\n");
				system("pause");
				break;
			}
		case 3:
			printf("Digite o novo Endereço: \n");  // O endereço também não pede validação pelo mesmo motivo do nome
			scanf("%s", cliente[i].endereco);
			system("pause");
			break;
		case 4:
			printf("Digite o novo Telefone: \n");   //Telefone não pede validação pois duas pessoas podem usar o mesmo
			scanf("%s", cliente[i].telefone);       //numero como por exemplo um residencial
			system("pause");
			break;
		case 5:
			printf("Digite o novo Email: \n");
			scanf("%s", cliente[i].email);
			system("pause");
			break;
		case 0:
			break;

		}

	}
	while(option != 0);

}

void alterarCliente(int *contCli)                   //Função criada para validação de cpf antes de iniciar as alterações
{
	//para saber se existe aquele cliente e só assim alterar, já que o que
	char cpf2[CPF];                                 //não existe não pode ser alterado.
	int i;
	int x = *contCli;
	printf("Informe o cpf do usuário: ");
	scanf("%s", cpf2);

	for(i = 0; i <= x; i++)
	{

		if((strcmp(cpf2, cliente[i].cpf )) == 0)  //Caso encontre o cpf no cadastro, pode ser alterado, e entrará na função
		{
			//que traz os menus perguntando o que deseja alterar. Ao encerrar a função
			menuAlterarCliente(cliente, i, &x);   //chamada, ele encerra esta função.
			system("pause");
			system("cls");
			return;
		}
	}

	printf("CPF NÃO ENCONTRADO!\n");     //Caso não encontre CPF nenhum, ele exibirá esta mensagem, limpará a tela e encerrará
	system("pause");                     //essa função
	system("cls");

}

void cadastroCliente(int *contCli)    //Função que recebe as informações principais de cada cliente, presentes na estrutura
{
	//cliente do tipo tCliente.

	char cpf2[CPF];
	int i;
	int x = *contCli;
	printf("\n\nCONTADOR X: %d\n\n", x);
	printf("Informe o cpf que deseja cadastrar: ");
	scanf("%s", cpf2);

	for(i = 0; i <= x; i++)
	{

		if((strcmp(cpf2, cliente[i].cpf )) == 0)  //Neste ponto, o programa faz uma busca no vetor cliente do tipo tCliente,
		{
			//acusa erro caso já exista um cpf com o mesmo número e encerra a função
			printf("Erro. CPF já cadastrado\n");  //voltando assim para o menuCliente.
			return;
		}
	}                                            //Caso não encontre nada no laço de repetição acima, o programa avança
	strcpy(cliente[x].cpf, cpf2);                //para estas leituras de dados.
	printf("Informe o nome do cliente: ");
	scanf("%s", cliente[x].nome);
	printf("Informe o endereço do cliente: ");
	scanf("%s", cliente[x].endereco);
	printf("Informe o telefone: ");
	scanf("%s", cliente[x].telefone);
	printf("Informe o email: ");
	scanf("%s", cliente[x].email);

	cliente[x].numConta = 0;

	x++;
	*contCli = x;
}


void menuCliente(int *contCli)
{


	int option;
	int y = *contCli;
	do
	{
		printf("<<<<<<<<<<<<<<  MENU CLIENTE  >>>>>>>>>>>>>>\n");
		setlocale(LC_ALL, "Portuguese");
		printf("--------------------------------------------\n");
		printf("| 1- Cadastrar Cliente                     |\n");
		printf("| 2- Alterar Cliente                       |\n");
		printf("| 0- Sair                                  |\n");
		printf("--------------------------------------------\n");


		scanf("%d", &option);

		if(option >= 0 && option <= 2)
			system("cls");

		switch(option)
		{
		case 1:
			if(y > CLI)     //Se o número de clientes for excedido, o programa não cadastra mais nada.
			{
				printf("Número de clientes excedido!");
				break;
			}
			cadastroCliente(&y);
			break;
		case 2:
			alterarCliente(&y);
			break;
		case 0:
			break;
		default:
			printf("Erro. Informe uma opção válida: \n");
		}
	}
	while(option != 0);
	*contCli = y;
}

//FIM MENU CLIENTE

int validarCPF(tCliente cliente[CLI], int *b, int *y)
{
	char cpf4[CPF];
	int aux;

	printf("DIGITE O CPF\n");
	scanf("%s", cpf4);

	for(aux = 0; aux <= CLI; aux++)
	{
		if( strcmp(cliente[aux].cpf, cpf4) == 0)
		{
			strcpy(contas[(*y)].cpf, cpf4);
			cliente[aux].numConta++;
			return 1;
		}
	}
	return 0;
}

//AQUI INICIAMOS O MENU CONTA E SUAS FUNÇÕES

void cadastrarConta(int *contContasMenuConta, int *contClienteMenuConta)
{
	int numAgencia;
	int numConta;
	int aux;
	int y = *contContasMenuConta;
	int b = *contClienteMenuConta;
	int h;

	printf("\n\nContador: %d contas\n\n", y); // APAGAR ESTA LINHA AO FINAL DO TRABALHO. MOTIVO: SÓ CONTADOR

	printf("Digite o numero da Agência: ");
	scanf("%d", &numAgencia);
	printf("Digite o numero da Conta: ");
	scanf("%d", &numConta);

	for(aux = 0; aux <= y; aux++)
	{
		if(numAgencia == contas[aux].agencia && numConta == contas[aux].nCont)
		{
			printf("CONTAS JÁ CADASTRADA\n");
			return;
		}
	}

	h = validarCPF(cliente, &b, &y);
	if(h == 0)
	{
		printf("CPF NÃO CADASTRADO!!\n");
		return;
	}

	contas[y].agencia = numAgencia;
	contas[y].nCont = numConta;
	printf("DIGITE O SALDO DA CONTA: ");
	scanf("%f", &contas[y].saldo);

	y++;
	*contContasMenuConta = y;
	system("pause");
	system("cls");
	// getchar();
	return;
}

void menuConta(int *contCli, int *contContas)
{
	int contContasMenuConta = *contContas;
	int contClienteMenuConta = *contCli;

	int option;
	do
	{
		printf("<<<<<<<<<<<<<<  MENU CONTA  >>>>>>>>>>>>>>\n");
		setlocale(LC_ALL, "Portuguese");
		printf("--------------------------------------------\n");
		printf("| 1- Cadastrar Conta                       |\n");
		printf("| 2- Alterar Conta                         |\n");
		printf("| 3- Remover Conta                         |\n");
		printf("| 0- Sair                                  |\n");
		printf("--------------------------------------------\n");


		scanf("%d", &option);

		if(option >= 0 && option <= 3)
			system("cls");

		switch(option)
		{
		case 1:
			if(contContasMenuConta > CONTAS) //Caso o número de contas exceda o valor máximo estipulado no define, o programa
			{
				//não cadastra.
				printf("Número de contas excedido!\n");
				break;
			}
			cadastrarConta(&contContasMenuConta, &contClienteMenuConta);
			;
			break;
		case 2:
			;
			break;
		case 3:
			;
			break;
		case 0:
			break;
		default:
			printf("Erro. Informe uma opção válida: \n");
		}
	}
	while(option != 0);
	*contContas = contContasMenuConta;

}

//AQUI INICIAMOS O MENU MOVIMENTO E SUAS FUNÇÕES
void menuMovimento()
{
	int option;

	printf("<<<<<<<<<<<<<<  MENU CLIENTE  >>>>>>>>>>>>>>\n");
	setlocale(LC_ALL, "Portuguese");
	printf("--------------------------------------------\n");
	printf("| 1- Depósito                              |\n");
	printf("| 2- Saque                                 |\n");
	printf("| 3- Transferência                         |\n");
	printf("| 0- Sair                                  |\n");
	printf("--------------------------------------------\n");

	do
	{
		scanf("%d", &option);

		if(option >= 0 && option <= 3)
			system("cls");

		switch(option)
		{
		case 1:
			;
			break;
		case 2:
			;
			break;
		case 3:
			;
			break;
		case 0:
			break;
		default:
			printf("Erro. Informe uma opção válida: \n");
		}
	}
	while(option != 0);


}

//E AQUI INICIAMOS O MENU RELARTÓRIOS E SUAS FUNÇÕES




void contasPorSaldo(int  *contadorContasMenuRelatorio, int *contadorClienteMenuRelatorio)
{
	int valorDesejado;
	int op;
	int aux;
	int auxNome;
	int control = 0;
	char nome[NOME];
	char cpf[CPF];
	do
	{
		printf("Digite o valor desejado: ");
		scanf("%i", &valorDesejado);

		printf("| 1- MAIOR                                                                     |\n");
		printf("| 2- IGUAL                                                                     |\n");
		printf("| 3- MENOR                                                                     |\n");
		printf("| 0- SAIR                                                                      |\n");

		scanf("%d", &op);

		switch(op)
		{
		case 1:

			for(aux = 0; aux < (*contadorContasMenuRelatorio) ; aux++)
			{
				if(contas[aux].saldo > valorDesejado)
				{
					control = 1;
				}
			}
			if(control == 1)
			{
				for(aux = 0; aux < (*contadorContasMenuRelatorio) ; aux++)
				{
					if(contas[aux].saldo > valorDesejado)
					{
						for(auxNome = 0; auxNome < (*contadorClienteMenuRelatorio); auxNome++)
						{
							if(strcmp(contas[aux].cpf, cliente[auxNome].cpf) == 0)
							{
								strcpy(nome, cliente[auxNome].nome);
							}
						}
                        strcpy(cpf,contas[aux].cpf);
						printf("\nNOME: %s\n", nome);
						printf("CPF: %s\n",cpf);
						printf("NUMERO DA CONTA: %i\n", contas[aux].nCont);
						printf("NUMERO DA AGENCIA: %i\n", contas[aux].agencia);
						printf("SALDO: %.2f\n", contas[aux].saldo);
					}
				}
			}
			else
			{
				printf("NÃO EXISTE NENHUMA CONTA COM ESSES REQUISITOS\n");
			}
			system("pause");
			system("cls");

			break;
		case 2:
			for(aux = 0; aux < (*contadorContasMenuRelatorio) ; aux++)
			{
				if(contas[aux].saldo == valorDesejado)
				{
					control = 1;
				}
			}
			if(control == 1)
			{
				for(aux = 0; aux < (*contadorContasMenuRelatorio) ; aux++)
				{
					if(contas[aux].saldo == valorDesejado)
					{
						for(auxNome = 0; auxNome < (*contadorClienteMenuRelatorio); auxNome++)
						{
							if(strcmp(contas[aux].cpf, cliente[auxNome].cpf) == 0)
							{
								strcpy(nome, cliente[auxNome].nome);
							}
						}

						printf("\nNOME: %s\n", nome);
						printf("CPF: %s\n", contas[aux].cpf);
						printf("NUMERO DA CONTA: %i\n", contas[aux].nCont);
						printf("NUMERO DA AGENCIA: %i\n", contas[aux].agencia);
						printf("SALDO: %.2f\n", contas[aux].saldo);
					}
				}
			}
			else
			{
				printf("NÃO EXISTE NENHUMA CONTA COM ESSES REQUISITOS\n");
			}
			system("pause");
			system("cls");
			break;
		case 3:
			for(aux = 0; aux < (*contadorContasMenuRelatorio) ; aux++)
			{
				if(contas[aux].saldo < valorDesejado)
				{
					control = 1;
				}
			}
			if(control == 1)
			{
				for(aux = 0; aux < (*contadorContasMenuRelatorio) ; aux++)
				{
					if(contas[aux].saldo < valorDesejado)
					{
						for(auxNome = 0; auxNome < (*contadorClienteMenuRelatorio); auxNome++)
						{
							if(strcmp(contas[aux].cpf, cliente[auxNome].cpf) == 0)
							{
								strcpy(nome, cliente[auxNome].nome);
							}
						}

						printf("\nNOME: %s\n", nome);
						printf("CPF: %s\n", contas[aux].cpf);
						printf("NUMERO DA CONTA: %i\n", contas[aux].nCont);
						printf("NUMERO DA AGENCIA: %i\n", contas[aux].agencia);
						printf("SALDO: %.2f\n",(double)contas[aux].saldo);
					}
				}
			}
			else
			{
				printf("NÃO EXISTE NENHUMA CONTA COM ESSES REQUISITOS\n");
			}
			system("pause");
			system("cls");
			break;
		case 0:
			break;
		default:
			printf("Erro. Informe uma opção válida: \n");
			system("pause");
			system("cls");
		}
	}
	while(op != 0);
}

void contasDeUmCliente(int *contadorContasMenuRelatorio)
{
	char cpf[CPF];
	int aux;
	int controle = 0;
	printf("Digite um CPF: ");
	scanf("%s", cpf);

	for(aux = 0; aux < (*contadorContasMenuRelatorio); aux++)
	{
		if(strcmp(cpf, contas[aux].cpf) == 0 )
		{
			printf("\nNumero da conta: %d\n", contas[aux].nCont);
			printf("Numero da agencia: %d\n", contas[aux].agencia);
			printf("Saldo da conta: %.2f\n", contas[aux].saldo);
			controle = 1;

			system("pause");
			system("cls");
		}
	}

	if(controle == 0)
	{
		printf("CPF NÃO CADASTRADO!\n");
		system("pause");
		system("cls");
	}

	return;
}

void menuRelatorios(int *contContas,int *contCli)
{
	int contadorContasMenuRelatorio = *contContas;
	int contadorClientesMenuRelatorio = *contCli;
	int option;
do
	{
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  MENU RELATORIOS  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	setlocale(LC_ALL, "Portuguese");
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("| 1- Contas de um cliente                                                                     |\n");
	printf("| 2- Dados dos clientes com saldo inferior, superior ou igual a um valor                      |\n");
	printf("| 3- Listar os dados cadastrais de todos clientes (ativos ou não)                             |\n");
	printf("| 4- Listar as informações de todas as contas                                                 |\n");
	printf("| 5- Listar as informações de todos os clientes incluindo suas contas                         |\n");
	printf("| 6- Listar os dados cadastrais de todos os clientes ativos de uma agência ordenados pelo cpf |\n");
	printf("| 0- Sair                                                                                     |\n");
	printf("-----------------------------------------------------------------------------------------------\n");

	
		scanf("%d", &option);

		if(option >= 0 && option <= 6)
			system("cls");

		switch(option)
		{
		case 1:
			contasDeUmCliente(&contadorContasMenuRelatorio);
			break;
		case 2:contasPorSaldo(&contadorContasMenuRelatorio,&contadorClientesMenuRelatorio);
			break;
		case 0:
			break;
		default:
			printf("Erro. Informe uma opção válida: \n");
		}
	}
	while(option != 0);
}



// FUNÇÃO DE MENU PRINCIPAL
void menuPrincipal(int *option)
{
	int o;
	printf("<<<<<<<<<<<<<< MENU PRINCIPAL >>>>>>>>>>>>>>\n");
	setlocale(LC_ALL, "Portuguese");
	printf("--------------------------------------------\n");
	printf("| 1- Cliente                               |\n");
	printf("| 2- Conta                                 |\n");
	printf("| 3- Movimento                             |\n");
	printf("| 4- Relatório                             |\n");
	printf("| 0- Sair                                  |\n");
	printf("--------------------------------------------\n");
	printf("Informe uma opção: ");
	scanf("%d", &o);
	if(o >= 0 && o <= 4)
		system("cls");
	*option = o;

}


int main()
{

	int contCli = 0;
	int contContas = 0;
	int option;

	do
	{

		menuPrincipal(&option);
		switch(option)
		{
		case 1:
			menuCliente(&contCli);
			break;
		case 2:
			menuConta(&contCli, &contContas);
			break;
		case 3:
			menuMovimento();
			break;
		case 4:
			menuRelatorios(&contContas,&contCli);
			break;
		case 0:
			break;
		default:
			printf("ERRO 404. NOT FOUND.\n");
			system("pause");
			system("cls");

		}
	}
	while(option != 0);

	printf("Programa de gestão bancária finalizado!\n");
	printf("By Raphael Kênnedy e Thales Abdon.\n");
	printf("Merry Christmas Dra. Rosianni.\n");
	printf("                §§\n");
	printf("Coffee is life C\\__/\n");
	return 0;
}