#include <stdio.h>
#include <stdlib.h>
#include "assinaturas.h"
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

    printf("\nDigite seu CPF (apenas numeros): ");
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
    FILE *fp;
    fp = fopen("despesas.dat", "ab");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
    des = (Despesa*) malloc(sizeof(Despesa));

    printf("\nDigite um valor (apenas numeros): R$ ");
    scanf(" %10[^\n]",des->valor);
    while ((validaValor(des->valor))) {
        printf("\nValor invalido. Digite um valor: ");
        scanf(" %10[^\n]",des->valor);
    }

    printf("\nDescricao: ");
    scanf(" %500[^\n]", des->descricao);
    
    printf("\nCategoria (Ex: alimentacao, compras, etc.): ");
    scanf(" %20[^\n]", des->categoria);
    
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
            printf(" $    Valor: R$ %s\n", des->valor);
            printf(" $    Descricao: %s\n", des->descricao);
            printf(" $    Categoria: %s\n", des->categoria);
            printf(" $    Data: %d/%d/%d\n", des->dia, des->mes, des->ano);          
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
    FILE *fp;
    int achou = 0;
    char procurado[80];
    fp = fopen("despesas.dat", "r+b");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n");

    }
    printf("\nInforme a descricao da despesa que esta buscando: ");
    scanf(" %400[^\n]", procurado);
    des = (Despesa*) malloc(sizeof(Despesa));
    while ((!achou) && (fread(des, sizeof(Despesa), 1, fp))) {
        if (strcmp(des->descricao, procurado) == 0 && (des->status == '1')) {
            achou = 1;
        }
        
    }
    if(achou){    
        exibeDespesa(des);
    }else{
            printf("\nNao tem despesas cadastradas com essa descricao\n");
    }
     

    fclose(fp);
    free(des);

    getchar();
    pausaPrograma();
    menuDespesa();
}
void alteraDespesa (void) {

    system("clear||cls");
    Despesa* des;
    FILE *fp;
    int achou = 0;
    char resp;
    char procurado[80];
    fp = fopen("despesas.dat", "r+b");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n");

    }
    printf("\nInforme a descricao da despesa que esta buscando: ");
    scanf(" %400[^\n]", procurado);
    des = (Despesa*) malloc(sizeof(Despesa));
    while ((!achou) && (fread(des, sizeof(Despesa), 1, fp))) {
        if (strcmp(des->descricao, procurado) == 0 && (des->status == '1')) {
            achou = 1;
        }
        
    }
    if (achou) {
        exibeDespesa(des);
        printf("\nDeseja realmente alterar esse cliente? (s = sim n = nao) ");
        scanf(" %c",&resp);
        getchar();
        if(resp == 's' || resp == 'S'){

            printf("\nDigite um valor (apenas numeros): R$ ");
            scanf("% 10[^\n]",des->valor);
            while ((validaValor(des->valor))) {
                printf("\nValor invalido. Digite um valor: ");
                scanf(" %10[^\n]",des->valor);
            }

            printf("\nDescricao: ");
            scanf(" %500[^\n]", des->descricao);
            
            printf("\nCategoria (Ex: alimentacao, compras, etc.): ");
            scanf(" %20[^\n]", des->categoria);
            
            printf("\nData (dd/mm/aaaa): ");
            scanf("%d/%d/%d",&des->dia, &des->mes, &des->ano);
            getchar();
            while(!dataValida(des->dia, des->mes, des->ano)){
                printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
                scanf("%d/%d/%d",&des->dia, &des->mes, &des->ano);
                getchar();
            }
            
            des->status = '1';
            fseek(fp, -1*sizeof(Despesa), SEEK_CUR);
            fwrite(des, sizeof(Despesa), 1, fp);
            printf("\nDespesa alterada\n");
        }
        else {
            printf("\nOs dados nao foram alterados\n");
        }
    }
    else {

        printf("\nNenhum cliente com o CPF %s esta cadastrado\n", procurado);
    }
    
    fclose(fp);
    free(des);

    pausaPrograma();
    menuDespesa();
}

