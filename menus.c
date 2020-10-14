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
    printf("Escolha sua opcao: ");
    scanf("%c", &opcao);
    getchar();
    return opcao;

}

char menuCliente (void) {

	char opcao;
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
    printf("\nEscolha sua opcao: ");
    scanf("%c", &opcao);
    getchar();

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
    return opcao;

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
    printf("\nEscolha sua opcao: ");
    scanf("%c", &opcao);
    getchar();

    switch (opcao) {
        case '1':
            cadastraDespesa();
            break;
        case'2': 
            listaDespesa();
            break;
        case '3':
            buscaDespesa();
            break;
        case '4':
            alteraDespesa();
            break;
        case '5':
            deletaDespesa();
            break;
    }

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
    printf("\nEscolha sua opcao: ");
    scanf("%c", &opcao);
    getchar();
    switch (opcao) {

        case '1':
            cadastraReceita();
            break;
        case '2':
            listaReceita();
            break;
        case '3':
            buscaReceita();
            break;
        case '4':
            alteraReceita();
            break;
        case '5':
            deletaReceita();
            break;
    }
    return opcao;

}

char menuRelatorio (void) {

    char opcao;
    printf("\n\n");
    printf(" $ $ $   MENU RELATORIOS   $ $ $   \n");
    printf(" $                             $   \n");
    printf(" $     1. RELATORIO DIARIO     $   \n");
    printf(" $     2. RELATORIO SEMANAL    $   \n");
    printf(" $     3. RELATORIO MENSAL     $   \n");
    printf(" $     4. RELATORIO ANUAL      $   \n");
    printf(" $     5. ESCOLHER PERIODO     $   \n");
    printf(" $     0. MENU PRINCIPAL       $   \n");
    printf(" $                             $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $   \n");
	printf("\n\n");
    printf("\nEscolha sua opcao: ");
    scanf("%c", &opcao);
    getchar();
    switch (opcao) {
        case '1':
            relatorioDiario();
            break;
        case '2':
            relatorioSemanal();
            break;
        case '3':
            relatorioMensal();
            break;
        case '4':
            relatorioAnual();
            break;
        case '5':
            escolherPeriodo();
            break;
    }
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
    printf(" $                                                           $   \n");
    printf(" $      O controle de finanças domésticas é uma das          $   \n");
    printf(" $  atividades necessárias em praticamente todas as          $   \n");
    printf(" $  residências, uma vez que para conseguir equilibrar       $   \n");
    printf(" $  o orçamento doméstico e evitaro acúmulo de dívidas,      $   \n");
    printf(" $  se faz necessário monitorar entradas e saídas de         $   \n");
    printf(" $  recursos. Tal atividade pode demandar tempo e esforço,   $   \n");
    printf(" $  principalmente se for realizado sem  a ajuda de um       $   \n");
    printf(" $  software                                                 $   \n");
    printf(" $                                                           $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $   \n");
    printf("\n");
}
