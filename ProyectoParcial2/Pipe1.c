#include <stdio.h>
#include <stdlib.h>

int main() {
  fprintf(stderr, "Pipe 1 sending numbers to other pipes.\n");
  for (int i = 2; i < 101; i++) {
    printf("%d\n", i);
  }
  fprintf(stderr, "Finalizing.\n");
  printf("%d\n",-1);
}
