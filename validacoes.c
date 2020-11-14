#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "cadastros.h"
#include <ctype.h>
#include <string.h>

// validações do menu cliente

// função feita na monitoria

int validaNome(char *nome) {

    int tam = strlen(nome);
    char letra;
    for (int i = 0; i < tam; i++)
    {
        letra = nome[i];
        if (isdigit(letra)) {
            return 1;
        }
        else if (isalpha(letra)) {
        }
        else if (isspace(letra)) {
        }
        else {
          return 1;
        }
    }
    return 0;
}

// função feita pelo Professor Flavius

int dataValida(int dia, int mes, int ano) {
    int maiorDia;
    if (dia < 1 || mes < 1 || mes > 12 || ano < 0) {
        return 0;
    }
    if (mes == 2 ) {
        if (bissexto(ano)) {
            maiorDia = 29;
        } else {
            maiorDia = 28;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        maiorDia = 30;
    } else {
        maiorDia = 31;
    }
    if (dia > maiorDia) {
        return 0;
    }
    return 1;   
}

int bissexto(int ano) {
    if ((ano % 4 == 0) && (ano % 100 != 0)) {
        return 1;
    } else if (ano % 400 == 0) {
        return 1;
    } else { 
        return 0;
    }
}

// função feita por Hiago e Danrley

int validaEmail(char *email) {

  int tam = strlen(email);
  int arroba = 0, ponto = 0, Aponto = 0, Dponto = 0, i;

  for (i = 0; i < tam; i++){
    char c = email[i];

    if(c == '@'){
      if (arroba)
        break;
      arroba = 1;
      if (i < 3)
        break;
    }
    else if (arroba){ 
      if (ponto){ 
        Dponto++;
      }
      else if (c == '.'){
        ponto = 1;
        if (Aponto < 3){
          break;
        }
      }
      else{
        Aponto++;
      }
    }
  } 

  if (i == tam && Dponto > 1)
    return 1;
  else
    return 0;
}

// função feita por Hiago e Danrley

int validaCpf(char *cpf){

  if ((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) 
  || (strcmp(cpf,"22222222222") == 0) || (strcmp(cpf,"33333333333") == 0) 
  || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) 
  || (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) 
  || (strcmp(cpf,"88888888888") == 0) || (strcmp(cpf,"99999999999") == 0)) {
    return 0;
  }
	int tamanho = strlen(cpf);
    if (tamanho != 11) {
        return 0;
    } else {
      int num;
      int soma1 = 0;
      char digito1, digito2;
      int j = 0;
      for(int i = 10; i >= 2; i--){
        num = chartoint(cpf[j]);
        num *= i;
        soma1 += num;
        j++;
      }
      soma1 = soma1 % 11;
      soma1 = 11 - soma1;
      if(soma1 > 9)
        soma1 = 0;
      digito1 = inttochar(soma1);
      if(digito1 != cpf[9])
        return 0;
      else {
        j = 0;
        soma1 = 0;
        for(int i = 11; i >= 2; i--){
          num = chartoint(cpf[j]);
          num *= i;
          soma1 += num;
          j++;
        }
        soma1 = soma1 % 11;
        soma1 = 11 - soma1;
        if(soma1 > 9)
          soma1 = 0;
        digito2 = inttochar(soma1);
        if(digito2 != cpf[10])
          return 0;
        else
          return 1;
      }
    }  
}

int chartoint(char c){
    return c - '0';
}

char inttochar(int n){
  return n + 48;
}
