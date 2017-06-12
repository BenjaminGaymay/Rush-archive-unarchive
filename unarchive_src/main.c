/*
** main.c for my_archive in /home/benjamin.g/CPE_2016_b2rush1
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Mar  3 20:48:20 2017 Benjamin GAYMAY
** Last update Sun Mar  5 15:06:45 2017 Benjamin GAYMAY
*/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "my_archive.h"
#include "get_next_line.h"

char	*get_name(char *s)
{
  char	*s2;
  int	i;
  int	f;

  i = strlen(s) - 2;
  while (i != 0 && s[i] != '/')
    i--;
  if (s[i] == '/')
    i++;
  if ((s2 = malloc(sizeof(char) * (strlen(&s[i]) + 1))) == NULL)
    return (NULL);
  f = 0;
  while (s[i])
    s2[f++] = s[i++];
  s2[f] = '\0';
  free(s);
  return (s2);
}

int	create_files2(int fd, int fd_file, char *s)
{
  int	i;
  int	lines;

  free(s);
  s = get_next_line(fd);
  lines = atoi(s);
  free(s);
  if ((s = get_name(get_next_line(fd))) == NULL)
    return (ERROR);
  fd_file = open(s, O_CREAT | O_WRONLY | O_TRUNC, 0644);
  free(s);
  if (fd_file == -1)
    return (ERROR);
  i = 0;
  while (i++ != lines)
    {
      s = get_next_line(fd);
      write(fd_file, s, strlen(s));
      write(fd_file, "\n", 1);
      free(s);
    }
  close(fd_file);
}

int	create_files(int fd)
{
  char	*s;
  int	fd_file;
  int	lines;
  int	i;

  while ((s = get_next_line(fd)))
    {
      if (strcmp(s, "d") == 0)
	{
	  free(s);
	  if ((s = get_name(get_next_line(fd))) == NULL)
	    return (ERROR);
	  if (mkdir(s, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != 0)
	    return (ERROR);
	  chdir(s);
	  free(s);
	}
      else if (strcmp(s, "f") == 0)
	create_files2(fd, fd_file, s);
      else
	{
	  free(s);
	  chdir("..");
	}
    }
  return (SUCCESS);
}

int	my_usage(char *name)
{
  printf("Usage: %s [archive_name]\n", name);
  return (SUCCESS);
}

int	main(int argc, char *argv[])
{
  int	fd;

  if (argc != 2)
    return (my_usage(argv[0]));
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    return (ERROR);
  if (create_files(fd) == ERROR)
    return (ERROR);
  close(fd);
  return (SUCCESS);
}
