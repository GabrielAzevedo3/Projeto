#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "cadastros.h"
#include <ctype.h>
#include <string.h>

// funções do menu cliente

void cadastraCliente (void) {

    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));

    FILE *fp;
    fp = fopen("clientes.dat", "wb");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }


/*
    printf("\nDigite seu nome: ");
    cli->nome = lelinha();
    while (validaNome(cli->nome)) {
	    printf("Nome invalido, digite novamente: ");    
		cli->nome = lelinha();
	} 
*/  
    
    printf("\nDigite seu nome: ");
    scanf(" %80[^\n]", cli->nome);
    while((validaNome(cli->nome))) {
        printf("Nome invalido, digite novamente: ");
        scanf(" %80[^\n]", cli->nome); 
    }

    printf("\nDigite sua data de nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&cli->dia, &cli->mes, &cli->ano);
    getchar();
    while(!dataValida(cli->dia, cli->mes, cli->ano)){
    printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
        scanf("%d/%d/%d",&cli->dia, &cli->mes, &cli->ano);
        getchar();
    }
/*
    printf("\nDigite seu e-mail: ");
    cli->email = lelinha();
    while(!(validaEmail(cli->email))){
	    printf("E-mail invalido, digite novamente: ");    
		cli->email = lelinha();
	}
*/
    printf("\nDigite seu e-mail: ");
    scanf(" %50[^\n]", cli->email);
    while(!(validaEmail(cli->email))){
	    printf("E-mail invalido, digite novamente: ");    
		scanf(" %50[^\n]", cli->email);
	}

    printf("\nDigite seu CPF: (apenas numeros): ");
    scanf(" %12[^\n]", cli->cpf);
    getchar();
    while(!(validaCpf(cli->cpf))){
        printf("CPF invalido, digite novamente: ");
        scanf(" %12[^\n]", cli->cpf);
        getchar();
    }
    free(cli);

    fwrite(cli, sizeof(Cliente), 1, fp);
    fclose(fp);
    
    printf("\nUsuario cadastrado!\n");
    pausaPrograma();
    menuCliente();
}

void listaCliente (void) {
    
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));

    FILE* fp;
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL){
        printf("\nErro na abertura do arquivo\n!");
    }
    fread(cli, sizeof(Cliente), 1, fp);
    fclose(fp);

    system("clear||cls");
    printf("\n\n");
    printf(" $ $ $   LISTA DE CLIENTES   $ $ $   \n");
    printf(" $                               $   \n");
    printf(" $    Nome: %s\n", cli->nome);
    printf(" $    Data de nascimento: %d/%d/%d\n", cli->dia, cli->mes, cli->ano);
    printf(" $    E-mail: %s\n", cli->email);
    printf(" $    CPF: %s\n", cli->cpf);
    printf(" $                               $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $  \n");
    printf("\n\n");


    pausaPrograma();
    menuCliente();

}

void buscaCliente (void) {

    printf("\nVocê entrou no Busca Cliente\n ");
    pausaPrograma();
    menuCliente();
}
void alteraCliente (void) {
   
    printf("\nVocê entrou no Altera Cliente\n ");
    pausaPrograma();
    menuCliente();
}

void deletaCliente (void) {

    printf("\nVocê entrou no Deleta Cliente\n ");
    pausaPrograma();
    menuCliente();
}

// funções do menu despesa

void cadastraDespesa (void) {

    Despesa* des;
    des = (Despesa*) malloc(sizeof(Despesa));

    printf("\nDigite um valor: ");
    scanf("%s",des->valor);
    getchar();
    validaValor(des->valor);
    while ((validaValor(des->valor))) {
        printf("\nValor invalido. Digite um valor: ");
        scanf("%s",des->valor);
        getchar();
    }

    printf("\nDescricao: ");
    des->descricao = lelinha();
    
    printf("\nCategoria: ");
    des->categoria = lelinha();

    printf("\nData (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&des->dia, &des->mes, &des->ano);
    getchar();
    while(!dataValida(des->dia, des->mes, des->ano)){
        printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
        scanf("%d/%d/%d",&des->dia, &des->mes, &des->ano);
        getchar();
    }
    free(des);

    printf("\nDespesa cadastrada!\n");
    pausaPrograma();
    menuDespesa();
}

void listaDespesa (void) {
 
    printf("\nVocê entrou no Lista Despesa\n ");
    pausaPrograma();
    menuDespesa();
}

void buscaDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Busca Despesa\n ");
    pausaPrograma();
    menuDespesa();
}
void alteraDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Altera Despesa\n ");

    pausaPrograma();
    menuDespesa();
}

void deletaDespesa (void) {
    char opcao2;
    printf("\nVocê entrou no Deleta Despesa\n ");

    pausaPrograma();
    menuDespesa();
}

// funções do menu Receita

void cadastraReceita (void) {

    Receita* res;
    res = (Receita*) malloc(sizeof(Receita));

    printf("\nDigite um valor: ");
    scanf("%s",res->valorR);
    getchar();
    validaValor(res->valorR);
    while ((validaValor(res->valorR))) {
        printf("\nValor invalido. Digite um valor: ");
        scanf("%s",res->valorR);
        getchar();
    }

    printf("\nDescricao: ");
    res->descricao = lelinha();

    printf("\nCategoria: ");
    res->categoria = lelinha();

    printf("\nData (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&res->dia, &res->mes, &res->ano);
    getchar();
    while(!dataValida(res->dia, res->mes, res->ano)){
        printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
        scanf("%d/%d/%d",&res->dia, &res->mes, &res->ano);
        getchar();
    }
    free(res);

    printf("\nReceita cadastrada!\n");
    pausaPrograma();
    menuReceita();
}

void listaReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Lista Receita\n ");
    pausaPrograma();
    menuReceita();
}

void buscaReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Busca Receita\n ");

    pausaPrograma();
    menuReceita();
}
void alteraReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Altera Receita\n ");

    pausaPrograma();
    menuReceita();
}

void deletaReceita (void) {
    char opcao2;
    printf("\nVocê entrou no Deleta Receita\n ");

    pausaPrograma();
    menuReceita();
}

// funções do menu Relatorio

void relatorioDiario (void) {
    char opcao2;
    printf("\nVocê entrou no Relatorio Diario\n ");

    pausaPrograma();
    menuRelatorio();
}

void relatorioSemanal (void) {
    char opcao2;
    printf("\nVocê entrou no Relatorio Semanal\n ");

    pausaPrograma();
    menuRelatorio();
}

void relatorioMensal (void) {
    char opcao2;
    printf("\nVocê entrou no Relatorio Mensal\n ");

    pausaPrograma();
    menuRelatorio();
}

void relatorioAnual (void) {
    char opcao2;
    printf("\nVocê entrou no Relatorio Anual\n ");

    pausaPrograma();
    menuRelatorio();
}

void escolherPeriodo (void) {
    char opcao2;
    printf("\nVocê entrou no Escolher Periodo\n ");

    pausaPrograma();
    menuRelatorio();
}

// função do menu Sobre

void pausaPrograma(void) {

    printf("\nTecle ENTER para voltar");
    getchar();

}