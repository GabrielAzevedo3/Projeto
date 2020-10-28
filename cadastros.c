#include <stdio.h>
#include "menus.h"

// funções do menu cliente

char cadastraCliente (void) {

    int dataNasc, cpf;
    char opcao2;
    char nome[50];
    char email[50];
    printf("\nDigite seu nome: ");
    gets(nome); // função que pega tudo o que foi digitado
    //scanf("%[A-Za-z]", nome); 
    //validaNome(nome);
    printf("\nDigite seu email: ");
    scanf("%s", email);
    printf("\nDigite sua data nascimento (dd/mm/aaaa): ");
    scanf("%d", &dataNasc);
    printf("\nDigite seu CPF: ");
    scanf("%d", &cpf);
    printf("\nUsuario cadastrado!\n");
    opcao2 = getchar();
    return opcao2;
}

// função para validar nome
/*
void validaNome (int nome) {
    // esboço imcompleto 

    for (int i; i < nome; i++) {
        if (nome >= 'A' && nome <= 'Z') {
            return 1;  
        } else if (nome >= 'a' && nome <= 'z') {
            return 1;  
        } else {
            return 0;  
        }
    }
}   
*/
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