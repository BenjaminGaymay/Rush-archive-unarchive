/*
** main.c for my_archive in /home/benjamin.g/CPE_2016_b2rush1
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Mar  3 20:48:20 2017 Benjamin GAYMAY
** Last update Thu Mar 23 11:34:08 2017 Benjamin GAYMAY
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

char	*int_to_str(int nb)
{
  char	*s;
  int	i;
  int	tmp;

  tmp = nb;
  i = 1;
  while ((tmp /= 10) > 0)
    ++i;
  if ((s = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  s[i] = '\0';
  while (i--)
    {
      s[i] = nb % 10 + '0';
      nb /= 10;
    }
  return (s);
}

int	add_file(int fd_file, char *to_compile, int lines, char *my_dir)
{
  char	*s;
  int	fd_to_compile;
  int	i;

  if ((fd_to_compile = open(to_compile, O_RDONLY)) == -1)
    return (ERROR);
  s = int_to_str(lines);
  write(fd_file, s, strlen(s));
  free(s);
  write(fd_file, "\n", 1);
  write(fd_file, my_dir, strlen(my_dir));
  if (my_dir[strlen(my_dir) - 1] != '/')
    write(fd_file, "/", 1);
  write(fd_file, to_compile, strlen(to_compile));
  write(fd_file, "\n", 1);
  while ((s = get_next_line(fd_to_compile)))
    {
      write(fd_file, s, strlen(s));
      write(fd_file, "\n", 1);
      free(s);
    }
  close(fd_to_compile);
  return (SUCCESS);
}

int	get_nb_line(char *name)
{
  char	*s;
  int	lines;
  int	fd;

  lines = 0;
  if ((fd = open(name, O_RDONLY)) == -1)
    return (ERROR);
  while ((s = get_next_line(fd)))
    {
      free(s);
      lines++;
    }
  close(fd);
  return (lines);
}

int	my_usage(char *name)
{
  printf("Usage: %s [archive_name] [files ...]\n", name);
  return (SUCCESS);
}

int		check_dir(int fd, char *to_compile, char *my_dir)
{
  struct stat	file;
  struct dirent	*file_in_dir;
  DIR		*dir;

  stat(to_compile, &file);
  if (S_ISDIR(file.st_mode) == 1)
    {
      if ((dir = check_dir3(fd, to_compile, my_dir, dir)) == NULL)
	return (ERROR);
      while ((file_in_dir = readdir(dir)))
	{
	  if (strcmp(file_in_dir->d_name, ".") != 0
	      && strcmp(file_in_dir->d_name, "..") != 0)
	    if (check_dir(fd, file_in_dir->d_name, to_compile) == ERROR)
	      return (ERROR);
	}
      check_dir2(fd, dir);
    }
  else
    {
      write(fd, "f\n", 2);
      if (add_file(fd, to_compile, get_nb_line(to_compile), my_dir) == ERROR)
	return (ERROR);
    }
  return (SUCCESS);
}

int	main(int argc, char *argv[])
{
  int	lines;
  int	fd_file;

  if (argc < 3)
    return (my_usage(argv[0]));
  if ((fd_file = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
    return (ERROR);
  if (fd_file == -1)
    return (ERROR);
  while (--argc > 1)
    {
      if (strcmp(argv[1], argv[argc]) == 0)
	return (ERROR);
      if (check_dir(fd_file, argv[argc], "./") == ERROR)
	return (ERROR);
    }
  close(fd_file);
  return (SUCCESS);
}
