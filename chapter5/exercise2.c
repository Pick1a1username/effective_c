#include <stdio.h>
#include <stdlib.h>

size_t find_element(size_t len, int arr[len], int key) {
  size_t pos = (size_t)-1;
  // traverse arr and search for key
  for (size_t i = 0; i < len; ++i) {
    if (arr[i] == key) {
      pos = i;
      break; // terminate loop
    }
  }
  return pos;
}


int main(void) {
  // https://www.geeksforgeeks.org/function-pointer-in-c/
  int ia[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  size_t result = find_element(10, ia, 21);

  printf("%d", result);
  
  return EXIT_SUCCESS;
}
