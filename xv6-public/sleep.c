#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char* argv[]){
    if(argc != 2) {
        printf(1, "Correct format: sleep <time>\n");
        exit();
    } else {
        sleep(atoi(argv[1])*100);
        exit();
    }
}