#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

char *concat(const char *string1, const char *string2)
{
  char *result = malloc(strlen(string2) + strlen(string1) + 1);
  strcpy(result, string1);
  strcat(result, string2);
  return result;
}

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *opened_dir;
  struct dirent *read_dir;
  struct stat buffer;
  int dir_given;

  if (argc > 2)
  {
    printf("Too Many Arguments!\nPlease Enter format as follows:\n\n ./lsls [DIRECTORY]\n\n");
    printf("Example: ./lsls ../../Processes/\n\n");
    exit(1);
  }
  // Open directory
  else if (argc == 2)
  {
    // use directory provided
    dir_given = 1;
    opened_dir = opendir(argv[1]);
  }
  else
  {
    // use current directory
    opened_dir = opendir(".\0");
    dir_given = 0;
  }

  if (opened_dir == NULL)
  {
    printf("Cannot Open Directory.\n\nPlease Enter format as follows:\n\n ./lsls [DIRECTORY]\n\n");
    printf("Example: ./lsls ../../Processes/\n\n");
    exit(1);
  }

  while ((read_dir = readdir(opened_dir)) != NULL)
  {
    char *current_file;
    if (dir_given == 0)
    {
      current_file = concat("./", read_dir->d_name);
    }
    else
    {
      // current_file = strcpy(argv[1], read_dir->d_name);
      // printf("%s   ", argv[1]);
      current_file = concat(argv[1], read_dir->d_name);
      // printf("%s  ", current_file);
    }

    stat(current_file, &buffer);

  // Repeatly read and print entries
    int file_size = buffer.st_size;

  // Close directory
    if (S_ISDIR(buffer.st_mode))
    // if (buffer.st_mode & S_IFDIR)
    {
      printf("%10s  %s\n", "<DIR>\0", read_dir->d_name);
    }
    else
    {
      printf("%10d  %s\n", file_size, read_dir->d_name);
    }
    free(current_file);
  }
  closedir(opened_dir);

  return 0;
} 