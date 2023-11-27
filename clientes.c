#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <conio.h>

typedef struct Usuario {
char nome[100];
char email[100];
char senha[50];
char telefone[50];
char experiencia[1000];
char cidade[50];
char estado[50];
char idade[50];
char nomeart[50];
char ritmo[50];
char tipo[100];
char deletado;
} usuarios;
FILE *arq;
usuarios max[10000];

void montarMenuCliente(void);
void gerenciarMenuCliente(int opcao);
void cadastroCliente(void);
void loginCliente(void);
void menuCliente(void);
void alterarCliente(void);
void consultarCliente(void);
void listarCliente(void);
void excluirCliente(void);
void clientesAdministrador(void);

void clientesAdministrador()
{
    int continuar = 0;

    printf("\n\tMenu de Clientes\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Cadastrar Cliente\n");
    printf("2. Alterar Clientes\n");
    printf("3. Consultar Clientes\n");
    printf("4. Excluir Clientes\n");
    printf("5. Voltar ao Menu Administrador\n");

    scanf("%i", &continuar);
    system("cls || clear");

    switch(continuar)
    {
        case 1:
            cadastroCliente();
            break;
        case 2:
            alterarCliente();
            break;
        case 3:
            consultarCliente();
            break;
        case 4:
            excluirCliente();
            break;
        case 5:
            menuAdministrador();
            break;
        default:
            printf("Digite uma opção válida!\n");
            clientesAdministrador();
    }
}

void montarMenuCliente()
{
    int opcao = 0;
    printf("\n\tMenu Cliente\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Caso já tenha cadastro e deseja se logar.\n");
    printf("2. Caso não tenha cadastro e deseja criar um.\n");
    printf("3. Voltar ao menu principal.\n");
    system("pause>nul");
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarMenuCliente(opcao);
}

void gerenciarMenuCliente(int opcao)
{
    switch(opcao)
    {
        case 1:
            loginCliente();
            break;
        case 2:
            cadastroCliente();
            break;
        case 3:
            montarMenuPrincipal();
            break;
        default:
            printf("Digite uma opção válida!\n");
            montarMenuCliente();
    }
}

void cadastroCliente()
{
    printf("\n\t\t\t\|SISTEMA DE CADASTRO DE CLIENTE|\n");
    arq = fopen("clientes.pro", "ab");
    struct Usuario usuarios;
    int cont, i = 0;
    int voltar;
    int adicionar;
    int opcao = 0;

    printf("\nDigite seu nome: ");
    scanf("%s", &usuarios.nome);
    printf("Digite seu nome artístico: ");
    scanf("%s", &usuarios.nomeart);
    printf("Digite sua idade: ");
    scanf("%s", &usuarios.idade);
    printf("Digite o telefone: ");
    scanf("%s", &usuarios.telefone);
    printf("Digite seu ritmo musical: ");
    scanf("%s", &usuarios.ritmo);
    printf("Digite sua profissão: ");
    scanf("%s", &usuarios.tipo);
    printf("Digite sua experiência profissional: ");
    scanf("%s", &usuarios.experiencia);
    printf("Digite sua cidade: ");
    scanf("%s", &usuarios.cidade);
    printf("Digite seu estado: ");
    scanf("%s", &usuarios.estado);
    printf("Digite o email: ");
    scanf("%s", &usuarios.email);
    printf("Crie uma senha: ");
    scanf("%s", &usuarios.senha);
    voltar = fwrite(&usuarios, sizeof(usuarios), 1, arq);
    fclose(arq);
    if (voltar == 1){
        printf("\n\nCadastro realizado com sucesso!\n");
        getch();
        system("clear || cls");
        loginCliente();
}
    else
        {
        printf("\nHouve erro ao cadastrar, favor tente novamente.\n\n");
        cadastroCliente();
    }
}

