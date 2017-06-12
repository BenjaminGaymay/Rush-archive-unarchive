/*
** my_archive.c for emacs in /home/BISHOP/Downloads/CPE_2016_b2rush1/archive_src
**
** Made by enzo petitpierre
** Login   <BISHOP@epitech.net>
**
** Started on  Sat Mar  4 15:25:41 2017 enzo petitpierre
** Last update Sat Mar  4 18:35:53 2017 Benjamin GAYMAY
*/

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "my_archive.h"
#include "get_next_line.h"

int	check_dir2(int fd, DIR *dir)
{
  chdir("..");
  write(fd, "--\n", 3);
  closedir(dir);
}

DIR	*check_dir3(int fd, char *to_compile, char *my_dir, DIR *dir)
{
  write(fd, "d\n", 2);
  write(fd, my_dir, strlen(my_dir));
  if (my_dir[strlen(my_dir) - 1] != '/')
    write(fd, "/", 1);
  write(fd, to_compile, strlen(to_compile));
  write(fd, "\n", 1);
  if ((dir = opendir(to_compile)) == NULL)
    return (NULL);
  chdir(to_compile);
  return (dir);
}
