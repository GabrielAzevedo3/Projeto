// definições das estruturas

typedef struct cliente Cliente;
typedef struct despesa Despesa;
typedef struct receita Receita;

// estruturas 

struct cliente {

    char nome[80];
    int dia;
    int mes;
    int ano;
    char email[50];
    char cpf[12];
    char status;

};

struct despesa {

    char valor[10];
    char descricao[500];
    char categoria[20];
    int dia;
    int mes;
    int ano;
    char status;

};

struct receita {

    char valorR[10];
    char descricaoR[500];
    char categoriaR[15];
    int dia;
    int mes;
    int ano;
    char status;

};

// assinatura da função que aloca memória

char* lelinha(void);

// assinatura das funções do menu Cliente

void cadastraCliente (void);
void listaCliente (void); 
void buscaCliente (void);
void alteraCliente (void);
void deletaCliente (void);


void exibeCliente(Cliente*);

// assinatura das funções do menu Despesa

void cadastraDespesa (void);
void listaDespesa (void);
void buscaDespesa (void);
void alteraDespesa (void);
void deletaDespesa (void);

void exibeDespesa(Despesa*);

// assinatura das funções do menu Receita

void cadastraReceita (void);
void listaReceita (void);
void buscaReceita (void);
void alteraReceita (void);
void deletaReceita (void);

void exibeReceita(Receita*);

// assinatura das funções do menu Relatorio 

void relatorioDiario (void);
void relatorioSemanal (void);
void relatorioMensal (void);
void relatorioAnual (void);
void escolherPeriodo (void);

// assinatura da função para pausar o programa

void pausaPrograma(void);

// assinatura da função validaNome 

int validaNome (char*);

// assinatura da função validaData

int dataValida(int, int, int);
int bissexto(int);

int anoAtual (void); // função que pega o ano atual

// assinatura da função validaEmail

int validaEmail(char*);

// assinatura da função validaCpf

int validaCpf(char*);

int chartoint(char);

char inttochar(int);

// assinatura da função validaValor

int validaValor (char*);

// função que pega a hora atual

void horaAtual(void);
