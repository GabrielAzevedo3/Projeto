#include <stdio.h>
#include "menus.h"

// assinatura da função opcaoInvalida

char opcaoInvalida (void) {

    printf("\nOpcao Invalida, tecle ENTER para voltar");
    getchar();
}

// funções do menu cliente

char cadastraCliente (void) {
    char opcao2;
    printf("\nVocê entrou no Cadastra Cliente\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

char listaCliente (void) {
    char opcao2;
    printf("\nVocê entrou no Lista Cliente\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

char buscaCliente (void) {
    char opcao2;
    printf("\nVocê entrou no Busca Cliente\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}
char alteraCliente (void) {
    char opcao2;
    printf("\nVocê entrou no Altera Cliente\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

char deletaCliente (void) {
    char opcao2;
    printf("\nVocê entrou no Deleta Cliente\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

// funções do menu despesa

char cadastraDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Cadastra Despesa\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

char listaDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Lista Despesa\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

char buscaDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Busca Despesa\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}
char alteraDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Altera Despesa\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

char deletaDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Deleta Despesa\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

// funções do menu Receita

char cadastraReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Cadastra Receita\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

char listaReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Lista Receita\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

char buscaReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Busca Receita\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}
char alteraReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Altera Receita\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

char deletaReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Deleta Receita\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

// funções do menu Relatorio

char relatorioDiario (void) {
    char opcao2;
    printf("\nVocê entrou no Relatorio Diario\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

char relatorioSemanal (void) {
    char opcao2;
    printf("\nVocê entrou no Relatorio Semanal\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

char relatorioMensal (void) {
    char opcao2;
    printf("\nVocê entrou no Relatorio Mensal\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

char relatorioAnual (void) {
    char opcao2;
    printf("\nVocê entrou no Relatorio Anual\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

char escolherPeriodo (void) {
    char opcao2;
    printf("\nVocê entrou no Escolher Periodo\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    return opcao2;
}

// função do menu Sobre

void pausaPrograma(void) {

    printf("\nTecle ENTER para voltar");
    getchar();

}