void loginCliente()
{
    int i = 0, valor = 1, cont = 0;
    char email[50];
    char senha[50];

    arq = fopen("clientes.pro", "rb");
    printf("\n\t\t\t\t|SISTEMA DE LOGIN DE CLIENTE|\n");
    printf("\nDigite o seu e-mail: ");
    scanf("%s", &email);
    printf("\nDigite a senha: ");
    scanf("%s", &senha);
    valor = fread(&max[i], sizeof(usuarios), 1, arq);
    printf("%d", valor);
    while (valor ==1)
    {
        if (strcmp(email, max[i].email)==0)
        {
           if (strcmp(senha, max[i].senha)==0)
            {
                fclose(arq);
                system("clear || cls");
                menuCliente();
                cont++;
            }
        }
        i++;
        valor = fread(&max[i], sizeof(usuarios), 1, arq);
    }
    if (cont ==0)
    {
        fclose(arq);
        system("cls || clear");
        printf("\nLogin ou senha incorretos! Digite novamente.\n");
        loginCliente();
    }
    getch();
    system("cls || clear");
}

void alterarCliente()
{
    {
        arq = fopen("clientes.pro", "r+b");
        if (arq == NULL)
        {
            retornarMensagem("\nArquivo inexistente!");
            system("pause>nul");
            system("cls || clear");
            montarMenuCliente();
        }

        struct Usuario usuarios;
        char nome[50];
        int encontrado = 0;
        printf ("\nDigite o nome que procura: ");
        scanf ("%s", &nome);

        while (fread (&usuarios, sizeof(usuarios), 1, arq))
        {
            if ((usuarios.nome[0] == nome[0]) && (usuarios.deletado != '*'))
            {
                printf("\nNome do cliente: %s", usuarios.nome);
                printf("\nNome artístico: %s", usuarios.nomeart);
                printf("\nIdade: %s", usuarios.idade);
                printf("\nTelefone: %s", usuarios.telefone);
                printf("\nRitmo musical: %s", usuarios.ritmo);
                printf("\nProfissão: %s", usuarios.tipo);
                printf("\nExperiência Profisional: %s", usuarios.experiencia);
                printf("\nCidade: %s", usuarios.cidade);
                printf("\nEstado: %s", usuarios.estado);
                printf("\nE-mail: %s", usuarios.email);
                encontrado = 1;

                fseek(arq,sizeof(struct Usuario)*-1, SEEK_CUR);
                printf("\n\nDigite o novo nome: ");
                fflush(stdin);
                gets(usuarios.nome);
                printf("Digite o novo nome artístico: ");
                scanf("%s", &usuarios.nomeart);
                printf("Digite a nova idade: ");
                scanf("%s", &usuarios.idade);
                printf("Digite o novo telefone: ");
                scanf("%s", &usuarios.telefone);
                printf("Digite o novo ritmo musical: ");
                scanf("%s", &usuarios.ritmo);
                printf("Digite a nova profissão: ");
                scanf("%s", &usuarios.tipo);
                printf("Digite a nova experiência profissional: ");
                scanf("%s", &usuarios.experiencia);
                printf("Digite a nova cidade: ");
                scanf("%s", &usuarios.cidade);
                printf("Digite o novo estado: ");
                scanf("%s", &usuarios.estado);
                printf("Digite a senha: ");
                scanf("%s", &usuarios.email);

                fwrite(&usuarios, sizeof(usuarios), 1, arq);
                fseek(arq, sizeof(usuarios)* 0, SEEK_END);

                retornarMensagem("\n\t\t\t|Dados do cliente alterados com sucesso!|");
                system("pause>nul");
                system("cls || clear");
                clientesAdministrador();
            }
        }
        if (!encontrado)
        {
            retornarMensagem("\n\t\t\t|Nome não cadastrado!|\n");
            system("pause>nul");
            system("cls || clear");
            clientesAdministrador();
        }
        fclose(arq);
    }

}