void deletaDespesa (void) {

    system("clear||cls");
    FILE* fp;
    Despesa* des;
    int achou = 0;
    char resp;
    char procurado[13];
    fp = fopen("despesas.dat", "r+b");
    if (fp == NULL){
        printf("\nErro na abertura do arquivo\n!");
    }

    printf("\nInforme a descricao da despesa que deseja deletar: ");
    scanf(" %400[^\n]", procurado);
    des = (Despesa*) malloc(sizeof(Despesa));

    while ((!achou) && (fread(des, sizeof(Despesa), 1, fp))) {
        if (strcmp(des->descricao, procurado) == 0 && (des->status == '1')) {
            achou = 1;
        }
    }
    if(achou){

        exibeDespesa(des);
        printf("\nDeseja realmente deletar essa despesa? (s = sim n = nao) ");
        scanf(" %c",&resp);
        if(resp == 's' || resp == 'S'){

            des->status = 'x';
            fseek(fp, -1*sizeof(Despesa), SEEK_CUR);
            fwrite(des, sizeof(Despesa), 1, fp);
            printf("\nDespesa deletada\n");

        } else{

            printf("\nDespesa nao deletada\n");

        }
    } 
    else{

        printf("\nNenhuma despesa com a descricao %s esta cadastrado\n", procurado);
    }
    
    fclose(fp);
    free(des);

    getchar();
    pausaPrograma();
    menuDespesa();
}

void exibeDespesa(Despesa* des){
  
    printf("\n\n");
    printf(" $ $ $   LISTA DE DESPESAS   $ $ $   \n");
    printf(" $                               $   \n");
    printf(" $    Valor: R$ %s\n", des->valor);
    printf(" $    Descricao: %s\n", des->descricao);
    printf(" $    Categoria: %s\n", des->categoria);
    printf(" $    Data de nascimento: %d/%d/%d\n", des->dia, des->mes, des->ano);
    printf(" $                               $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $  \n");
    printf("\n\n");
}

// funções do menu Receita

