#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <conio.h>

void gerenciarCores(int opcao);
void montarMenuPrincipal(void);
void gerenciarMenuPrincipal(int opcao);
void sair(void);

void retornarMensagem(const char* mensagem)
{
    printf(mensagem);
    return;
}

void sair()
{
    printf("\tObrigado por acessar nosso programa em C criado para apresentação do PIM!\n\n\n");
    printf("\t\t\t\t             OOOOOOOOOOO               \n");
    printf("\t\t\t\t         OOOOOOOOOOOOOOOOOOO           \n");
    printf("\t\t\t\t      OOOOOO  OOOOOOOOO  OOOOOO        \n");
    printf("\t\t\t\t    OOOOOO      OOOOO      OOOOOO      \n");
    printf("\t\t\t\t  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
    printf("\t\t\t\t OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
    printf("\t\t\t\tOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
    printf("\t\t\t\tOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
    printf("\t\t\t\tOOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
    printf("\t\t\t\t OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
    printf("\t\t\t\t  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
    printf("\t\t\t\t    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
    printf("\t\t\t\t      OOOOOO   OOOOOOOOO   OOOOOO      \n");
    printf("\t\t\t\t         OOOOOO         OOOOOO         \n");
    printf("\t\t\t\t             OOOOOOOOOOOO              \n\n");
    exit(1);
}

void configurarTela()
{
    int opcao = 0;
    printf("A primeira cor corresponde ao fundo, e a segunda aos caracteres.\n\n");
    printf("1. Cinza/Amarelo\n");
    printf("2. Branco/Roxo\n");
    printf("3. Verde-água/Azul-escuro\n");
    printf("4. Preto/Branco-brilhante\n");
    printf("5. Voltar ao Menu Principal\n");
    system("pause>nul");
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarCores(opcao);
}

void gerenciarCores(int opcao)
{
    switch(opcao)
    {
        case 1:
            system("color 8E");
            montarMenuPrincipal();
            break;

        case 2:
            system("color F5");
            montarMenuPrincipal();
            break;

        case 3:
            system("color B1");
            montarMenuPrincipal();
            break;

        case 4:
            system("color 0F");
            montarMenuPrincipal();
            break;
        case 5:
            montarMenuPrincipal();
            break;
        default:
            printf("Digite uma opção válida!\n");
            configurarTela();
    }
}

void sobre()
{
    printf("\t\t\tPIM\n\n");
    printf("\tAnálise e Desenvolvimento de Sistemas\n\tProjeto Integrado Multidisciplinar\n\tUNIP - Universidade Paulista\n");
    printf("\t2º Semestre - 2022\n");
    printf("\n\tUNIMUSIC - Plataforma de contratação de musicos.\n\n");
    printf("\tIntegrantes:\n\tRaul Sanches Pedrosa\n\tRonny Fabiano Dantas\n\tSavio Emanuel B Gonçalves\n\tVinicius Bezerra Pimentel\n\n\n");
    printf("\tNesse presente projeto tivemos a ideia de criar uma palataforma de musicos, onde no mesma existe a\n");
    printf("\tpossibilidade de cadastro de clientes e contratantes, onde os dois poderão se consultar e conseguir informações \n");
    printf("\tde contato para fins trabalhistas.\n\n\n");
    getch();
    system("cls || clear");
    montarMenuPrincipal();
}

void montarMenuPrincipal()
{
    int opcao = 0;
    printf("\n\tMenu Principal\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Menu Administrador\n");
    printf("2. Menu Cliente\n");
    printf("3. Menu Estabelecimento\n");
    printf("4. Configurar Cores\n");
    printf("5. Sobre\n");
    printf("6. Sair\n");
    system("pause>nul");
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarMenuPrincipal(opcao);
}

void gerenciarMenuPrincipal(int opcao)
{
    switch(opcao)
    {
        case 1:
            loginAdm();
            break;
        case 2:
            montarMenuCliente();
            break;
        case 3:
            montarMenuEstabelecimento();
            break;
        case 4:
            configurarTela();
            break;
        case 5:
            sobre();
        case 6:
            sair();
        default:
            printf("Digite uma opção válida!\n");
            montarMenuPrincipal();
    }
}
