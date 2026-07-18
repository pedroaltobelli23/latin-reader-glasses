#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  char a = 'A';
  char b = 'B';
  for (;;) {
    putchar(a);
    printf("\x1b[23A");
    usleep(300000);
    putchar(b);
    printf("\x1b[23A");
    usleep(300000);

  }
  return 0;
}