#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>


/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int opt;

  for (opt = 0; opt < argc; opt++) {
    // printf("%s\n", argv[opt]);
  }

  // Open directory
  struct dirent *pDirent;
  DIR *our_path;
  DIR *default_path;
  
  our_path = opendir(argv[1]);
  default_path = opendir(".");

  struct stat buf;

  // Repeatly read and print entries
  if (our_path == NULL) {
    while ((pDirent = readdir(default_path)) != NULL) {
      stat(pDirent->d_name, &buf);
      if ((buf.st_mode & S_IFMT) == S_IFDIR) {
        printf("<DIR> ");
        printf("%s\n", pDirent->d_name);
      } else if((buf.st_mode & S_IFMT) == S_IFREG) {
        printf("%10ld ", buf.st_size);
        printf("%s\n", pDirent->d_name);
      }
    }
  } else {
    while ((pDirent = readdir(our_path)) != NULL) {
      stat(pDirent->d_name, &buf);
      if (buf.st_size >= 0) {
        if ((buf.st_mode & S_IFMT) == S_IFREG) {
          printf("%10ld ", buf.st_size);
          printf("%s\n", pDirent->d_name);
        } else if ((buf.st_mode & S_IFMT) == S_IFDIR) {
          printf("<DIR> ");
          printf("%s\n", pDirent->d_name);
        } 
      } else {
        fprintf(stderr, "ST_SIZE ERROR\n");
      }
    }
  }


  // Close directory
  closedir(our_path);
  closedir(default_path);

  return 0;
}