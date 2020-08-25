#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int absolute_value(int a) {
  if (a < 0) {
    return -a;
  }
  return a;
}

int main(void) {
  printf("%d\n", absolute_value(1));
  printf("%d\n", absolute_value(-1));
  printf("%d\n", INT_MIN);
  printf("%u\n", absolute_value(INT_MIN)); // This is ...
  
  return EXIT_SUCCESS;
}
