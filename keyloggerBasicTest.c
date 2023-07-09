#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main() {
    FILE *logfile;
    int key;

    // Inicializa a biblioteca ncurses
    initscr();
    cbreak();
    noecho();

    // Abre o arquivo de log para escrita
    logfile = fopen("log.txt", "w");

    if (logfile == NULL) {
        printf("Erro ao abrir o arquivo de log.");
        endwin();
        return 1;
    }

    printw("Pressione ESC para sair.\n");
    refresh();

    // Loop infinito para capturar as teclas digitadas
    while (1) {
        key = getch();

        if (key == 27) { // 27 é o código ASCII para ESC
            break;
        }

        fputc(key, logfile); // Grava a tecla no arquivo de log
        fflush(logfile); // Limpa o buffer para garantir a escrita imediata
    }

    fclose(logfile); // Fecha o arquivo de log

    // Encerra a biblioteca ncurses
    endwin();
    printf("Log salvo com sucesso em log.txt.\n");

    return 0;
}
