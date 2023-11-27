#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <conio.h>

typedef struct Estabelecimento {
char nome[50];
char localizacao[100];
char fone[20];
char email[50];
char cidade[50];
char estado[50];
char tipo[100];
char senha[50];
char deletado;
}estabelecimentos;
FILE *arq;
estabelecimentos maximo [1000];

void montarMenuEstabelecimento(void);
void gerenciarMenuEstabelecimento(int opcao);
void cadastroEstabelecimento(void);
void loginEstabelecimento(void);
void menuEstabelecimento(void);
void listarEstabelecimento(void);
void alterarEstabelecimento(void);
void consultarEstabelecimento(void);
void excluirEstabelecimento(void);
void estabelecimentosAdministrador(void);

void estabelecimentosAdministrador()
{
    int continuar = 0;

    printf("\n\tMenu de Estabelecimentos\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Cadastrar Estabelecimento\n");
    printf("2. Alterar Estabelecimento\n");
    printf("3. Consultar Estabelecimento\n");
    printf("4. Excluir Estabelecimento\n");
    printf("5. Voltar ao Menu Administrador\n");

    scanf("%i", &continuar);
    system("cls || clear");

    switch(continuar)
    {
        case 1:
            cadastroEstabelecimento();
            break;
        case 2:
            alterarEstabelecimento();
            break;
        case 3:
            consultarEstabelecimento();
            break;
        case 4:
            excluirEstabelecimento();
            break;
        case 5:
            menuAdministrador();
            break;
        default:
            printf("Digite uma opção válida!\n");
            estabelecimentosAdministrador();
    }
}

void montarMenuEstabelecimento()
{
    int opcao = 0;
    printf("\n\tMenu de Estabelecimento\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Caso já tenha cadastro e deseja se logar.\n");
    printf("2. Caso não tenha cadastro e deseja criar um.\n");
    printf("3. Voltar ao menu principal.\n");
    system("pause>nul");
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarMenuEstabelecimento(opcao);
}

void gerenciarMenuEstabelecimento(int opcao)
{
    switch(opcao)
    {
        case 1:
            loginEstabelecimento();
            break;
        case 2:
            cadastroEstabelecimento();
            break;
        case 3:
            montarMenuPrincipal();
        default:
            printf("Digite uma opção válida!\n");
            montarMenuEstabelecimento();
    }
}

void menuEstabelecimento()
{
    int continuar = 0;

    printf("\n\tMenu do Estabelecimento\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Alterar Cadastro\n");
    printf("2. Excluir Cadastro\n");
    printf("3. Listar Clientes\n");
    printf("4. Voltar ao Menu Principal\n");
    printf("5. Sair do Programa\n");

    scanf("%i", &continuar);
    system("cls || clear");

    switch(continuar)
    {
        case 1:
            alterarEstabelecimento();
            break;
        case 2:
            excluirEstabelecimento();
            break;
        case 3:
            listarCliente();
            break;
        case 4:
            montarMenuPrincipal();
        case 5:
            sair();
            break;
        default:
            printf("Digite uma opção válida!\n");
            menuEstabelecimento();
    }
}

void cadastroEstabelecimento()
{
    printf("\n\t\t\t|SISTEMA DE CADASTRO DE ESTABELECIMENTO|\n");
    arq = fopen("estabelecimento.pro", "ab");
    struct Estabelecimento estabelecimentos;
    int cont, i = 0;
    int voltar;
    int adicionar;
    int opcao = 0;

    printf("\nQual o nome do estabelecimento: ");
    scanf("%s", &estabelecimentos.nome);
    printf("Telefone do estabelecimento: ");
    scanf("%s", &estabelecimentos.fone);
    printf("Qual o estado: ");
    scanf("%s", &estabelecimentos.estado);
    printf("Qual a cidade: ");
    scanf("%s", &estabelecimentos.cidade);
    printf("Endereço do estabelecimento: ");
    scanf("%s", &estabelecimentos.localizacao);
    printf("Qual o tipo do estabelecimento (ex:casa de show, bar, produtora, empresário): ");
    scanf("%s", &estabelecimentos.tipo);
    printf("Qual o e-mail do estabelecimento: ");
    scanf("%s", &estabelecimentos.email);
    printf("Crie uma senha: ");
    scanf("%s", &estabelecimentos.senha);

    voltar = fwrite(&estabelecimentos, sizeof(estabelecimentos), 1, arq);
    fclose(arq);
    if (voltar == 1){
        printf("\nCadastro realizado com sucesso!\n");
        getch();
        system("clear || cls");
        loginEstabelecimento();
}
    else
        {
        printf("\nHouve erro ao cadastrar, favor tente novamente.\n");
        cadastroEstabelecimento();
    }
}

