#include <stdio.h>
#include <stdlib.h>

int main() {
    int prime = 0;
    int num = 0;

    scanf("%d\n",&prime);
    fprintf(stderr, "New prime: %d\n", prime);

    while(num >= 0) {
        scanf("%d\n",&num); // Reading numbers from stdout

        if(num % prime != 0){
            printf("%d\n",num);
        }
    }
    printf("%d\n",num);
}
