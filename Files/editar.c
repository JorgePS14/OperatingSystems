#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    char * file = argv[3];
    char * word = argv[1];
    char * newWord = argv[2];

    char * copy = "temp.txt";
    char * pwd = getcwd(NULL,0);

    char filePath[strlen(file)+strlen(pwd) + 2];
    char copyPath[strlen(copy)+strlen(pwd) + 2];

    sprintf(filePath, "%s/%s", pwd, file);
    sprintf(copyPath, "%s/%s", pwd, copy);

    int readFile = open(filePath, O_RDONLY);

    int copyFile = open(copyPath, O_CREAT|O_WRONLY, 0666);

    char buf[15];
    char emptyBuf[15];
    char c;
    int i = 0;

    int n;

    while(read(readFile, &c, 1)) {
        if(c == ' ') {
            buf[i] = '\0';
            i = 0;
            if(strcmp(buf, word) != 0) {
                write(copyFile, buf, strlen(buf));
                write(copyFile, &c, 1);
            } else {
                write(copyFile, newWord, strlen(newWord));
                write(copyFile, &c, 1);
            }
        } else {
            buf[i++] = c;
        }
    }

    buf[i] = '\0';
    i = 0;
    if(strcmp(buf, word) != 0) {
        write(copyFile, buf, strlen(buf));
    } else {
        write(copyFile, newWord, strlen(newWord));
    }

    close(readFile);
    close(copyFile);

    int succ = unlink(filePath);

    if(succ == -1) {
        printf("Hubo un problema borrando el archivo\n");
        return -1;
    }

    succ = link(copyPath, filePath);

    if(succ == -1) {
        printf("Hubo un problema creando el nuevo nombre del archivo\n");
        return -1;
    }

    succ = unlink(copyPath);

    if(succ == -1) {
        printf("Hubo un problema borrando el archivo\n");
        return -1;
    }
}