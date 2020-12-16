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
    fp = fopen("clientes.dat", "ab");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }

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

    cli->status = '1';

    fwrite(cli, sizeof(Cliente), 1, fp);
    fclose(fp);
    free(cli);

    printf("\nUsuario cadastrado!\n");
    pausaPrograma();
    menuCliente();
}

void listaCliente (void) {

    system("clear||cls");
    FILE* fp;
    Cliente* cli;

    fp = fopen("clientes.dat", "rb");

    if (fp == NULL){
        printf("\nErro na abertura do arquivo\n!");
    }
    cli = (Cliente*) malloc(sizeof(Cliente));

    while (fread(cli, sizeof(Cliente), 1, fp)) {
        if (cli->status == '1') {

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
        }        
    }
    fclose(fp);
    free(cli);
    pausaPrograma();
    menuCliente();

}

void buscaCliente (void) {

    system("clear||cls");
    FILE* fp;
    Cliente* cli;
    int achou = 0;
    char procurado[80];

    fp = fopen("clientes.dat", "rb");
    if (fp == NULL){
        printf("\nErro na abertura do arquivo\n!");
    }

    printf("Digite o CPF do usuario que esta buscando: ");
    scanf(" %80[^\n]", procurado);
    cli = (Cliente*) malloc(sizeof(Cliente));
    while ((!achou) && (fread(cli, sizeof(Cliente), 1, fp))) {
        if (strcmp(cli->cpf, procurado) == 0 && (cli->status == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
      if(achou){
        exibeCliente(cli);
    } else{
        printf("\n%s nao esta cadastrado\n", procurado);
    }
    free(cli);

    getchar();
    pausaPrograma();
    menuCliente();
}

void alteraCliente (void) {
   
    system("clear||cls");
    FILE* fp;
    Cliente* cli;
    int achou = 0;
    char resp;
    char procurado[13];
    fp = fopen("clientes.dat", "r+b");
    if (fp == NULL){
        printf("\nErro na abertura do arquivo\n!");
    }

    printf("Digite o CPF do usuario que deseja alterar: ");
    scanf(" %12[^\n]", procurado);
    getchar();
    cli = (Cliente*) malloc(sizeof(Cliente));

    while ((!achou) && (fread(cli, sizeof(Cliente), 1, fp))) {
        if (strcmp(cli->cpf, procurado) == 0 && (cli->status == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeCliente(cli);
        printf("\nDeseja realmente alterar esse cliente? (s = sim n = nao) ");
        scanf(" %c",&resp);
        getchar();
        if(resp == 's' || resp == 'S'){

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

            cli->status = '1';
            fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
            fwrite(cli, sizeof(Cliente), 1, fp);
            printf("\ncliente alterado\n");
        }
        else {
            printf("\nOs dados nao foram alterados\n");
        }
    }
    else {

        printf("\nNenhum cliente com o CPF %s esta cadastrado\n", procurado);
    }
    
    fclose(fp);
    free(cli);

    //getchar();
    pausaPrograma();
    menuCliente();
}

void deletaCliente (void) {

    system("clear||cls");
    FILE* fp;
    Cliente* cli;
    int achou = 0;
    char resp;
    char procurado[13];
    fp = fopen("clientes.dat", "r+b");
    if (fp == NULL){
        printf("\nErro na abertura do arquivo\n!");
    }

    printf("Digite o CPF do usuario que deseja deletar: ");
    scanf(" %12[^\n]", procurado);
    cli = (Cliente*) malloc(sizeof(Cliente));

    while ((!achou) && (fread(cli, sizeof(Cliente), 1, fp))) {
        if (strcmp(cli->cpf, procurado) == 0 && (cli->status == '1')) {
            achou = 1;
        }
    }
    if(achou){

        exibeCliente(cli);
        printf("\nDeseja realmente deletar esse cliente? (s = sim n = nao) ");
        scanf(" %c",&resp);
        if(resp == 's' || resp == 'S'){

            cli->status = 'x';
            fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
            fwrite(cli, sizeof(Cliente), 1, fp);
            printf("\ncliente deletado\n");

        } else{

             printf("\nCliente nao deletado\n");

        }
    } 
    else{

        printf("\nNenhum cliente com o CPF %s esta cadastrado\n", procurado);
    }
    
    fclose(fp);
    free(cli);
    

    getchar();
    pausaPrograma();
    menuCliente();
}

void exibeCliente(Cliente* cli){

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

}


// funções do menu despesa

void cadastraDespesa (void) {

    Despesa* des;
    des = (Despesa*) malloc(sizeof(Despesa));

    FILE *fp;
    fp = fopen("despesas.dat", "ab");
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
    des->status = '1';

    fwrite(des, sizeof(Despesa), 1, fp);
    fclose(fp);
    free(des);

    

    printf("\nDespesa cadastrada!\n");
    pausaPrograma();
    menuDespesa();
}

void listaDespesa (void) {

    system("clear||cls");
    Despesa* des;
    des = (Despesa*) malloc(sizeof(Despesa));

    FILE *fp;
    fp = fopen("despesas.dat", "rb");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
    while (fread(des, sizeof(Despesa), 1, fp)) {
        if (des->status == '1') {

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
        }
    }
    fclose(fp);
    free(des);

    pausaPrograma();
    menuDespesa();
}

void buscaDespesa (void) {

    system("clear||cls");
    Despesa* des;
    des = (Despesa*) malloc(sizeof(Despesa));

    FILE *fp;
    fp = fopen("despesas.dat", "r+b");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }

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
    fwrite(res, sizeof(Receita), 1, fp);
    fclose(fp);
    free(res);



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
    fread(res, sizeof(Receita), 1, fp);
 
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