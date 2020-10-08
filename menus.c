#include <stdio.h>
#include "menus.h"


char mainMenu (void) {

	char opcao;

    printf("\n\n");
    printf(" $ $ $   MENU PRINCIPAL  $ $ $   \n");
    printf(" $                           $   \n");
    printf(" $     1. MENU CLIENTES      $   \n");
    printf(" $     2. MENU DESPESAS      $   \n");
    printf(" $     3. MENU RECEITAS      $   \n");
    printf(" $     4. RELATORIOS         $   \n");
    printf(" $     5. SOBRE              $   \n");
    printf(" $     0. SAIR               $   \n");
    printf(" $                           $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $   \n");
    printf("\n\n");
    printf("\nEscolha sua opção: ");
    scanf("%c", &opcao);
    return opcao;

}

char menuCliente (void) {

	char opcao;
    getchar();
	printf("\n\n");
    printf(" $ $ $   MENU CLIENTE    $ $ $   \n");
    printf(" $                           $   \n");
    printf(" $     1. CADASTRAR CLIENTE  $   \n");
    printf(" $     2. LISTA DE CLIENTES  $   \n");
    printf(" $     3. BUSCAR CLIENTE     $   \n");
    printf(" $     4. ALTERAR CLIENTE    $   \n");
    printf(" $     5. DELETAR CLIENTE    $   \n");
    printf(" $     0. MENU PRINCIPAL     $   \n");
    printf(" $                           $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $   \n");
	printf("\n\n");
    printf("\nEscolha sua opção: ");
    scanf("%c", &opcao);
    return opcao;

    switch (opcao) {
        case '1':
            cadastraCliente();
            break;
        case '2':
            listaCliente();
            break;
        case '3':
            buscaCliente();
            break;
        case '4':
            alteraCliente();
            break;
        case '5':
            deletaCliente();
            break;
    } 
   


}

char menuDespesa (void) {

	char opcao;
	printf("\n\n");
    printf(" $ $ $   MENU DESPESA    $ $ $   \n");
    printf(" $                           $   \n");
    printf(" $     1. CADASTRAR DESPESA  $   \n");
    printf(" $     2. LISTA DE DESPESAS  $   \n");
    printf(" $     3. BUSCAR DESPESA     $   \n");
    printf(" $     4. ALTERAR DESPESA    $   \n");
    printf(" $     5. DELETAR DESPESA    $   \n");
    printf(" $     0. MENU PRINCIPAL     $   \n");
    printf(" $                           $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $   \n");
	printf("\n\n");
    printf("\nEscolha sua opção: ");
    scanf("%c", &opcao);
    return opcao;

}

char menuReceita (void) {

	char opcao;
	printf("\n\n");
    printf(" $ $ $   MENU RECEITAS   $ $ $   \n");
    printf(" $                           $   \n");
    printf(" $     1. CADASTRAR RECEITA  $   \n");
    printf(" $     2. LISTA DE RECEITAS  $   \n");
    printf(" $     3. BUSCAR RECEITA     $   \n");
    printf(" $     4. ALTERAR RECEITA    $   \n");
    printf(" $     5. DELETAR RECEITA    $   \n");
    printf(" $     0. MENU PRINCIPAL     $   \n");
    printf(" $                           $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $   \n");
	printf("\n\n");
    printf("\nEscolha sua opção: ");
    scanf("%c", &opcao);
    return opcao;

}

char menuRelatorio (void) {

    char opcao;
    printf("\n\n");
    printf(" $ $ $    MENU RECEITAS    $ $ $   \n");
    printf(" $                             $   \n");
    printf(" $     1. RELATORIO DO DIA     $   \n");
    printf(" $     2. RELATORIO SEMANAL    $   \n");
    printf(" $     3. RELATORIO MENSAL     $   \n");
    printf(" $     4. RELATORIO ANUAL      $   \n");
    printf(" $     5. RELATORIO COMPLETO   $   \n");
    printf(" $     0. MENU PRINCIPAL       $   \n");
    printf(" $                             $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $  \n");
	printf("\n\n");
    printf("\nEscolha sua opção: ");
    scanf("%c", &opcao);
    return opcao;

}

char menuSobre (void) {

    char opcao;
    printf("\n\n");
    printf(" $ $ $ $ $ $ $ $ $ $      MENU SOBRE       $ $ $ $ $ $ $ $ $ $   \n");
    printf(" $                                                           $   \n");
    printf(" $        Universidade Federal do Rio Grande do Norte        $   \n");
    printf(" $            Centro de Ensino Superior do Seridó            $   \n");
    printf(" $          Departamento de Computação e Tecnologia          $   \n");
    printf(" $              Disciplina DCT1106 - Programação             $   \n");
    printf(" $     Projeto Sistema de Controle de Financias Domésticas   $   \n");
    printf(" $           Desenvolvido por Gabriel Azevedo dos Santos     $   \n");
    printf(" $                gabrielazevedo492@gmail.com                $   \n");
    printf(" $             https://github.com/GabrielAzevedo3            $   \n");
    printf(" $                            2020                           $   \n");
    printf(" $                                                           $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $   \n");
	printf("\n\n");
    printf("\nEscolha sua opção: ");
    scanf("%c", &opcao);
    return opcao;
}
