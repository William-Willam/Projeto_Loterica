#include "includes/caixa.h"      // Caminho ajustado
#include "includes/utilidades.h" // Caminho ajustado
#include <stdio.h>
#include <string.h> // Para operações com strings como strcpy

// Definição das variáveis globais
EntradaConta contas[MAX_REGISTROS];
int totalContas;
VendaJogo jogos[MAX_REGISTROS];
int totalJogos;
TransacaoCliente depositos[MAX_REGISTROS];
int totalDepositos;
Premiacao premiacoes[MAX_REGISTROS];
int totalPremiacoes;
Comissao comissoes[MAX_REGISTROS];
int totalComissoes;
TransacaoCliente saques[MAX_REGISTROS];
int totalSaques;

double totalEntradas;
double valorTotalDepositos;
double valorTotalPremiacoes;
double valorTotalComissoes;
double valorTotalSaques;
double totalSaidas;
double saldoFinal;

// Inicializa todas as variáveis do caixa para 0
void inicializarCaixa() {
    totalContas = 0;
    totalJogos = 0;
    totalDepositos = 0;
    totalPremiacoes = 0;
    totalComissoes = 0;
    totalSaques = 0;

    totalEntradas = 0.0;
    valorTotalDepositos = 0.0;
    valorTotalPremiacoes = 0.0;
    valorTotalComissoes = 0.0;
    valorTotalSaques = 0.0;
    totalSaidas = 0.0;
    saldoFinal = 0.0;
}

// --- FUNÇÕES DE ENTRADA ---

void registrarPagamentoConta() {
    limparTela();
    printf("------------- Registro de Contas a Pagar -------------\n");
    if (totalContas < MAX_REGISTROS) {
        printf("Nome da conta (ex: conta de luz): ");
        // Usando scanf("%49s", ...) para evitar estouro de buffer para arrays de char.
        // Para strings com espaços, o ideal seria usar fgets.
        scanf("%49s", contas[totalContas].nome);
        printf("Valor pago (R$): ");
        scanf("%lf", &contas[totalContas].valor);
        totalContas++;
        printf("Conta registrada com sucesso!\n");
    } else {
        printf("Limite de registros atingido (%d).\n", MAX_REGISTROS);
    }
    pressionarEnterParaContinuar();
}

void registrarVendaJogo() {
    limparTela();
    printf("-------------- Registro de Venda de Jogo --------------\n");
    if (totalJogos < MAX_REGISTROS) {
        printf("Tipo de jogo (ex: Mega-Sena): ");
        scanf("%49s", jogos[totalJogos].tipoJogo);
        printf("Quantidade de bilhetes: ");
        scanf("%d", &jogos[totalJogos].quantidadeBilhetes);
        printf("Valor unitário do bilhete (R$): ");
        scanf("%lf", &jogos[totalJogos].valorUnitario);
        double valorVendaJogo = jogos[totalJogos].quantidadeBilhetes * jogos[totalJogos].valorUnitario;
        printf("Venda registrada. Valor total do bilhete: R$ %.2f\n", valorVendaJogo);
        totalJogos++;
    } else {
        printf("Limite de jogos atingido (%d).\n", MAX_REGISTROS);
    }
    pressionarEnterParaContinuar();
}

void registrarDeposito() {
    limparTela();
    printf("-------------- Registro de Depósitos --------------\n");
    if (totalDepositos < MAX_REGISTROS) {
        printf("Digite o nome do cliente: ");
        scanf("%49s", depositos[totalDepositos].nomeCliente);
        printf("Digite o CPF do cliente: ");
        scanf("%14s", depositos[totalDepositos].cpfCliente); // Campo CPF ajustado para formato
        printf("Digite o número da conta: ");
        scanf("%19s", depositos[totalDepositos].numeroConta);
        printf("Digite o valor do depósito (R$): ");
        scanf("%lf", &depositos[totalDepositos].valor);
        valorTotalDepositos += depositos[totalDepositos].valor;
        printf("Valor total de depósitos até agora: R$ %.2f\n", valorTotalDepositos);
        totalDepositos++;
    } else {
        printf("Limite de depósitos atingido (%d).\n", MAX_REGISTROS);
    }
    pressionarEnterParaContinuar();
}

