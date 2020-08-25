#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int closedir(DIR *dirp) {
  // No idea which types d_buf and d_fd are.
  free(dirp->d_buf);
  free(dirp);
  return close(dirp->d_fd); // dirp has already been freed
}



