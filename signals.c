#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int infinite = 1;

void signalHandler(int signalNumber) {
    printf("Signal received %d \n", signalNumber);
    infinite = 0;
}

int main() {
    int pid;
    signal(10, signalHandler);
    pid = fork();
    if(pid == 0) {
        printf("Soy el hijo\n");
        while(infinite) {
            printf("Entramos al infinito\n");
            sleep(1);
        }
        printf("Ya sali\n");
    } else {
        printf("Soy el padre\n");
        sleep(1);
        kill(pid, 10);
        for(;;);
    }
}