void consultarCliente()
{
    {
        arq = fopen("clientes.pro", "rb");
        if (arq == NULL)
        {
            retornarMensagem("\nArquivo inexistente!");
            system("pause>nul");
            system("cls || clear");
            montarMenuCliente();
        }
        struct  Usuario usuarios;
        char nome[50];
        int encontrado = 0;
        printf ("\nDigite o cliente que procura: ");
        scanf ("%s", &nome);

        while (fread (&usuarios, sizeof(usuarios), 1, arq))
        {
            if ((usuarios.nome[0] == nome[0]) && (usuarios.deletado != '*'))
            {
                printf("\nNome do cliente: %s", usuarios.nome);
                printf("\nNome artístico: %s", usuarios.nomeart);
                printf("\nIdade: %s", usuarios.idade);
                printf("\nTelefone: %s", usuarios.telefone);
                printf("\nRitmo musical: %s", usuarios.ritmo);
                printf("\nProfissão: %s", usuarios.tipo);
                printf("\nExperiência Profisional: %s", usuarios.experiencia);
                printf("\nCidade: %s", usuarios.cidade);
                printf("\nEstado: %s", usuarios.estado);
                printf("\nE-mail: %s", usuarios.email);
                encontrado = 1;
                system("pause>nul");
                system("cls || clear");
                clientesAdministrador();
            }
        }
        if (!encontrado)
        {
            retornarMensagem("\nCliente não cadastrado!\n");
            system("pause>nul");
            system("cls || clear");
            clientesAdministrador();
        }
        fclose(arq);
    }
}

void excluirCliente(void)
{
    char excluir;
    printf("\t\t\t\t\tAVISO\n");
    printf("TODOS OS CLIENTES SERÃO APAGADOS!\n");
    printf("NÃO É POSSÍVEL RECUPERAR!");
    printf("\n\n");
    printf("Deseja realmente apagar todos os clientes? [S/N} \n");
    scanf("%s", &excluir);
    printf("\n");

    while (excluir != 's' || excluir != 'S')
    {
        if (excluir == 's' || excluir == 'S')
        {
            arq = fopen("clientes.pro", "w++");

            fclose(arq);
            printf("Clientes excluídos como solicitado.");
            getch();
            system("clear||cls");
            montarMenuPrincipal();

        }
        if (excluir == 'n' || excluir == 'N')
        {
            printf("Nenhum cliente foi apagado!\n\n\n\n");
            system("clear||cls");
            menuCliente();
        }
    }
}

void listarCliente()
{
    int i = 0, retorno;

    arq = fopen("clientes.pro", "a+b");
    if (arq == NULL){
       printf ("\nErro!\nO arquivo da lista não pode ser aberto!\n");
       getch();
       exit(1);
    }
    retorno = fread(&max[i], sizeof(usuarios), 1, arq);
    while (retorno == 1){
      printf("\nNome: %s",max[i].nome);
      printf("\nNome artístico: %s",max[i].nomeart);
      printf("\nIdade: %s",max[i].idade);
      printf("\nTelefone: %s",max[i].telefone);
      printf("\nRitmo musical: %s",max[i].ritmo);
      printf("\nProfissão: %s",max[i].tipo);
      printf("\nExperiência Profissional: %s",max[i].experiencia);
      printf("\nCidade: %s",max[i].cidade);
      printf("\nEstado: %s",max[i].estado);
      printf("\nE-mail: %s\n",max[i].email);
      i++;
      retorno = fread(&max[i], sizeof(usuarios), 1, arq);
    }
    printf(" \n\n %d Contatos salvos!\n ", i);
    getch();
    fclose(arq);
    system("cls || clear");
    menuEstabelecimento();
}

void menuCliente()
{
    int continuar = 0;

    printf("\n\tMenu do Cliente\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Alterar Cadastro\n");
    printf("2. Excluir Cadastro\n");
    printf("3. Listar Estabelecimentos\n");
    printf("4. Voltar ao Menu Principal\n");
    printf("5. Sair do Programa\n");

    scanf("%i", &continuar);
    system("cls || clear");

    switch(continuar)
    {
        case 1:
            alterarCliente();
            break;
        case 2:
            excluirCliente();
            break;
        case 3:
            listarEstabelecimento();
            break;
        case 4:
            montarMenuPrincipal();
        case 5:
            sair();
            break;
        default:
            printf("Digite uma opção válida!\n");
            menuCliente();
    }
}
