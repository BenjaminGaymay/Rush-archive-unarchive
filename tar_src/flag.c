/*
** flag.c for flags.c in /home/benjamin.g/delivery/CPE_2016_b2rush1
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Sat Mar  4 16:24:49 2017 Benjamin GAYMAY
** Last update Sat Mar  4 16:31:48 2017 Benjamin GAYMAY
*/

#include "my_tar.h"
#include "my_archive.h"

int	my_c(char *flag)
{
  flag[1] = '1';
  return (SUCCESS);
}

int	my_v(char *flag)
{
  flag[2] = '1';
  return (SUCCESS);
}

int	my_f(char *flag)
{
  flag[3] = '1';
  return (SUCCESS);
}

int	my_t(char *flag)
{
  flag[4] = '1';
  return (SUCCESS);
}

int	my_p(char *flag)
{
  flag[5] = '1';
  return (SUCCESS);
}
