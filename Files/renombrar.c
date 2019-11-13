#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    char * file = argv[1];
    char * rename = argv[2];
    char * pwd = getcwd(NULL,0);

    char filePath[strlen(file)+strlen(pwd) + 2];
    char newPath[strlen(rename)+strlen(pwd) + 2];

    sprintf(filePath, "%s/%s", pwd, file);
    sprintf(newPath, "%s/%s", pwd, rename);

    int succ = link(filePath, newPath);

    if(succ == -1) {
        printf("Hubo un problema creando el nuevo nombre del archivo\n");
        return -1;
    }

    succ = unlink(filePath);

    if(succ == -1) {
        printf("Hubo un problema borrando el archivo\n");
        return -1;
    }
}