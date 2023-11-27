#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <conio.h>
#include "clientes.c"
#include "estabelecimentos.c"
#include "funcionarios.c"
#include "relatorios.c"
#include "administrador.c"
#include "menuPrincipal.c"

int main()
{
    int var;
    system("title PIM - UNIMUSIC");
    system("color F0");
    setlocale(LC_ALL, "Portuguese");
    printf("\n\n\t\tUNIMUSIC - PLATAFORMA DO RAMO MUSICAL\n\n");
    printf("\tVeja todas as funções disponiveis no menu.\n");
    printf("\tUse os numeros para selecionar a opção desejada.\n");
    printf("\tPressione qualquer tecla para continuar ou espaço para sair do programa agora.\n");
    printf("\n\n");
    printf("\t\t          P  /_\\  P                              \n");
    printf("\t\t         /_\\_|_|_/_\\                            \n");
    printf("\t\t     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("\t\t     |_|_|nnnn nnnn|_|_|        nosso programa!   \n");
    printf("\t\t    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("\t\t    |_____| ' _ ' |_____|                         \n");
    printf("\t\t          \\__|_|__/                              \n");
    printf("\n\n");
    var=getch();
    if(var == 32){ exit(0);}
    system("cls || clear");
    montarMenuPrincipal();
    system("pause");
}