void mostrarValorTotalEntradas() {
    limparTela();
    totalEntradas = 0.0;
    for (int i = 0; i < totalContas; i++) {
        totalEntradas += contas[i].valor;
    }
    for (int i = 0; i < totalJogos; i++) {
        totalEntradas += (jogos[i].quantidadeBilhetes * jogos[i].valorUnitario);
    }
    for (int i = 0; i < totalDepositos; i++) {
        totalEntradas += depositos[i].valor;
    }
    printf("============== Total de Entradas ================\n");
    printf("Valor total acumulado: R$ %.2f\n", totalEntradas);
    printf("=================================================\n");
    pressionarEnterParaContinuar();
}

void menuRegistrarEntradas() {
    int opcaoMenu;
    do {
        limparTela();
        printf("====================================================\n");
        printf("|              REGISTRAR ENTRADAS                  |\n");
        printf("====================================================\n");
        printf("| 1 - Contas a Pagar                               |\n");
        printf("| 2 - Venda de Jogos                               |\n");
        printf("| 3 - Depósitos                                    |\n");
        printf("| 4 - Mostrar Valor Total de Entradas              |\n");
        printf("| 0 - Voltar ao menu anterior                      |\n");
        printf("----------------------------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu) {
            case 1:
                registrarPagamentoConta();
                break;
            case 2:
                registrarVendaJogo();
                break;
            case 3:
                registrarDeposito();
                break;
            case 4:
                mostrarValorTotalEntradas();
                break;
            case 0:
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
                pressionarEnterParaContinuar();
                break;
        }
    } while (opcaoMenu != 0);
}

// --- FUNÇÕES DE SAÍDA ---

void registrarPagamentoPremiacao() {
    limparTela();
    printf("------------- Registro de Premiações -------------\n");
    if (totalPremiacoes < MAX_REGISTROS) {
        printf("Insira o nome da premiação (ex: Mega-Sena): ");
        scanf("%49s", premiacoes[totalPremiacoes].nomePremiacao);
        printf("Digite o valor da premiação: ");
        scanf("%lf", &premiacoes[totalPremiacoes].valor);

        if (premiacoes[totalPremiacoes].valor > 2000.00) {
            printf("Avisar ao cliente: vá ao Banco Caixa.\n");
        } else {
            printf("Avisar ao cliente que ganhou a premiação.\n");
            // Adiciona ao total apenas se o valor for menor ou igual a 2000,
            // conforme a lógica do seu pseudocódigo
            valorTotalPremiacoes += premiacoes[totalPremiacoes].valor;
        }
        totalPremiacoes++;
    } else {
        printf("Limite de premiações atingido.\n");
    }
    pressionarEnterParaContinuar();
}

void registrarPagamentoComissao() {
    limparTela();
    printf("------------- Registro de Comissão -------------\n");
    if (totalComissoes < MAX_REGISTROS) {
        printf("Nome da comissão (ex: Recarga): ");
        scanf("%49s", comissoes[totalComissoes].nomeComissao);
        printf("Valor total dessa comissão: ");
        scanf("%lf", &comissoes[totalComissoes].valor);
        valorTotalComissoes += comissoes[totalComissoes].valor;
        printf("Valor total de comissões: R$ %.2f\n", valorTotalComissoes);
        totalComissoes++;
    } else {
        printf("Limite de comissões atingido.\n");
    }
    pressionarEnterParaContinuar();
}

void registrarSaque() {
    limparTela();
    printf("-------------- Registro de Saques --------------\n");
    if (totalSaques < MAX_REGISTROS) {
        printf("Nome do cliente: ");
        scanf("%49s", saques[totalSaques].nomeCliente);
        printf("CPF do cliente: ");
        scanf("%14s", saques[totalSaques].cpfCliente);
        printf("Número da conta: ");
        scanf("%19s", saques[totalSaques].numeroConta);
        printf("Valor do saque (R$): ");
        scanf("%lf", &saques[totalSaques].valor);
        valorTotalSaques += saques[totalSaques].valor;
        printf("Total de saques: R$ %.2f\n", valorTotalSaques);
        totalSaques++;
    } else {
        printf("Limite de saques atingido.\n");
    }
    pressionarEnterParaContinuar();
}

