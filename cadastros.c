#include <stdio.h>
#include "menus.h"

// funções do menu cliente

char cadastraCliente (void) {
    char opcao2;
    printf("\nVocê entrou no Cadastra Cliente ");
    printf("\nTecle ENTER para continuar... ");
    opcao2 = getchar();
    return opcao2;
}

char listaCliente (void) {
    char opcao2;
    printf("\nVocê entrou no Lista Cliente ");
    printf("\nTecle ENTER para continuar... ");
    opcao2 = getchar();
    return opcao2;
}

char buscaCliente (void) {
    char opcao2;
    printf("\nVocê entrou no Busca Cliente ");
    printf("\nTecle ENTER para continuar... ");
    opcao2 = getchar();
    return opcao2;
}
char alteraCliente (void) {
    char opcao2;
    printf("\nVocê entrou no Altera Cliente ");
    printf("\nTecle ENTER para continuar... ");
    opcao2 = getchar();
    return opcao2;
}

char deletaCliente (void) {
    char opcao2;
    printf("\nVocê entrou no Deleta Cliente ");
    printf("\nTecle ENTER para continuar... ");
    opcao2 = getchar();
    return opcao2;
}

// funções do menu despesa

char cadastraDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Cadastra Despesa ");
    printf("\nTecle ENTER para continuar... ");
    opcao2 = getchar();
    return opcao2;
}

char listaDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Lista Despesa ");
    printf("\nTecle ENTER para continuar... ");
    opcao2 = getchar();
    return opcao2;
}

char buscaDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Busca Despesa ");
    printf("\nTecle ENTER para continuar... ");
    opcao2 = getchar();
    return opcao2;
}
char alteraDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Altera Despesa ");
    printf("\nTecle ENTER para continuar... ");
    opcao2 = getchar();
    return opcao2;
}

char deletaDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Deleta Despesa ");
    printf("\nTecle ENTER para continuar... ");
    opcao2 = getchar();
    return opcao2;
}

// funções do menu Receita

char cadastraReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Cadastra Receita ");
    printf("\nTecle ENTER para continuar... ");
    opcao2 = getchar();
    return opcao2;
}

char listaReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Lista Receita ");
    printf("\nTecle ENTER para continuar... ");
    opcao2 = getchar();
    return opcao2;
}

char buscaReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Busca Receita ");
    printf("\nTecle ENTER para continuar... ");
    opcao2 = getchar();
    return opcao2;
}
char alteraReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Altera Receita ");
    printf("\nTecle ENTER para continuar... ");
    opcao2 = getchar();
    return opcao2;
}

char deletaReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Deleta Receita ");
    printf("\nTecle ENTER para continuar... ");
    opcao2 = getchar();
    return opcao2;
}

// função do menu Sobre

void pausaPrograma(void) {

    printf("\nTecle ENTER para voltar ao menu principal");
    getchar();
    getchar();
}