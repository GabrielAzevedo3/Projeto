#include <stdio.h>
#include "menus.h"
#include "cadastros.h"
#include <ctype.h>
#include <string.h>

// funções do menu cliente

void cadastraCliente (void) {

    int dataNasc, cpf;
    char opcao2;
    char nome[100];
    char email[50];
    char *pnome = nome;
    printf("\nDigite seu nome: ");
    gets(pnome); // função que pega tudo o que foi digitado
    validaNome(pnome);

    printf("\nDigite seu email: ");
    scanf("%s", email);
    printf("\nDigite sua data nascimento (dd/mm/aaaa): ");
    scanf("%d", &dataNasc);
    printf("\nDigite seu CPF: ");
    scanf("%d", &cpf);
    printf("\nUsuario cadastrado!\n");
    pausaPrograma();
    opcao2 = getchar();
    menuCliente();
}

void validaNome(char *pnome) {
    int tam = strlen(pnome);
    char letra;
    for (int i = 0; i < tam; i++)
    {
        letra = pnome[i];
        if (isdigit(letra)) {
            printf("Nome inválido");
            return;
        }
        if (isspace(letra)) {
        }
        if (isalpha(letra)) {
        }
    }
    //printf("Nome Válido");
}


void listaCliente (void) {
    char opcao2;
    printf("\nVocê entrou no Lista Cliente\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuCliente();

}

void buscaCliente (void) {
    char opcao2;
    printf("\nVocê entrou no Busca Cliente\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuCliente();
}
void alteraCliente (void) {
    char opcao2;
    printf("\nVocê entrou no Altera Cliente\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuCliente();
}

void deletaCliente (void) {
    char opcao2;
    printf("\nVocê entrou no Deleta Cliente\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuCliente();
}

// funções do menu despesa

void cadastraDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Cadastra Despesa\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuDespesa();
}

void listaDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Lista Despesa\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuDespesa();
}

void buscaDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Busca Despesa\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuDespesa();
}
void alteraDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Altera Despesa\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuDespesa();
}

void deletaDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Deleta Despesa\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuDespesa();
}

// funções do menu Receita

void cadastraReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Cadastra Receita\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuReceita();
}

void listaReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Lista Receita\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuReceita();
}

void buscaReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Busca Receita\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuReceita();
}
void alteraReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Altera Receita\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuReceita();
}

void deletaReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Deleta Receita\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuReceita();
}

// funções do menu Relatorio

void relatorioDiario (void) {
    char opcao2;
    printf("\nVocê entrou no Relatorio Diario\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuRelatorio();
}

void relatorioSemanal (void) {
    char opcao2;
    printf("\nVocê entrou no Relatorio Semanal\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuRelatorio();
}

void relatorioMensal (void) {
    char opcao2;
    printf("\nVocê entrou no Relatorio Mensal\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuRelatorio();
}

void relatorioAnual (void) {
    char opcao2;
    printf("\nVocê entrou no Relatorio Anual\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuRelatorio();
}

void escolherPeriodo (void) {
    char opcao2;
    printf("\nVocê entrou no Escolher Periodo\n ");
    printf("\nTecle ENTER para voltar");
    opcao2 = getchar();
    menuRelatorio();
}

// função do menu Sobre

void pausaPrograma(void) {

    printf("\nTecle ENTER para voltar");
    getchar();

}