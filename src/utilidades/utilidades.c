#include "utilidades.h" 
#include <stdio.h>
#include <stdlib.h> // Necessário para system("cls") ou system("clear")

// Função para limpar a tela do console
void limparTela() {
#ifdef _WIN32
    system("cls"); // Para Windows
#else
    system("clear"); // Para Linux/macOS
#endif
}

// Função para pausar a execução e esperar pela tecla Enter
void pressionarEnterParaContinuar() {
    printf("Pressione ENTER para continuar...");
    // Limpa o buffer de entrada antes de ler o caractere dummy
    // Isso evita problemas com leituras subsequentes
    while (getchar() != '\n');
    getchar();
}