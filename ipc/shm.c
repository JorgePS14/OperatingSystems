#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>

int main(void) {
  int pid;
  pid = fork();
  if(pid == 0) {
    int key = 27;
    int shmid = shmget(key, 100, IPC_CREAT|0666);
    char * message = (char *)shmat(shmid, NULL, 0);
    sprintf(message, "Hello world");
    while(message[0] == 'H') {
      sleep(1);
    }
    printf("El mensaje final es: %s \n", message);
  } else {
    int key = 27;
    int shmid = shmget(key, 100, IPC_CREAT|0666);
    char * message = (char *)shmat(shmid, NULL, 0);
    printf("El mensaje es: %s \n", message);
    sleep(1);
    message[0] = '*';
    sleep(1);
  }
}
