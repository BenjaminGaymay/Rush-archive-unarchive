/*
** main.c for my_archive in /home/benjamin.g/CPE_2016_b2rush1
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Mar  3 20:48:20 2017 Benjamin GAYMAY
** Last update Thu Mar 23 11:55:55 2017 Benjamin GAYMAY
*/

#include <stdio.h>
#include "my_tar.h"
#include "my_archive.h"

int	(*ptr_arg[6])(char *flag) =
{
  my_x,
  my_c,
  my_v,
  my_f,
  my_t,
  my_p
};

int	my_x(char *flag)
{
  flag[0] = '1';
  return (SUCCESS);
}

int	disp_usage(char *name)
{
  printf("Usage: %s\n", name);
  return (SUCCESS);
}

int	start_tar(int argc, char **argv, char *flag)
{
  if (flag[0] == '1' && flag[1] == '0')
    {
      if (launch_unarchive(argc, argv, flag) == ERROR)
	return (ERROR);
    }
  else if (flag[0] == '0' && flag[1] == '1')
    {
      if (launch_archive(argc, argv, flag) == ERROR)
	return (ERROR);
    }
  else
    return (ERROR);
  return (SUCCESS);
}

int main(int argc, char *argv[])
{
  char	flag_list[] = "xcvftp\0";
  char	flag[] = "000000\0";
  int	f;
  int	i;

  if (argc < 3)
    return (disp_usage(argv[0]));
  f = 0;
  while (argv[1][f] != '\0')
    {
      i = 0;
      while (flag_list[i] != '\0' && flag_list[i] != argv[1][f])
	i++;
      if (flag_list[i] == '\0')
	return (disp_usage(argv[0]));
      ptr_arg[i](flag);
      f++;
    }
  if (flag[3] != '1')
    {
      printf("Error: missing -f option\n");
      return (ERROR);
    }
  if (start_tar(argc, argv, flag) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
