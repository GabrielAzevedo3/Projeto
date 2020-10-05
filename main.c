#include <stdio.h>

int main (void) {

    char opcao;
    while (opcao != 0) {
        printf("\n\n");
        printf(" $ $ $   Menu de Opções   $ $ $ \n\n");
        printf(" $     1. MENU CLIENTES   $       \n");
        printf(" $     2. MENU DESPESAS   $       \n");
        printf(" $     3. RELATÓRIOS      $       \n");
        printf(" $     4. SOBRE           $       \n");
        printf(" $     0. SAIR            $       \n");
        printf("\nEscolha sua opção: ");
        scanf("%c", &opcao);
    }

    menuSobre();
    return 0;

}

