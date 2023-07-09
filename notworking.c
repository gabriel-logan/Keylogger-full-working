#include stdio.h
#include stdlib.h
#include conio.h

#if defined(_WIN32)  defined(_WIN64)
     Código específico para Windows
    void executeWindowsAction() {
         Implemente aqui a lógica específica para o Windows
    }
#elif defined(__linux__)
     Código específico para Linux
    void executeLinuxAction() {
         Implemente aqui a lógica específica para o Linux
    }
#elif defined(__APPLE__) && defined(__MACH__)
     Código específico para macOS
    void executeMacOSAction() {
         Implemente aqui a lógica específica para o macOS
    }
#else
     Código genérico para outros sistemas operacionais
    void executeGenericAction() {
         Implemente aqui a lógica genérica para outros sistemas operacionais
    }
#endif

int main() {
    FILE logfile;
    char key;

     Abre o arquivo de log para escrita
    logfile = fopen(log.txt, w);

    if (logfile == NULL) {
        printf(Erro ao abrir o arquivo de log.);
        return 1;
    }

    printf(Pressione ESC para sair.n);

     Verifica qual sistema operacional está sendo executado e executa ação correspondente
    #if defined(_WIN32)  defined(_WIN64)
        executeWindowsAction();
    #elif defined(__linux__)
        executeLinuxAction();
    #elif defined(__APPLE__) && defined(__MACH__)
        executeMacOSAction();
    #else
        executeGenericAction();
    #endif

     Loop infinito para capturar as teclas digitadas
    while (1) {
        if (kbhit()) {  Verifica se uma tecla foi pressionada
            key = getch();  Obtém a tecla pressionada

            if (key == 27) {  27 é o código ASCII para ESC
                break;
            }

            fputc(key, logfile);  Grava a tecla no arquivo de log
            fflush(logfile);  Limpa o buffer para garantir a escrita imediata
        }
    }

    fclose(logfile);  Fecha o arquivo de log
    printf(Log salvo com sucesso em log.txt.n);

    return 0;
}
