#include <stdio.h>
#include <stdlib.h>

#ifdef DMALLOC
#include "dmalloc.h"
#endif


int main(void) {
  char *errmsg = (char *)malloc(80);

  free(errmsg); // From stdlib.h
  free(errmsg); // From stdlib.h

  exit(EXIT_SUCCESS);
}
