#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef DMALLOC
#include "dmalloc.h"
#endif

/*
 * $ dmalloc -l logfile -i 100 low
 * $ gcc -DDMALLOC -DDMALLOC_FUNC_CHECK exercise2.c -ldmalloc
 * $ cat logfile
 *
 * https://dmalloc.com/docs/latest/online/dmalloc_4.html#SEC4
 * https://stackoverflow.com/questions/9736589/ld-cannot-link-symbols-although-they-are-in-library
 */


void usage(char *msg) {
  fprintf(stderr, "%s", msg); // From stdio.h
  free(msg);
  return;
}

int main(int argc, char *argv[]) {
  if (argc != 3 && argc != 4) {
    /* the error message won't be more than 80 chars */
    char *errmsg = (char *)malloc(80);
    sprintf( // From stdio.h
      errmsg,
      "Sorry %s,\nUsage: caesar secret_file keys_file [output_file]\n",
      getenv("USER") // From stdlib.h
    );
    usage(errmsg);
    usage(errmsg); // Referring freed memory doesn't make dmalloc triggered.
    free(errmsg); // From stdlib.h
    exit(EXIT_FAILURE); // From stdlib.h
  }

  exit(EXIT_SUCCESS);
}