void loginEstabelecimento()
{
    int i = 0, valor = 1, cont = 0;
    char email[50];
    char senha[50];

    arq = fopen("estabelecimento.pro", "rb");
    printf("\n\t\t\t\t|SISTEMA DE LOGIN DE ESTABELECIMENTO|\n");
    printf("\nDigite o seu e-mail: ");
    scanf("%s", &email);
    printf("\nDigite a senha: ");
    scanf("%s", &senha);
    valor = fread(&maximo[i], sizeof(estabelecimentos), 1, arq);
    printf("%d", valor);
    while (valor ==1)
    {
        if (strcmp(email, maximo[i].email)==0)
        {
           if (strcmp(senha, maximo[i].senha)==0)
            {
                fclose(arq);
                system("clear || cls");
                menuEstabelecimento();
                cont++;
            }
        }
        i++;
        valor = fread(&maximo[i], sizeof(estabelecimentos), 1, arq);
    }
    if (cont ==0)
    {
        fclose(arq);
        system("cls || clear");
        printf("\nLogin ou senha incorreto! Digite novamente.\n");
        loginEstabelecimento();
    }
    getch();
    system("cls || clear");
}

void alterarEstabelecimento()
{
arq = fopen("estabelecimento.pro", "r+b");

    if (arq == NULL)

    {
        retornarMensagem("\nArquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        estabelecimentosAdministrador();
    }

    struct Estabelecimento estabelecimentos;
    char nome[50];
    int encontrado = 0;
    int valor;
    printf ("\nDigite o nome que procura: ");
    scanf ("%s", &nome);
    while (fread (&estabelecimentos, sizeof(estabelecimentos), 1, arq))
    {
        if ((estabelecimentos.nome[0] == nome[0]) && (estabelecimentos.deletado != '*'))
        {
            printf("\nNome do estabelecimento: %s",estabelecimentos.nome);
            printf("\nTelefone do estabelecimento: %s",estabelecimentos.fone);
            printf("\nEstado: %s",estabelecimentos.estado);
            printf("\nCidade: %s",estabelecimentos.cidade);
            printf("\nEndereço do estabelecimento: %s",estabelecimentos.localizacao);
            printf("\nTipo do estabelecimento: %s",estabelecimentos.tipo);
            printf("\nE-mail do estabelecimento: %s",estabelecimentos.email);

            encontrado = 1;

            fseek(arq,sizeof(struct Estabelecimento)*-1, SEEK_CUR);

            printf("\n\nDigite o novo nome: ");
            fflush(stdin);
            gets(estabelecimentos.nome);
            printf("Digite o novo telefone: ");
            scanf(" %s", &estabelecimentos.fone);
            printf("Digite o novo estado: ");
            scanf(" %s", &estabelecimentos.estado);
            printf("Digite a nova cidade: ");
            scanf(" %s", &estabelecimentos.cidade);
            printf("Digite o novo endereço: ");
            scanf(" %s", &estabelecimentos.localizacao);
            printf("Digite a nova senha: ");
            scanf(" %s", &estabelecimentos.senha);


            fwrite(&estabelecimentos, sizeof(estabelecimentos), 1, arq);
            fseek(arq, sizeof(estabelecimentos)* 0, SEEK_END);

            retornarMensagem("\n\t\t\t|Dados do funcionário alterados com sucesso!|");
            system("pause>nul");
            system("cls || clear");
            estabelecimentosAdministrador();
        }
    }
    if (!encontrado)
    {
        retornarMensagem("\nNome não cadastrado!\n");
        system("pause>nul");
        system("cls || clear");
        estabelecimentosAdministrador();
    }
    fclose(arq);
}

void consultarEstabelecimento()
{
    {
        arq = fopen("estabelecimento.pro", "rb");
        if (arq == NULL)
        {
            retornarMensagem("\nArquivo inexistente!");
            system("pause>nul");
            system("cls || clear");
            montarMenuEstabelecimento();
        }
        struct  Estabelecimento estabelecimentos;
        char nome[50];
        int encontrado = 0;
        printf ("\nDigite o estabelecimento que procura: ");
        scanf ("%s", &nome);

        while (fread (&estabelecimentos, sizeof(estabelecimentos), 1, arq))
        {
            if ((estabelecimentos.nome[0] == nome[0]) && (estabelecimentos.deletado != '*'))
            {
                printf("\nNome do estabelecimento: %s",estabelecimentos.nome);
                printf("\nTelefone do estabelecimento: %s",estabelecimentos.fone);
                printf("\nEstado: %s",estabelecimentos.estado);
                printf("\nCidade:  %s",estabelecimentos.cidade);
                printf("\nEndereço do estabelecimento:  %s",estabelecimentos.localizacao);
                printf("\nTipo do estabelecimento: %s",estabelecimentos.tipo);
                printf("\nE-mail do estabelecimento:  %s",estabelecimentos.email);
                encontrado = 1;
                system("pause>nul");
                system("cls || clear");
                estabelecimentosAdministrador();
            }
        }
        if (!encontrado)
        {
            retornarMensagem("\nEstabelecimento não cadastrado!\n");
            system("pause>nul");
            system("cls || clear");
            estabelecimentosAdministrador();
        }
        fclose(arq);
    }
}

void excluirEstabelecimento()
{
    char excluir;
    printf("\t\t\t\t\t|AVISO|\n");
    printf("TODOS OS ESTABELECIMENTOS SERÃO APAGADOS!\n");
    printf("NÃO É POSSÍVEL RECUPERAR!");
    printf("\n\n");
    printf("Deseja realmente apagar todos os estabelecimentos? [S/N} \n");
    scanf("%s", &excluir);
    printf("\n");

    while (excluir != 's' || excluir != 'S')
    {
        if (excluir == 's' || excluir == 'S')
        {
            arq = fopen("estabelecimento.pro", "w++");
            fclose(arq);
            printf("Todos os estabelecimentos foram excluídos com sucesso.");
            getch();
            system("clear||cls");
            montarMenuPrincipal();

        }
        if (excluir == 'n' || excluir == 'N')
        {
            printf("Nenhum estabelecimento foi excluído!\n\n\n\n");
            system("clear||cls");
            menuEstabelecimento();
        }
    }
}

void listarEstabelecimento()
{
    int i = 0, retorno;

    arq = fopen("estabelecimento.pro", "a+b");
    if (arq == NULL){
       printf ("\nErro!\nO arquivo da lista não pode ser aberto!\n");
       getch();
       montarMenuEstabelecimento();
    }
    retorno = fread(&maximo[i], sizeof(estabelecimentos), 1, arq);
    while (retorno == 1){
      printf("\n Nome: %s",maximo[i].nome);
      printf("\n Endereço: %s",maximo[i].localizacao);
      printf("\n Estado: %s",maximo[i].estado);
      printf("\n Cidade: %s",maximo[i].cidade);
      printf("\n Telefone: %s",maximo[i].fone);
      printf("\n Tipo Estabelecimento: %s",maximo[i].tipo);
      printf("\n E-mail: %s\n",maximo[i].email);
      i++;
      retorno = fread(&maximo[i], sizeof(estabelecimentos), 1, arq);
    }
    printf(" \n\n %d Contatos salvos!\n ", i);
    getch();
    fclose(arq);
    system("cls || clear");
    menuCliente();
}
