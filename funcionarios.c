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
    printf("\n\tMenu de Funcionários\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Cadastrar Funcionários\n");
    printf("2. Alterar Funcionários\n");
    printf("3. Consultar Funcionários\n");
    printf("4. Excluir Funcionários\n");
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
            printf("Digite uma opcão válida\n");
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
    printf("\n\t\t\t\|SISTEMA DE CADASTRO DE FUNCIONÁRIO|\n");
    printf("\nDigite o nome: ");
    scanf("%s", &funcionarios.nome);
    printf("Digite o CPF: ");
    scanf("%s", &funcionarios.cpf);
    printf("Digite o cargo: ");
    fflush(stdin);
    gets(funcionarios.cargo);
    printf("Digite a função: ");
    scanf("%s", &funcionarios.funcao);
    retorno = fwrite (&funcionarios, sizeof(funcionarios), 1, arq);
    if (retorno == 1)
    {
        fclose (arq);
        retornarMensagem("\nDados do funcionário incluídos com sucesso!");
        system("pause>nul");
        system("cls || clear");
        montarMenuFuncionarios();
    }
    else
    {
        fclose (arq);
        retornarMensagem("\n Falha ao gravar dados do funcionário.");
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
            printf("\nNome do funcionário: %s\nCPF: %s\nCargo: %s\nFunção: %s\n",funcionarios.nome, funcionarios.cpf, funcionarios.cargo, funcionarios.funcao);
            encontrado = 1;

            fseek(arq,sizeof(struct Funcionario)*-1, SEEK_CUR);
            printf("\nDigite o novo cargo: ");
            fflush(stdin);
            gets(funcionarios.cargo);
            printf("Digite a nova função: ");
            scanf("%s", &funcionarios.funcao);

            fwrite(&funcionarios, sizeof(funcionarios), 1, arq);
            fseek(arq, sizeof(funcionarios)* 0, SEEK_END);

            retornarMensagem("\n\t\t\t|Dados do funcionário alterados com sucesso!|");
            system("pause>nul");
            system("cls || clear");
            montarMenuFuncionarios();
        }
    }
    if (!encontrado)
    {
        retornarMensagem("\n\t\t\tNome não cadastrado!\n");
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
            printf("\nNome do funcionário: %s\nCPF: %s\nCargo: %s\nFunção: %s\n",funcionarios.nome, funcionarios.cpf, funcionarios.cargo, funcionarios.funcao);
            encontrado = 1;
            system("pause>nul");
            system("cls || clear");
            montarMenuFuncionarios();
        }
    }
    if (!encontrado)
    {
        retornarMensagem("\nFuncionário não cadastrado!\n");
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
    printf("TODOS OS FUNCIONÁRIOS SERÃO APAGADOS!\n");
    printf("NÃO É POSSÍVEL RECUPERAR!");
    printf("\n\n");
    printf("Deseja realmente apagar todos os funcionários? [S/N} \n");
    scanf("%s", &excluir);
    printf("\n");

    while (excluir != 's' || excluir != 'S')
    {
        if (excluir == 's' || excluir == 'S')
        {
            arq = fopen("funcionarios.pro", "w++");

            fclose(arq);
            printf("\nFuncionários excluídos como solicitado.");
            getch();
            system("clear||cls");
            montarMenuFuncionarios();

        }
        if (excluir == 'n' || excluir == 'N')
        {
            printf("\nNenhum funcionário foi apagado!\n\n\n\n");
            system("clear||cls");
            montarMenuFuncionarios();
        }
    }
}
