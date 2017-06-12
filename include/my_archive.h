/*
** my_archive.h for my_archive in /home/benjamin.g/CPE_2016_b2rush1
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Mar  3 22:35:26 2017 Benjamin GAYMAY
** Last update Sat Mar  4 18:34:21 2017 Benjamin GAYMAY
*/

#ifndef MY_ARCHIVE_H_

# define MY_ARCHIVE_H_

# define ERROR 84
# define SUCCESS 0
# define FAILURE 1

#include <dirent.h>

int	check_dir2(int fd, DIR *dir);
DIR	*check_dir3(int fd, char *to_compile, char *my_dir, DIR *dir);

#endif /* !MY_ARCHIVE_H_ */
