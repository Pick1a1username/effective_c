#include <stdio.h>

void hello(void) {
  printf("Hello ");
}

void world(void) {
  printf("world");
}

void exclamation(void) {
  printf("!\n");
}


int main(void) {
  // https://www.geeksforgeeks.org/function-pointer-in-c/
  void (*hello_p)(void) = &hello;
  void (*world_p)(void) = &world;
  void (*exclamation_p)(void) = &exclamation;
  void (*hw[3])(void);
  hw[0] = hello_p;
  hw[1] = world_p;
  hw[2] = exclamation_p;

  (*hw[0])();
  (*hw[1])();
  (*hw[2])();
  
  return 0;
}
