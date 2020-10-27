// assinatura da função menu

char mainMenu (void);

// assinatura das funções dos menus

char menuCliente (void);
char menuDespesa (void);
char menuReceita (void);
char menuRelatorio (void);
char menuSobre (void);

// assinatura das funções do menu Cliente

void cadastraCliente (void);
char listaCliente (void);
char buscaCliente (void);
char alteraCliente (void);
char deletaCliente (void);

// assinatura das funções do menu Despesa

char cadastraDespesa (void);
char listaDespesa (void);
char buscaDespesa (void);
char alteraDespesa (void);
char deletaDespesa (void);

// assinatura das funções do menu Receita

char cadastraReceita (void);
char listaReceita (void);
char buscaReceita (void);
char alteraReceita (void);
char deletaReceita (void);

// assinatura das funções do menu Relatorio 

char relatorioDiario (void);
char relatorioSemanal (void);
char relatorioMensal (void);
char relatorioAnual (void);
char escolherPeriodo (void);

// assinatura da função para pausar o programa

void pausaPrograma(void);