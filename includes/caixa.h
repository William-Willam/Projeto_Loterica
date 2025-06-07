#ifndef CAIXA_H
#define CAIXA_H

// Constantes para o tamanho dos arrays (corresponde ao seu limite de 10 itens)
#define MAX_REGISTROS 10

// Structs para organizar os dados
typedef struct {
    char nome[50];
    double valor;
} EntradaConta;

typedef struct {
    char tipoJogo[50];
    int quantidadeBilhetes;
    double valorUnitario;
} VendaJogo;

typedef struct {
    char nomeCliente[50];
    char cpfCliente[15]; // CPF pode ter 11 dígitos + 2 pontos + 1 hífen + terminador nulo
    char numeroConta[20];
    double valor;
} TransacaoCliente; // Usado tanto para depósitos quanto para saques

typedef struct {
    char nomePremiacao[50];
    double valor;
} Premiacao;

typedef struct {
    char nomeComissao[50];
    double valor;
} Comissao;

// Variáveis globais (ou considere passá-las para funções para um design mais limpo)
extern EntradaConta contas[MAX_REGISTROS];
extern int totalContas;
extern VendaJogo jogos[MAX_REGISTROS];
extern int totalJogos;
extern TransacaoCliente depositos[MAX_REGISTROS];
extern int totalDepositos;
extern Premiacao premiacoes[MAX_REGISTROS];
extern int totalPremiacoes;
extern Comissao comissoes[MAX_REGISTROS];
extern int totalComissoes;
extern TransacaoCliente saques[MAX_REGISTROS];
extern int totalSaques;

extern double totalEntradas;
extern double valorTotalDepositos;
extern double valorTotalPremiacoes;
extern double valorTotalComissoes;
extern double valorTotalSaques;
extern double totalSaidas;
extern double saldoFinal;

// Protótipos das funções
void inicializarCaixa();
void menuRegistrarEntradas();
void menuRegistrarSaidas();
void mostrarSaldoFinalCaixa();

// Funções de Entrada
void registrarPagamentoConta();
void registrarVendaJogo();
void registrarDeposito();
void mostrarValorTotalEntradas();

// Funções de Saída
void registrarPagamentoPremiacao();
void registrarPagamentoComissao();
void registrarSaque();
void mostrarValorTotalSaidas();

// Função principal do menu do caixa
void menuCaixa();

#endif // CAIXA_H