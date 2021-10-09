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

//FUN��ES REFENTES AO � FUN��O MENU PRINCIPAL

//AQUI INICIAMOS O MENU CLIENTE E SUAS FUN��ES

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
		printf("| 3- Endere�o                              |\n");
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
			printf("NOME ALTERADO COM SUCESSO!\n"); //O nome n�o pede valida��o pois, em um mundo com tantas pessoas,
			system("pause");                        //pode acontecer de existirem nomes iguais.
			break;
		case 2:
			printf("Digite o novo Cpf: \n");
			int h = 0; // Vari�vel criada com �nico prop�sito de valida��o do cpf.
			scanf("%s", cpf3);
			for(aux = 0; aux <= (*x); aux++)
			{

				if((strcmp(cpf3, cliente[aux].cpf )) == 0)
				{
					h = 1; //se "h" deu 1, � porque j� existe este numero de cpf. Passamos para os "if".
				}
			}
			if(h == 1) // se "h" for 1, acusa que j� existe e n�o altera.
			{
				printf("Erro. CPF j� cadastrado\n");
				system("pause");
				break;
			}
			if(h == 0) // se "h" for 0, � porque n�o existe, logo, pode ser alterado com sucesso.
			{
				strcpy(cliente[i].cpf, cpf3);
				printf("CPF ALTERADO COM SUCESSO!\n");
				system("pause");
				break;
			}
		case 3:
			printf("Digite o novo Endere�o: \n");  // O endere�o tamb�m n�o pede valida��o pelo mesmo motivo do nome
			scanf("%s", cliente[i].endereco);
			system("pause");
			break;
		case 4:
			printf("Digite o novo Telefone: \n");   //Telefone n�o pede valida��o pois duas pessoas podem usar o mesmo
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

void alterarCliente(int *contCli)                   //Fun��o criada para valida��o de cpf antes de iniciar as altera��es
{
	//para saber se existe aquele cliente e s� assim alterar, j� que o que
	char cpf2[CPF];                                 //n�o existe n�o pode ser alterado.
	int i;
	int x = *contCli;
	printf("Informe o cpf do usu�rio: ");
	scanf("%s", cpf2);

	for(i = 0; i <= x; i++)
	{

		if((strcmp(cpf2, cliente[i].cpf )) == 0)  //Caso encontre o cpf no cadastro, pode ser alterado, e entrar� na fun��o
		{
			//que traz os menus perguntando o que deseja alterar. Ao encerrar a fun��o
			menuAlterarCliente(cliente, i, &x);   //chamada, ele encerra esta fun��o.
			system("pause");
			system("cls");
			return;
		}
	}

	printf("CPF N�O ENCONTRADO!\n");     //Caso n�o encontre CPF nenhum, ele exibir� esta mensagem, limpar� a tela e encerrar�
	system("pause");                     //essa fun��o
	system("cls");

}

