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

    fread(cli, sizeof(Cliente), 1, fp);
    fclose(fp);

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

    FILE *fp;
    fp = fopen("despesas.dat", "wb");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }

    printf("\nDigite um valor: ");
    scanf("%10[^\n]",des->valor);
    //getchar();
    //validaValor(des->valor);
    while ((validaValor(des->valor))) {
        printf("\nValor invalido. Digite um valor: ");
        scanf("%10[^\n]",des->valor);
        //getchar();
    }

    printf("\nDescricao: ");
    scanf(" %500[^\n]", des->descricao);
    //des->descricao = lelinha();
    
    printf("\nCategoria: ");
    scanf(" %15[^\n]", des->categoria);
    //des->categoria = lelinha();

    printf("\nData (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&des->dia, &des->mes, &des->ano);
    getchar();
    while(!dataValida(des->dia, des->mes, des->ano)){
        printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
        scanf("%d/%d/%d",&des->dia, &des->mes, &des->ano);
        getchar();
    }
    free(des);

    fwrite(des, sizeof(Despesa), 1, fp);
    fclose(fp);

    printf("\nDespesa cadastrada!\n");
    pausaPrograma();
    menuDespesa();
}

void listaDespesa (void) {

    Despesa* des;
    des = (Despesa*) malloc(sizeof(Despesa));

    FILE *fp;
    fp = fopen("despesas.dat", "rb");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
 
    system("clear||cls");
    printf("\n\n");
    printf(" $ $ $   LISTA DE DESPESAS   $ $ $   \n");
    printf(" $                               $   \n");
    printf(" $    Valor: %s\n", des->valor);
    printf(" $    Descricao: %s\n", des->descricao);
    printf(" $    Categoria: %s\n", des->categoria);
    printf(" $    Data de nascimento: %d/%d/%d\n", des->dia, des->mes, des->ano);
    printf(" $                               $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $  \n");
    printf("\n\n");

    free(des);

    fread(des, sizeof(Despesa), 1, fp);
    fclose(fp);

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

    FILE *fp;
    fp = fopen("receitas.dat", "wb");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
/*
    printf("\nDigite um valor: ");
    scanf("%10[^\n]",res->valorR);
    while ((validaValor(res->valorR))) {
        printf("\nValor invalido. Digite um valor: ");
        scanf("%10[^\n]",res->valorR);

    }

    printf("\nDescricao: ");
    scanf("% 500[^\n]", res->descricaoR);
    
    printf("\nCategoria: ");
    scanf("% 15[^\n]", res->categoriaR);      */

    printf("\nDigite um valor: ");
    scanf("%10[^\n]",res->valorR);
    while ((validaValor(res->valorR))) {
        printf("\nValor invalido. Digite um valor: ");
        scanf("%10[^\n]",res->valorR);
    }

    printf("\nDescricao: ");
    scanf(" %500[^\n]", res->descricaoR);
    
    printf("\nCategoria: ");
    scanf(" %15[^\n]", res->categoriaR);

    printf("\nData (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&res->dia, &res->mes, &res->ano);
    getchar();
    while(!dataValida(res->dia, res->mes, res->ano)){
        printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
        scanf("%d/%d/%d",&res->dia, &res->mes, &res->ano);
        getchar();
    }
    free(res);

    fwrite(res, sizeof(Receita), 1, fp);
    fclose(fp);

    printf("\nReceita cadastrada!\n");
    pausaPrograma();
    menuReceita();
}

void listaReceita (void) {

    Receita* res;
    res = (Receita*) malloc(sizeof(Receita));

    FILE *fp;
    fp = fopen("receitas.dat", "rb");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
 
    system("clear||cls");
    printf("\n\n");
    printf(" $ $ $   LISTA DE RECEITAS   $ $ $   \n");
    printf(" $                               $   \n");
    printf(" $    Valor: %s\n", res->valorR);
    printf(" $    Descricao: %s\n", res->descricaoR);
    printf(" $    Categoria: %s\n", res->categoriaR);
    printf(" $    Data de nascimento: %d/%d/%d\n", res->dia, res->mes, res->ano);
    printf(" $                               $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $  \n");
    printf("\n\n");

    free(res);

    fread(res, sizeof(Receita), 1, fp);
    fclose(fp);
    
    pausaPrograma();
    menuReceita();
}

void buscaReceita (void) {
    
    printf("\nVocê entrou no Busca Receita\n ");

    pausaPrograma();
    menuReceita();
}
void alteraReceita (void) {
    
    printf("\nVocê entrou no Altera Receita\n ");

    pausaPrograma();
    menuReceita();
}

void deletaReceita (void) {
    
    printf("\nVocê entrou no Deleta Receita\n ");

    pausaPrograma();
    menuReceita();
}

// funções do menu Relatorio

void relatorioDiario (void) {
    
    printf("\nVocê entrou no Relatorio Diario\n ");

    pausaPrograma();
    menuRelatorio();
}

void relatorioSemanal (void) {
    
    printf("\nVocê entrou no Relatorio Semanal\n ");

    pausaPrograma();
    menuRelatorio();
}

void relatorioMensal (void) {
    
    printf("\nVocê entrou no Relatorio Mensal\n ");

    pausaPrograma();
    menuRelatorio();
}

void relatorioAnual (void) {
    
    printf("\nVocê entrou no Relatorio Anual\n ");

    pausaPrograma();
    menuRelatorio();
}

void escolherPeriodo (void) {
    
    printf("\nVocê entrou no Escolher Periodo\n ");

    pausaPrograma();
    menuRelatorio();
}

// função do menu Sobre

void pausaPrograma(void) {

    printf("\nTecle ENTER para voltar");
    getchar();

}