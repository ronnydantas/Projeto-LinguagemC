#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <conio.h>

typedef struct Relatorio {
char nome[50];
char texto[1000];
char data[15];
char deletado;
} relatorios;
FILE *arq;
relatorios maxi[1000];

void montarMenuRelatorios(void);
void gerenciarRelatorios(int opcao);
void cadastrarRelatorios(void);
void alterarRelatorios(void);
void consultarRelatorios(void);
void excluirRelatorios(void);

void montarMenuRelatorios()
{
    int opcao = 0;
    printf("\n\tMenu de Relatórios\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Cadastrar Relatórios\n");
    printf("2. Alterar Relatórios\n");
    printf("3. Consultar Relatórios\n");
    printf("4. Excluir Relatórios\n");
    printf("5. Voltar ao Menu Administrador\n");
    system("pause>nul");
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarRelatorios(opcao);
}

void gerenciarRelatorios(int opcao)
{
    switch(opcao)
    {
        case 1:
            cadastrarRelatorios();
            break;
        case 2:
            alterarRelatorios();
            break;
        case 3:
            consultarRelatorios();
            break;
        case 4:
            excluirRelatorios();
            break;
        case 5:
            menuAdministrador();
            break;
        default:
            printf("Digite uma opção válida!\n");
            montarMenuRelatorios();
    }
}

void cadastrarRelatorios()
{
    struct Relatorio relatorios;
    int retorno;
    arq = fopen("relatorios.pro", "a");
    if (arq == NULL)
    {
        retornarMensagem("Erro ao abrir arquivo");
        return;
    }
    printf("\n\t\t\t\|SISTEMA DE CADASTRO DE RELATÓRIO|\n");
    printf("\nDigite o título do relátório: ");
    scanf("%s", &relatorios.nome);
    printf("Digite o relatório: ");
    fflush(stdin);
    gets(relatorios.texto);
    printf("Digite a data: ");
    scanf("%s", &relatorios.data);
    retorno = fwrite (&relatorios, sizeof(relatorios), 1, arq);
    if (retorno == 1)
    {
        fclose (arq);
        retornarMensagem("\nRelatório cadastrado com sucesso!");
        system("pause>nul");
        system("cls || clear");
        montarMenuRelatorios();
    }
    else
    {
        fclose (arq);
        retornarMensagem("\n Falha ao cadastrar relatório.");
        system("pause>nul");
        system("cls || clear");
        montarMenuRelatorios();
    }
}

void alterarRelatorios()
{
    {
        arq = fopen("relatorios.pro", "r+b");
        if (arq == NULL)
        {
            retornarMensagem("\nArquivo inexistente!");
            system("pause>nul");
            system("cls || clear");
            montarMenuRelatorios();
        }

        struct Relatorio relatorios;
        char nome[50];
        int encontrado = 0;
        printf ("\nDigite o nome que procura: ");
        scanf ("%s", &nome);

        while (fread (&relatorios, sizeof(relatorios), 1, arq))
        {
            if ((relatorios.nome[0] == nome[0]) && (relatorios.deletado != '*'))
            {
                printf("\nNome do relatório: %s\nTexto: %s\nData:  %s\n",relatorios.nome, relatorios.texto, relatorios.data);
                encontrado = 1;

                fseek(arq,sizeof(struct Relatorio)*-1, SEEK_CUR);
                printf("\nDigite o novo texto: ");
                fflush(stdin);
                gets(relatorios.texto);
                printf("Digite a nova data: ");
                scanf("%s", &relatorios.data);

                fwrite(&relatorios, sizeof(relatorios), 1, arq);
                fseek(arq, sizeof(relatorios)* 0, SEEK_END);

                retornarMensagem("\n\t\t\t|Dados do relatório alterados com sucesso!|");
                system("pause>nul");
                system("cls || clear");
                montarMenuRelatorios();
            }
        }
        if (!encontrado)
        {
            retornarMensagem("\n\t\t\tNome não cadastrado!\n");
            system("pause>nul");
            system("cls || clear");
            montarMenuRelatorios();
        }
        fclose(arq);
    }

}

void consultarRelatorios()
{
    {
        arq = fopen("relatorios.pro", "rb");
        if (arq == NULL)
        {
            retornarMensagem("\nArquivo inexistente!");
            system("pause>nul");
            system("cls || clear");
            montarMenuRelatorios();
        }
        struct  Relatorio relatorios;
        char nome[50];
        int encontrado = 0;
        printf ("\nDigite o relatório que procura: ");
        scanf ("%s", &nome);

        while (fread (&relatorios, sizeof(relatorios), 1, arq))
        {
            if ((relatorios.nome[0] == nome[0]) && (relatorios.deletado != '*'))
            {
                printf("\nNome do relatório: %s\nTexto: %s\nData: %s\n",relatorios.nome, relatorios.texto, relatorios.data);
                encontrado = 1;
                system("pause>nul");
                system("cls || clear");
                montarMenuRelatorios();
            }
        }
        if (!encontrado)
        {
            retornarMensagem("\nRelatório não cadastrado!\n");
            system("pause>nul");
            system("cls || clear");
            montarMenuRelatorios();
        }
        fclose(arq);
    }
}

void excluirRelatorios()
{
    char excluir;
    printf("\t\t\t\t\t|AVISO|\n");
    printf("TODOS OS RELATÓRIOS SERÃO APAGADOS!\n");
    printf("NÃO É POSSÍVEL RECUPERAR!");
    printf("\n\n");
    printf("Deseja realmente apagar todos os relatórios? [S/N} \n");
    scanf("%s", &excluir);
    printf("\n");

    while (excluir != 's' || excluir != 'S')
    {
        if (excluir == 's' || excluir == 'S')
        {
            arq = fopen("relatorios.pro", "w++");

            fclose(arq);
            printf("\nRelatórios excluídos como solicitado.");
            getch();
            system("clear||cls");
            montarMenuRelatorios();

        }
        if (excluir == 'n' || excluir == 'N')
        {
            printf("\nNenhum relatório foi excluído!\n\n\n\n");
            system("clear||cls");
            montarMenuRelatorios();
        }
    }
}