void cadastroCliente(int *contCli)    //Fun��o que recebe as informa��es principais de cada cliente, presentes na estrutura
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
			//acusa erro caso j� exista um cpf com o mesmo n�mero e encerra a fun��o
			printf("Erro. CPF j� cadastrado\n");  //voltando assim para o menuCliente.
			return;
		}
	}                                            //Caso n�o encontre nada no la�o de repeti��o acima, o programa avan�a
	strcpy(cliente[x].cpf, cpf2);                //para estas leituras de dados.
	printf("Informe o nome do cliente: ");
	scanf("%s", cliente[x].nome);
	printf("Informe o endere�o do cliente: ");
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
			if(y > CLI)     //Se o n�mero de clientes for excedido, o programa n�o cadastra mais nada.
			{
				printf("N�mero de clientes excedido!");
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
			printf("Erro. Informe uma op��o v�lida: \n");
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

//AQUI INICIAMOS O MENU CONTA E SUAS FUN��ES

void cadastrarConta(int *contContasMenuConta, int *contClienteMenuConta)
{
	int numAgencia;
	int numConta;
	int aux;
	int y = *contContasMenuConta;
	int b = *contClienteMenuConta;
	int h;

	printf("\n\nContador: %d contas\n\n", y); // APAGAR ESTA LINHA AO FINAL DO TRABALHO. MOTIVO: S� CONTADOR

	printf("Digite o numero da Ag�ncia: ");
	scanf("%d", &numAgencia);
	printf("Digite o numero da Conta: ");
	scanf("%d", &numConta);

	for(aux = 0; aux <= y; aux++)
	{
		if(numAgencia == contas[aux].agencia && numConta == contas[aux].nCont)
		{
			printf("CONTAS J� CADASTRADA\n");
			return;
		}
	}

	h = validarCPF(cliente, &b, &y);
	if(h == 0)
	{
		printf("CPF N�O CADASTRADO!!\n");
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
			if(contContasMenuConta > CONTAS) //Caso o n�mero de contas exceda o valor m�ximo estipulado no define, o programa
			{
				//n�o cadastra.
				printf("N�mero de contas excedido!\n");
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
			printf("Erro. Informe uma op��o v�lida: \n");
		}
	}
	while(option != 0);
	*contContas = contContasMenuConta;

}

//AQUI INICIAMOS O MENU MOVIMENTO E SUAS FUN��ES
void menuMovimento()
{
	int option;

	printf("<<<<<<<<<<<<<<  MENU CLIENTE  >>>>>>>>>>>>>>\n");
	setlocale(LC_ALL, "Portuguese");
	printf("--------------------------------------------\n");
	printf("| 1- Dep�sito                              |\n");
	printf("| 2- Saque                                 |\n");
	printf("| 3- Transfer�ncia                         |\n");
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
			printf("Erro. Informe uma op��o v�lida: \n");
		}
	}
	while(option != 0);


}

//E AQUI INICIAMOS O MENU RELART�RIOS E SUAS FUN��ES




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
				printf("N�O EXISTE NENHUMA CONTA COM ESSES REQUISITOS\n");
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
				printf("N�O EXISTE NENHUMA CONTA COM ESSES REQUISITOS\n");
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
				printf("N�O EXISTE NENHUMA CONTA COM ESSES REQUISITOS\n");
			}
			system("pause");
			system("cls");
			break;
		case 0:
			break;
		default:
			printf("Erro. Informe uma op��o v�lida: \n");
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
		printf("CPF N�O CADASTRADO!\n");
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
	printf("| 3- Listar os dados cadastrais de todos clientes (ativos ou n�o)                             |\n");
	printf("| 4- Listar as informa��es de todas as contas                                                 |\n");
	printf("| 5- Listar as informa��es de todos os clientes incluindo suas contas                         |\n");
	printf("| 6- Listar os dados cadastrais de todos os clientes ativos de uma ag�ncia ordenados pelo cpf |\n");
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
			printf("Erro. Informe uma op��o v�lida: \n");
		}
	}
	while(option != 0);
}



// FUN��O DE MENU PRINCIPAL
void menuPrincipal(int *option)
{
	int o;
	printf("<<<<<<<<<<<<<< MENU PRINCIPAL >>>>>>>>>>>>>>\n");
	setlocale(LC_ALL, "Portuguese");
	printf("--------------------------------------------\n");
	printf("| 1- Cliente                               |\n");
	printf("| 2- Conta                                 |\n");
	printf("| 3- Movimento                             |\n");
	printf("| 4- Relat�rio                             |\n");
	printf("| 0- Sair                                  |\n");
	printf("--------------------------------------------\n");
	printf("Informe uma op��o: ");
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

	printf("Programa de gest�o banc�ria finalizado!\n");
	printf("By Raphael K�nnedy e Thales Abdon.\n");
	printf("Merry Christmas Dra. Rosianni.\n");
	printf("                ��\n");
	printf("Coffee is life C\\__/\n");
	return 0;
}