void cadastraReceita (void) {

    Receita* res;
    FILE *fp;
    fp = fopen("receitas.dat", "ab");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
    res = (Receita*) malloc(sizeof(Receita));

    printf("\nDigite um valor (apenas numeros): R$ ");
    scanf(" %10[^\n]",res->valorR);
    while ((validaValor(res->valorR))) {
        printf("\nValor invalido. Digite um valor: ");
        scanf(" %10[^\n]",res->valorR);
    }

    printf("\nDescricao: ");
    scanf(" %500[^\n]", res->descricaoR);
    
    printf("\nCategoria (Ex: emprestimos, salario, etc): ");
    scanf(" %15[^\n]", res->categoriaR);

    printf("\nData (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&res->dia, &res->mes, &res->ano);
    getchar();
    while(!dataValida(res->dia, res->mes, res->ano)){
        printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
        scanf("%d/%d/%d",&res->dia, &res->mes, &res->ano);
        getchar();
    }
    res->status = '1';

    fwrite(res, sizeof(Receita), 1, fp);
    fclose(fp);
    free(res);

    printf("\nReceita cadastrada!\n");
    pausaPrograma();
    menuReceita();
}
void listaReceita (void) {

    system("clear||cls");
    Receita* res;
    res = (Receita*) malloc(sizeof(Receita));
    FILE *fp;
    fp = fopen("receitas.dat", "rb");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
    while (fread(res, sizeof(Receita), 1, fp)) {
        if (res->status == '1') {
 
            printf("\n\n");
            printf(" $ $ $   LISTA DE RECEITAS   $ $ $   \n");
            printf(" $                               $   \n");
            printf(" $    Valor: R$ %s\n", res->valorR);
            printf(" $    Descricao: %s\n", res->descricaoR);
            printf(" $    Categoria: %s\n", res->categoriaR);
            printf(" $    Data de nascimento: %d/%d/%d\n", res->dia, res->mes, res->ano);
            printf(" $                               $   \n");
            printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $  \n");
            printf("\n\n");
        }
    }
    fclose(fp);
    free(res);

    pausaPrograma();
    menuReceita();
}

void buscaReceita (void) {
    
    system("clear||cls");
    Receita* res;
    int achou = 0;
    char procurado[80];
    FILE *fp;
    fp = fopen("receitas.dat", "r+b");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
    res = (Receita*) malloc(sizeof(Receita));

    printf("\nInforme a descricao da receita que esta buscando: ");
    scanf(" %400[^\n]", procurado);
    while ((!achou) && (fread(res, sizeof(Receita), 1, fp))) {
        if (strcmp(res->descricaoR, procurado) == 0 && (res->status == '1')) {
            achou = 1;
        }
        
    }
    if(achou){    
        exibeReceita(res);
    }else{
            printf("\nNao tem receitas cadastradas com essa descricao\n");
    }
    fclose(fp);
    free(res);

    getchar();
    pausaPrograma();
    menuReceita();
}
void alteraReceita (void) {
    
    system("clear||cls");
    Receita* res;
    int achou = 0;
    char procurado[80];
    char resp;
    FILE *fp;
    fp = fopen("receitas.dat", "r+b");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
    res = (Receita*) malloc(sizeof(Receita));

    printf("\nInforme a descricao da receita que deseja alterar: ");
    scanf(" %400[^\n]", procurado);
    while ((!achou) && (fread(res, sizeof(Receita), 1, fp))) {
        if (strcmp(res->descricaoR, procurado) == 0 && (res->status == '1')) {
            achou = 1;
        }
        
    }
    if (achou) {
        exibeReceita(res);
        printf("\nDeseja realmente alterar esse cliente? (s = sim n = nao) ");
        scanf(" %c",&resp);
        getchar();
        if(resp == 's' || resp == 'S'){

            printf("\nDigite um valor (apenas numeros): R$ ");
            scanf(" %10[^\n]",res->valorR);
            while ((validaValor(res->valorR))) {
                printf("\nValor invalido. Digite um valor: ");
                scanf(" %10[^\n]",res->valorR);
            }

            printf("\nDescricao: ");
            scanf(" %500[^\n]", res->descricaoR);
            
            printf("\nCategoria (Ex: emprestimos, salario, etc): ");
            scanf(" %15[^\n]", res->categoriaR);

            printf("\nData (dd/mm/aaaa): ");
            scanf("%d/%d/%d",&res->dia, &res->mes, &res->ano);
            getchar();
            while(!dataValida(res->dia, res->mes, res->ano)){
                printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
                scanf("%d/%d/%d",&res->dia, &res->mes, &res->ano);
                getchar();
            }
            res->status = '1';
            fseek(fp, -1*sizeof(Receita), SEEK_CUR);
            fwrite(res, sizeof(Receita), 1, fp);
            printf("\nReceita alterada\n");
        }
        else {
            printf("\nOs dados nao foram alterados\n");
        }
    }
    else {

        printf("\nNenhuma receita encontrada com essa descricao\n", procurado);
    }
    
    fclose(fp);
    free(res);

    pausaPrograma();
    menuReceita();
}

void deletaReceita (void) {

    system("clear||cls");
    Receita* res;
    int achou = 0;
    char procurado[80];
    char resp;
    FILE *fp;
    fp = fopen("receitas.dat", "r+b");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
    res = (Receita*) malloc(sizeof(Receita));

    printf("\nInforme a descricao da receita que deseja deletar: ");
    scanf(" %400[^\n]", procurado);
    while ((!achou) && (fread(res, sizeof(Receita), 1, fp))) {
        if (strcmp(res->descricaoR, procurado) == 0 && (res->status == '1')) {
            achou = 1;
        }
        
    }
    if (achou) {
        exibeReceita(res);
        printf("\nDeseja realmente deletar esse cliente? (s = sim n = nao) ");
        scanf(" %c",&resp);
        getchar();
        if(resp == 's' || resp == 'S'){

            res->status = 'x';
            fseek(fp, -1*sizeof(Receita), SEEK_CUR);
            fwrite(res, sizeof(Receita), 1, fp);
            printf("\nReceita deletada\n");

        }
        else {
            printf("\nOs dados nao foram deletados\n");
        }
    }
    else {

        printf("\nNenhuma receita encontrada com essa descricao\\n", procurado);
    }
    
    fclose(fp);
    free(res);    
    
    getchar();
    pausaPrograma();
    menuReceita();
}

void exibeReceita(Receita* res){
  
    printf("\n\n");
    printf(" $ $ $   LISTA DE DESPESAS   $ $ $   \n");
    printf(" $                               $   \n");
    printf(" $    Valor: R$ %s\n", res->valorR);
    printf(" $    Descricao: %s\n", res->descricaoR);
    printf(" $    Categoria: %s\n", res->categoriaR);
    printf(" $    Data de nascimento: %d/%d/%d\n", res->dia, res->mes, res->ano);
    printf(" $                               $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $  \n");
    printf("\n\n");
}


// funções do menu Relatorio

NoDes* relatorioDespesaDireto (void) {
    
    FILE* fp;
    Despesa* des;
    NoDes* noDes;
    NoDes* lista;
    NoDes* ultimo;

    lista = NULL;

    fp = fopen("despesas.dat", "rb");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
    des = (Despesa*) malloc(sizeof(Despesa));
    while (fread(des, sizeof(Despesa), 1, fp)) {
        if (des->status == '1') {

        noDes = (NoDes*) malloc(sizeof(NoDes));
        strcpy(noDes->valor, des->valor);
        strcpy(noDes->descricao, des->descricao);
        strcpy(noDes->categoria, des->categoria);
        noDes->dia = des->dia;
        noDes->mes = des->mes;
        noDes->ano = des->ano;
        noDes->status = des->status;
        noDes->prox = NULL;
        if (lista == NULL) {
            lista = noDes;
        } else {
            ultimo->prox = noDes;
        }
        ultimo = noDes;


        }
    }
    fclose(fp);
    free(des);
    return lista;
}

NoDes* relatorioDespesaInvertido (void) {
    
    FILE* fp;
    Despesa* des;
    NoDes* noDes;
    NoDes* lista;
    NoDes* ultimo;

    lista = NULL;

    fp = fopen("despesas.dat", "rb");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
    des = (Despesa*) malloc(sizeof(Despesa));
    while (fread(des, sizeof(Despesa), 1, fp)) {
        if (des->status == '1') {

        noDes = (NoDes*) malloc(sizeof(NoDes));
        strcpy(noDes->valor, des->valor);
        strcpy(noDes->descricao, des->descricao);
        strcpy(noDes->categoria, des->categoria);
        noDes->dia = des->dia;
        noDes->mes = des->mes;
        noDes->ano = des->ano;
        noDes->status = des->status;
        noDes->prox = lista;
        lista = noDes;

        }
    }
    fclose(fp);
    free(des);
    return lista;
}

// O relatorio é gerado de acordo com o valor de cada despesa 

NoDes* relatorioDespesaOrdenado(void) {
  
    FILE* fp;
    Despesa* des;
    NoDes* noDes;
    NoDes* lista;

    lista = NULL;

    fp = fopen("despesas.dat", "rb");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
    des = (Despesa*) malloc(sizeof(Despesa));
    while (fread(des, sizeof(Despesa), 1, fp)) {
        if (des->status == '1') {

            noDes = (NoDes*) malloc(sizeof(NoDes));
            strcpy(noDes->valor, des->valor);
            strcpy(noDes->descricao, des->descricao);
            strcpy(noDes->categoria, des->categoria);
            noDes->dia = des->dia;
            noDes->mes = des->mes;
            noDes->ano = des->ano;
            noDes->status = des->status;

            char anoS[5];   
            char mesS[3];
            char diaS[3];

            snprintf(anoS, sizeof(anoS), "%d", noDes->ano);
            snprintf(mesS, sizeof(mesS), "%d", noDes->mes);
            snprintf(diaS, sizeof(diaS), "%d", noDes->dia);

            strcat(anoS,mesS);
            strcat(anoS,diaS);

            strcpy(noDes->dataCon, anoS );

            if (lista == NULL) {
                lista = noDes;
                noDes->prox = NULL;
            } else if (strcmp(noDes->dataCon,lista->dataCon) < 0) {
                noDes->prox = lista;
                lista = noDes;
            } else {
            NoDes* anter = lista;
            NoDes* atual = lista->prox;
                while ((atual != NULL) && strcmp(atual->dataCon,noDes->dataCon) < 0) {
                anter = atual;
                atual = atual->prox;
                }
                anter->prox = noDes;
                noDes->prox = atual;
                }
            }
    }
    fclose(fp);
    free(des);
    return lista;
}

// funções dos relatorios das receitas

NoRes* relatorioReceitaDireto (void) {
    
    FILE* fp;
    Receita* res;
    NoRes* noRes;
    NoRes* listaR;
    NoRes* ultimo;

    listaR = NULL;

    fp = fopen("receitas.dat", "rb");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
    res = (Receita*) malloc(sizeof(Receita));
    while (fread(res, sizeof(Receita), 1, fp)) {
        if (res->status == '1') {

        noRes = (NoRes*) malloc(sizeof(NoRes));
        strcpy(noRes->valorR, res->valorR);
        strcpy(noRes->descricaoR, res->descricaoR);
        strcpy(noRes->categoriaR, res->categoriaR);
        noRes->dia = res->dia;
        noRes->mes = res->mes;
        noRes->ano = res->ano;
        noRes->status = res->status;
        noRes->prox = NULL;
        if (listaR == NULL) {
            listaR = noRes;
        } else {
            ultimo->prox = noRes;
        }
        ultimo = noRes;


        }
    }
    fclose(fp);
    free(res);
    return listaR;
}

NoRes* relatorioReceitaInvertido (void) {
    
    FILE* fp;
    Receita* res;
    NoRes* noRes;
    NoRes* listaR;
    NoRes* ultimo;

    listaR = NULL;

    fp = fopen("receitas.dat", "rb");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
    res = (Receita*) malloc(sizeof(Receita));
    while (fread(res, sizeof(Receita), 1, fp)) {
        if (res->status == '1') {

        noRes = (NoRes*) malloc(sizeof(NoRes));
        strcpy(noRes->valorR, res->valorR);
        strcpy(noRes->descricaoR, res->descricaoR);
        strcpy(noRes->categoriaR, res->categoriaR);
        noRes->dia = res->dia;
        noRes->mes = res->mes;
        noRes->ano = res->ano;
        noRes->status = res->status;
        noRes->prox = listaR;
        listaR = noRes;
        }
    }
    fclose(fp);
    free(res);
    return listaR;
}

NoRes* relatorioReceitaOrdenado (void) {
    
    FILE* fp;
    Receita* res;
    NoRes* noRes;
    NoRes* listaR;
    NoRes* ultimo;

    listaR = NULL;

    fp = fopen("receitas.dat", "rb");
    if (fp == NULL){
        printf("\nErro na criacao do arquivo\n!");
    }
    res = (Receita*) malloc(sizeof(Receita));
    while (fread(res, sizeof(Receita), 1, fp)) {
        if (res->status == '1') {

            noRes = (NoRes*) malloc(sizeof(NoRes));
            strcpy(noRes->valorR, res->valorR);
            strcpy(noRes->descricaoR, res->descricaoR);
            strcpy(noRes->categoriaR, res->categoriaR);
            noRes->dia = res->dia;
            noRes->mes = res->mes;
            noRes->ano = res->ano;
            noRes->status = res->status;

            char anoS[5];   
            char mesS[3];
            char diaS[3];

            snprintf(anoS, sizeof(anoS), "%d", noRes->ano);
            snprintf(mesS, sizeof(mesS), "%d", noRes->mes);
            snprintf(diaS, sizeof(diaS), "%d", noRes->dia);

            strcat(anoS,mesS);
            strcat(anoS,diaS);

            strcpy(noRes->dataCon, anoS );

            if (listaR == NULL) {
                listaR = noRes;
                noRes->prox = NULL;
            } else if (strcmp(noRes->valorR,listaR->valorR) < 0) {
                noRes->prox = listaR;
                listaR = noRes;
            } else {
            NoRes* anter = listaR;
            NoRes* atual = listaR->prox;
                while ((atual != NULL) && strcmp(atual->valorR,noRes->valorR) < 0) {
                anter = atual;
                atual = atual->prox;
                }
                anter->prox = noRes;
                noRes->prox = atual;
                }
            }
    }
    fclose(fp);
    free(res);
    return listaR;
}



void exibeListaDespesa(NoDes* lista) {

  while (lista != NULL) {
    printf("\n\n");
    printf(" $ $ $   LISTA DE DESPESAS   $ $ $   \n");
    printf(" $                               $   \n");
    printf(" $    Valor: R$ %s\n", lista->valor);
    printf(" $    Descricao: %s\n", lista->descricao);
    printf(" $    Categoria: %s\n", lista->categoria);
    printf(" $    Data: %d/%d/%d\n", lista->dia, lista->mes, lista->ano);          
    printf(" $                               $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $  \n");
    printf("\n\n");
    lista = lista->prox;
    
  }
}

void exibeListaReceita(NoRes* listaR) {

  while (listaR != NULL) {
    printf("\n\n");
    printf(" $ $ $   LISTA DE RECEITAS   $ $ $   \n");
    printf(" $                               $   \n");
    printf(" $    Valor: R$ %s\n", listaR->valorR);
    printf(" $    Descricao: %s\n", listaR->descricaoR);
    printf(" $    Categoria: %s\n", listaR->categoriaR);
    printf(" $    Data: %d/%d/%d\n", listaR->dia, listaR->mes, listaR->ano);          
    printf(" $                               $   \n");
    printf(" $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $  \n");
    printf("\n\n");
    listaR = listaR->prox;
    
  }
}
// função do menu Sobre

void pausaPrograma(void) {

    printf("\nTecle ENTER para voltar");
    getchar();

}