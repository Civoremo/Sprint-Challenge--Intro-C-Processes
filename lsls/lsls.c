#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *commandNum = argc;
  char *inputPath = argv[1];

  if (inputPath == NULL) {
    printf("ITS EMPTY\n");
  } else {
    printf("WE HAVE SOMETHING\n");
  }

  // Open directory
  struct dirent *pathDir;
  DIR *searchPath;
  DIR *defaultPath;

  searchPath = opendir(inputPath);
  defaultPath = opendir(".");

  // Repeatly read and print entries
  

  // Close directory

  return 0;
}