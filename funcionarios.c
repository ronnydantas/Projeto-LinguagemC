#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <conio.h>

typedef struct Funcionario {
char nome[50];
char cpf[50];
char cargo[50];
char funcao[100];
char deletado;
} funcionarios;
FILE *arq;
funcionarios maximum[100];

void montarMenuFuncionarios(void);
void gerenciarFuncionarios(int opcao);
void cadastrarFuncionarios(void);
void alterarFuncionarios(void);
void consultarFuncionarios(void);
void excluirFuncionarios(void);

void montarMenuFuncionarios()
{
    int opcao = 0;
    printf("\n\tMenu de Funcion�rios\n\n");
    printf("Informe uma op��o v�lida e aperte a tecla enter\n\n");
    printf("1. Cadastrar Funcion�rios\n");
    printf("2. Alterar Funcion�rios\n");
    printf("3. Consultar Funcion�rios\n");
    printf("4. Excluir Funcion�rios\n");
    printf("5. Voltar ao Menu Administrador\n");
    system("pause>nul");
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarFuncionarios(opcao);
}

void gerenciarFuncionarios(int opcao)
{
    switch(opcao)
    {
        case 1:
            cadastrarFuncionarios();
            break;
        case 2:
            alterarFuncionarios();
            break;
        case 3:
            consultarFuncionarios();
            break;
        case 4:
            excluirFuncionarios();
            break;
        case 5:
            menuAdministrador();
            break;
        default:
            printf("Digite uma opc�o v�lida\n");
            montarMenuFuncionarios();
    }
}

void cadastrarFuncionarios()
{
    struct Funcionario funcionarios;
    int retorno;
    arq = fopen("funcionarios.pro", "a");
    if (arq == NULL)
    {
        retornarMensagem("\nErro ao abrir arquivo");
        return;
    }
    printf("\n\t\t\t\|SISTEMA DE CADASTRO DE FUNCION�RIO|\n");
    printf("\nDigite o nome: ");
    scanf("%s", &funcionarios.nome);
    printf("Digite o CPF: ");
    scanf("%s", &funcionarios.cpf);
    printf("Digite o cargo: ");
    fflush(stdin);
    gets(funcionarios.cargo);
    printf("Digite a fun��o: ");
    scanf("%s", &funcionarios.funcao);
    retorno = fwrite (&funcionarios, sizeof(funcionarios), 1, arq);
    if (retorno == 1)
    {
        fclose (arq);
        retornarMensagem("\nDados do funcion�rio inclu�dos com sucesso!");
        system("pause>nul");
        system("cls || clear");
        montarMenuFuncionarios();
    }
    else
    {
        fclose (arq);
        retornarMensagem("\n Falha ao gravar dados do funcion�rio.");
        system("pause>nul");
        system("cls || clear");
        montarMenuFuncionarios();
    }
}

void alterarFuncionarios()
{
    arq = fopen("funcionarios.pro", "r+b");
    if (arq == NULL)
    {
        retornarMensagem("\nArquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenuFuncionarios();
    }

    struct Funcionario funcionarios;
    char nome[50];
    int encontrado = 0;
    printf ("\nDigite o nome que procura: ");
    scanf ("%s", &nome);

    while (fread (&funcionarios, sizeof(funcionarios), 1, arq))
    {
        if ((funcionarios.nome[0] == nome[0]) && (funcionarios.deletado != '*'))
        {
            printf("\nNome do funcion�rio: %s\nCPF: %s\nCargo: %s\nFun��o: %s\n",funcionarios.nome, funcionarios.cpf, funcionarios.cargo, funcionarios.funcao);
            encontrado = 1;

            fseek(arq,sizeof(struct Funcionario)*-1, SEEK_CUR);
            printf("\nDigite o novo cargo: ");
            fflush(stdin);
            gets(funcionarios.cargo);
            printf("Digite a nova fun��o: ");
            scanf("%s", &funcionarios.funcao);

            fwrite(&funcionarios, sizeof(funcionarios), 1, arq);
            fseek(arq, sizeof(funcionarios)* 0, SEEK_END);

            retornarMensagem("\n\t\t\t|Dados do funcion�rio alterados com sucesso!|");
            system("pause>nul");
            system("cls || clear");
            montarMenuFuncionarios();
        }
    }
    if (!encontrado)
    {
        retornarMensagem("\n\t\t\tNome n�o cadastrado!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenuFuncionarios();
    }
    fclose(arq);
}

void consultarFuncionarios()
{
    arq = fopen("funcionarios.pro", "rb");
    if (arq == NULL)
    {
        retornarMensagem("\nArquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenuFuncionarios();
    }
    struct Funcionario funcionarios;
    char nome[50];
    int encontrado = 0;
    printf ("\nDigite o nome que procura: ");
    scanf ("%s", &nome);

    while (fread (&funcionarios, sizeof(funcionarios), 1, arq))
    {
        if ((funcionarios.nome[0] == nome[0]) && (funcionarios.deletado != '*'))
        {
            printf("\nNome do funcion�rio: %s\nCPF: %s\nCargo: %s\nFun��o: %s\n",funcionarios.nome, funcionarios.cpf, funcionarios.cargo, funcionarios.funcao);
            encontrado = 1;
            system("pause>nul");
            system("cls || clear");
            montarMenuFuncionarios();
        }
    }
    if (!encontrado)
    {
        retornarMensagem("\nFuncion�rio n�o cadastrado!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenuFuncionarios();
    }
    fclose(arq);
}

void excluirFuncionarios()
{
    char excluir;
    printf("\t\t\t\t\t|AVISO|\n");
    printf("TODOS OS FUNCION�RIOS SER�O APAGADOS!\n");
    printf("N�O � POSS�VEL RECUPERAR!");
    printf("\n\n");
    printf("Deseja realmente apagar todos os funcion�rios? [S/N} \n");
    scanf("%s", &excluir);
    printf("\n");

    while (excluir != 's' || excluir != 'S')
    {
        if (excluir == 's' || excluir == 'S')
        {
            arq = fopen("funcionarios.pro", "w++");

            fclose(arq);
            printf("\nFuncion�rios exclu�dos como solicitado.");
            getch();
            system("clear||cls");
            montarMenuFuncionarios();

        }
        if (excluir == 'n' || excluir == 'N')
        {
            printf("\nNenhum funcion�rio foi apagado!\n\n\n\n");
            system("clear||cls");
            montarMenuFuncionarios();
        }
    }
}
