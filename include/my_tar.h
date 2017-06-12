/*
** my_tar.h for my_archive in /home/benjamin.g/CPE_2016_b2rush1
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Mar  3 22:35:26 2017 Benjamin GAYMAY
** Last update Sat Mar  4 17:22:04 2017 Benjamin GAYMAY
*/

#ifndef MY_TAR_H_

# define MY_TAR_H_

int	my_x(char *);
int	my_c(char *);
int	my_v(char *);
int	my_f(char *);
int	my_t(char *);
int	my_p(char *);

int	launch_unarchive(int, char **, char *);
int	launch_archive(int, char **, char *);

#endif /* !MY_TAR_H_ */
