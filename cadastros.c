#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "cadastros.h"
#include <ctype.h>
#include <string.h>

// funções do menu cliente

void cadastraCliente (void) {

    
    char *nome;
    int data[3];
    int dia = data[0];
    int mes = data[1];
    int ano = data[2];
    char *email;
    char cpf[12];

    int tam;
    char linha[256];

    printf("\nDigite seu nome: ");
    scanf(" %255[^\n]", linha);
    tam = strlen(linha);
    nome = (char*) malloc(tam+1);
    strcpy(nome, linha);
    while((validaNome(nome))) {
        printf("Nome invalido, digite novamente: ");
        scanf(" %255[^\n]", nome);
    }

    printf("\nDigite sua data de nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&data[0], &data[1], &data[2]);
    getchar();
    dataValida(dia, mes, ano);
    while(!dataValida(data[0], data[1], data[2])){
    printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&data[0], &data[1], &data[2]);
    }
  
    printf("\nDigite seu email: ");
    scanf(" %255[^\n]", linha);
    tam = strlen(linha);
    email = (char*) malloc(tam+1);
    strcpy(email, linha);
    while(!(validaEmail(email))){
        printf("Email invalido, digite novamente: ");
        scanf(" %255[^\n]", email);
    }

    printf("\nDigite seu CPF: (xxxxxxxxxxx): ");
    scanf(" %12[^\n]", cpf);
    while(!(validaCpf(cpf))){
        printf("CPF invalido, digite novamente: ");
        scanf(" %12[^\n]", cpf);
    }
    free(email);
    free(nome);
    
    printf("\nUsuario cadastrado!\n");
    getchar();
    pausaPrograma();
    menuCliente();
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

    char valor[10];
    char descricao[1000];
    char categoria[100];
    int data[3];
    int dia = data[0];
    int mes = data[1];
    int ano = data[2];


    printf("\nDigite um valor: ");
    scanf("%s",valor);
    getchar();
    validaValor(valor);
    while ((validaValor(valor))) {
        printf("\nValor invalido. Digite um valor: ");
        scanf("%s",valor);
        getchar();
    }

    printf("\nDescricao: ");
    fgets(descricao, 1000, stdin);
    
    printf("\nCategoria: ");
    fgets(categoria, 100, stdin);

    printf("\nData (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&data[0], &data[1], &data[2]);
    getchar();
    dataValida(dia, mes, ano);
    while(!dataValida(data[0], data[1], data[2])){
        printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
        scanf("%d/%d/%d",&data[0], &data[1], &data[2]);
    }

    printf("\nDespesa cadastrada!\n");
    pausaPrograma();
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

    char valorR[10];
    char descricao[1000];
    char categoria[1000];
    int data[3];
    int dia = data[0];
    int mes = data[1];
    int ano = data[2];

    printf("\nDigite um valor: ");
    scanf("%s",valorR);
    getchar();
    validaValor(valorR);
    while ((validaValor(valorR))) {
        printf("\nValor invalido. Digite um valor: ");
        scanf("%s",valorR);
        getchar();
    }

    printf("\nDescricao: ");
    fgets(descricao, 1000, stdin);

    printf("\nCategoria: ");
    fgets(categoria, 100, stdin);

    printf("\nData (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&data[0], &data[1], &data[2]);
    getchar();
    dataValida(dia, mes, ano);
    while(!dataValida(data[0], data[1], data[2])){
    printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&data[0], &data[1], &data[2]);
    }

    printf("\nReceita cadastrada!\n");
    pausaPrograma();
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