void mostrarValorTotalSaidas() {
    limparTela();
    totalSaidas = 0.0;
    // O loop para prêmios: apenas os prêmios <= 2000 são considerados como saída do caixa.
    for (int i = 0; i < totalPremiacoes; i++) {
        if (premiacoes[i].valor <= 2000.00) {
            totalSaidas += premiacoes[i].valor;
        }
    }
    for (int i = 0; i < totalComissoes; i++) {
        totalSaidas += comissoes[i].valor;
    }
    for (int i = 0; i < totalSaques; i++) {
        totalSaidas += saques[i].valor;
    }
    printf("============== Total de Saídas ================\n");
    printf("Valor total acumulado: R$ %.2f\n", totalSaidas);
    printf("===============================================\n");
    pressionarEnterParaContinuar();
}

void menuRegistrarSaidas() {
    int opcaoMenu;
    do {
        limparTela();
        printf("====================================================\n");
        printf("|              REGISTRAR SAÍDAS                    |\n");
        printf("====================================================\n");
        printf("| 1 - Premiação                                    |\n");
        printf("| 2 - Comissão                                     |\n");
        printf("| 3 - Saque                                        |\n");
        printf("| 4 - Mostrar Valor Total de Saídas                |\n");
        printf("| 0 - Voltar ao menu anterior                      |\n");
        printf("----------------------------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu) {
            case 1:
                registrarPagamentoPremiacao();
                break;
            case 2:
                registrarPagamentoComissao();
                break;
            case 3:
                registrarSaque();
                break;
            case 4:
                mostrarValorTotalSaidas();
                break;
            case 0:
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
                pressionarEnterParaContinuar();
                break;
        }
    } while (opcaoMenu != 0);
}

void mostrarSaldoFinalCaixa() {
    limparTela();
    // Recalcula os totais para garantir que estejam atualizados
    totalEntradas = 0.0;
    for (int i = 0; i < totalContas; i++) {
        totalEntradas += contas[i].valor;
    }
    for (int i = 0; i < totalJogos; i++) {
        totalEntradas += (jogos[i].quantidadeBilhetes * jogos[i].valorUnitario);
    }
    for (int i = 0; i < totalDepositos; i++) {
        totalEntradas += depositos[i].valor;
    }

    totalSaidas = 0.0;
    for (int i = 0; i < totalPremiacoes; i++) {
         if (premiacoes[i].valor <= 2000.00) { // Apenas conta como saída se pago pela lotérica
            totalSaidas += premiacoes[i].valor;
        }
    }
    for (int i = 0; i < totalComissoes; i++) {
        totalSaidas += comissoes[i].valor;
    }
    for (int i = 0; i < totalSaques; i++) {
        totalSaidas += saques[i].valor;
    }

    saldoFinal = totalEntradas - totalSaidas;

    printf("============== Saldo Final ================\n");
    printf("Valor total acumulado: R$ %.2f\n", saldoFinal);

    if (saldoFinal > 0) {
        printf("\nCaixa com saldo positivo. Tudo certo para movimentações!\n");
    } else if (saldoFinal == 0) {
        printf("\nNão houve movimentação no caixa!!\n");
    } else { // saldoFinal < 0
        printf("\nCaixa negativado, não podemos fazer os pagamentos!!\n");
    }
    printf("===========================================\n");
    pressionarEnterParaContinuar();
}

void menuCaixa() {
    int opcaoCaixa;
    do {
        limparTela();
        printf("====================================================\n");
        printf("|                CONTROLE DE CAIXA                 |\n");
        printf("====================================================\n");
        printf("| 1 - Registrar Entradas                           |\n");
        printf("| 2 - Registrar Saídas                             |\n");
        printf("| 3 - Mostrar o Saldo do caixa final               |\n");
        printf("| 0 - Voltar ao Menu Principal                     |\n");
        printf("----------------------------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoCaixa);

        switch (opcaoCaixa) {
            case 1:
                menuRegistrarEntradas();
                break;
            case 2:
                menuRegistrarSaidas();
                break;
            case 3:
                mostrarSaldoFinalCaixa();
                break;
            case 0:
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
                pressionarEnterParaContinuar();
                break;
        }
    } while (opcaoCaixa != 0);
}