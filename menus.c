#include <stdio.h>
#include "menus.h"


char mainMenu (void) {

	char opcao;

    printf("\n\n");
    printf(" $ $ $   MENU PRINCIPAL  $ $ $ \n\n");
    printf(" $                           $   \n");
    printf(" $     1. MENU CLIENTES      $   \n");
    printf(" $     2. MENU DESPESAS      $   \n");
    printf(" $     3. MENU RECEITAS      $   \n");
    printf(" $     4. RELATÓRIOS         $   \n");
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
	printf("\n\n");
    printf(" $ $ $   MENU CLIENTE    $ $ $ \n\n");
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
    scanf("%c", &opcao);
    return opcao;

}

char menuDespesa (void) {

	char opcao;
	printf("\n\n");
    printf(" $ $ $   MENU DESPESA    $ $ $ \n\n");
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
    scanf("%c", &opcao);
    return opcao;

}

char menuReceita (void) {

	char opcao;
	printf("\n\n");
    printf(" $ $ $   MENU RECEITAS   $ $ $ \n\n");
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
    scanf("%c", &opcao);
    return opcao;

}

char menuRelatorio (void) {

    char opcao;
    printf("\n\n");
    printf(" $ $ $   MENU RECEITAS    $ $ $ \n\n");
    printf(" $                            $   \n");
    printf(" $     1. RELATORIO DO DIA    $   \n");
    printf(" $     2. RELATORIO SEMANAL   $   \n");
    printf(" $     3. RELATORIO MENSAL    $   \n");
    printf(" $     4. RELATORIO ANUAL     $   \n");
    printf(" $     5. RELATORIO COMPLETO  $   \n");
    printf(" $     0. MENU PRINCIPAL      $   \n");
    printf(" $                            $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $   \n");
	printf("\n\n");
    scanf("%c", &opcao);
    return opcao;

}

char menuSobre (void) {

    char opcao;
	printf("\n");
	printf("///////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                         ///\n");
	printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
	printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
	printf("///               Departamento de Computação e Tecnologia                   ///\n");
	printf("///                   Disciplina DCT1106 - Programação                      ///\n");
	printf("///          Projeto Sistema de Controle de Financias Domésticas            ///\n");
	printf("///                Desenvolvido por Gabriel Azevedo dos Santos              ///\n");
	printf("///                        gabrielazevedo492@gmail.com                      ///\n");
	printf("///                             @gabriel_azevedo3                           ///\n");
	printf("///                                   2020                                  ///\n");
	printf("///                                                                         ///\n");
	printf("///////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                         ///\n");
	printf("///       = = = =  Sistema de Controle de Finanças Domésticas = = = =       ///\n");
	printf("///                                                                         ///\n");
	printf("///  O controle de finanças domésticas é uma das atividades necessárias em  ///\n");
  	printf("///  praticamente todas as residências, uma vez que para conseguir          ///\n");
	printf("///  equilibrar o orçamento doméstico e evitar o acúmulo de dívidas, se faz ///\n");
	printf("///  necessário monitorar entradas e saídas de recursos. Tal atividade pode ///\n");
	printf("///  demandar tempo e esforço, principalmente se for realizado sem a ajuda  ///\n");
	printf("///  de um software.                                                        ///\n");
	printf("///                                                                         ///\n");
	printf("///////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf(" 0. MENU PRINCIPAL\n");
    scanf("%c", &opcao);
    return opcao;

}
