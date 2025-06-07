#include <stdio.h>
#include <string.h> // Necessário para strcmp()
#include "includes/utilidades.h" // Caminho ajustado
#include "includes/caixa.h"      // Caminho ajustado
#include "includes/pagamentos.h" // Caminho ajustado
#include "includes/relatorios.h" // Caminho ajustado

int main() {
    char login[20];
    char senha[20];
    int opcaoMenu;

    inicializarCaixa(); // Inicializa as variáveis globais em caixa.c

    limparTela();
    printf("====================================================\n");
    printf("|              CASA DA SORTE LTDA                  |\n");
    printf("|          SISTEMA DE CONTROLE FINANCEIRO          |\n");
    printf("====================================================\n");
    printf("\n");
    printf("Login de acesso: ");
    scanf("%19s", login); // Limita a entrada para evitar estouro de buffer
    printf("Senha: ");
    scanf("%19s", senha); // Limita a entrada

    if (strcmp(login, "admin") == 0 && strcmp(senha, "1234") == 0) {
        do {
            limparTela();
            printf("====================================================\n");
            printf("|              PAINEL ADMINISTRATIVO               |\n");
            printf("====================================================\n");
            printf("| 1 - Controle de Caixa                            |\n");
            printf("| 2 - Pagamento (em breve)                         |\n");
            printf("| 3 - Relatórios (em breve)                        |\n");
            printf("| 0 - Finalizar o acesso                           |\n");
            printf("----------------------------------------------------\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcaoMenu);

            // Limpa o buffer de entrada após ler um inteiro.
            // Isso é importante porque o próximo scanf pode ler o caractere de nova linha restante
            // se não for limpo.
            while (getchar() != '\n');


            switch (opcaoMenu) {
                case 1:
                    menuCaixa(); // Chama o menu do caixa de caixa.c
                    break;
                case 2:
                    menuPagamentos(); // Chama o placeholder para pagamentos
                    break;
                case 3:
                    menuRelatorios(); // Chama o placeholder para relatórios
                    break;
                case 0:
                    break;
                default:
                    printf("Opção inválida. Por favor, tente novamente.\n");
                    pressionarEnterParaContinuar();
                    break;
            }
        } while (opcaoMenu != 0);
        printf("Sessão finalizada. Obrigado por utilizar o sistema!\n");
    } else {
        limparTela();
        printf("\n");
        printf("====================================================\n");
        printf("|         ACESSO NEGADO - CREDENCIAIS INVÁLIDAS    |\n");
        printf("|             Por favor, contate o administrador.  |\n");
        printf("====================================================\n");
    }

    return 0;
}