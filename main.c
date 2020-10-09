#include <stdio.h>
#include "menus.h"

int main (void) {

    char opcao;
    opcao = mainMenu();
    while (opcao != '0') {

        switch (opcao) {

            case '1': 
                menuCliente();
                break;
            case '2':
                menuDespesa();
                break;
            case'3':
                menuReceita();
                break;
            case '4':
                menuRelatorio();
                break;
            case '5':
                menuSobre();
                break;
            default:
                printf("\nOpção inválida\n");
                break;
                
        } 
        opcao = mainMenu();
            
    }
    return 0;

}