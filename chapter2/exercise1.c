#include <stdio.h>

void increment(void) {
  void retrieve(void) {
    printf("retrieved: %d\n", counter);
  }

  static unsigned int counter = 0;
  counter++;
  printf("%d\n", counter);
  retrieve();
}

int main(void) {
  for (int i = 0; i < 5; i++) {
    increment();
    retrieve();
  }
  return 0;
}
