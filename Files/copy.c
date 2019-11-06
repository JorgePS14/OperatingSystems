#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    char * file = argv[1];
    char * copy = argv[2];
    char * pwd = getcwd(NULL,0);

    char filePath[strlen(file)+strlen(pwd) + 2];
    char copyPath[strlen(copy)+strlen(pwd) + 2];

    sprintf(filePath, "%s/%s", pwd, file);
    sprintf(copyPath, "%s/%s", pwd, copy);

    printf("Path 1: %s\n", filePath);
    printf("Path 2: %s\n", copyPath);

    int readFile = open(filePath, O_RDONLY);

    int copyFile = open(copyPath, O_CREAT|O_WRONLY, 0666);

    char buf[100];
    char emptyBuf[100];

    int n;

    while((n = read(readFile, buf, 100)) != 0) {
        write(copyFile, buf, n);
    }

    printf("Finished copying file.\n");

    close(filePath);
    close(copyPath);
}