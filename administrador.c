#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <conio.h>

void loginAdm(void);
void menuAdministrador(void);

void loginAdm()
{
    int continuar = 0;

    printf("\n\t\t\t\t| ACESSO ADMINISTRADOR |\n\n\n");
    printf("\tDigite o login e a senha para ter acesso às funções de administrador.\n\n\n");

    char login[15] = "adm";
    char login1[15];
    char senha[15] = "adm";
    char senha1[15];

    printf("Digite o Login: ");
    scanf("%s", login1);

    printf("\nDigite a Senha: ");
    scanf("%s", senha1);

    if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0) {

        system ("cls || clear");
        printf("\n\t\t\t\tLOGADO!\n\n");
        printf("1. Entrar\n");
        printf("2. Voltar\n");
        scanf("%d", &continuar);
        system ("cls || clear");

        switch(continuar)
        {
            case 1:
                menuAdministrador();
            case 2:
                montarMenuPrincipal();
            default:
                printf("Digite uma opção valida!\n");
                loginAdm();
        }

                } else

                system("cls||clear");
                printf("\n\n\t\t\t\tDADOS INVÁLIDOS!\n");
                printf("\nDados de administrador não constam.\n\n");
                printf("1. Para inserir os dados novamente.\n");
                printf("2. Para voltar  ao menu principal.\n");
                scanf("%i", &continuar);
                system("cls||clear");

                switch(continuar)
                {
                    case 1:
                        return loginAdm();
                    case 2:
                        montarMenuPrincipal();
                    default:
                        printf("Digite uma opção válida!\n");
                        loginAdm();
                }
}

void menuAdministrador()
{
    int continuar = 0;

    printf("\n\tMenu de Administrador\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Gerenciar Funcionários\n");
    printf("2. Gerenciar Relatorios\n");
    printf("3. Gerenciar Clientes\n");
    printf("4. Gerenciar Estabelecimentos\n");
    printf("5. Voltar ao Menu Principal\n");
    printf("6. Sair do Programa\n");

    scanf("%d", &continuar);
    system("cls || clear");

    switch(continuar)
    {
        case 1:
            montarMenuFuncionarios();
            break;
        case 2:
            montarMenuRelatorios();
            break;
        case 3:
            clientesAdministrador();
            break;
        case 4:
            estabelecimentosAdministrador();
            break;
        case 5:
            montarMenuPrincipal();
            break;
        case 6:
            sair();
        default:
            printf("Digite uma opção válida!\n");
            menuAdministrador();
    }
}
