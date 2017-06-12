##
## Makefile for Makefile in /home/benjamin.g/save/nouveau_projet
##
## Made by Benjamin GAYMAY
## Login   <benjamin.g@epitech.net>
##
## Started on  Sun Nov 20 13:42:20 2016 Benjamin GAYMAY
## Last update Sat Mar  4 18:22:06 2017 Benjamin GAYMAY

CC	=	gcc -g

NAME_1	=	my_archive

NAME_2	=	my_unarchive

NAME_3	=	my_tar

SRC_ALL	=	./src/get_next_line.c \

SRC_1	=	./archive_src/main.c \
		./archive_src/my_archive.c \

SRC_2	=	./unarchive_src/main.c

SRC_3	=	./tar_src/main.c \
		./tar_src/unarchive.c \
		./tar_src/flag.c \
		./tar_src/my_archive.c \
		./tar_src/my_archive2.c \

OBJ_ALL	=	$(SRC_ALL:.c=.o)

OBJ_1	=	$(SRC_1:.c=.o)

OBJ_2	=	$(SRC_2:.c=.o)

OBJ_3	=	$(SRC_3:.c=.o)

CFLAGS +=	-I./include

RM	=	rm -f

all	:	$(NAME_1) $(NAME_2) $(NAME_3)

$(NAME_1):	$(OBJ_1) $(OBJ_ALL)
		$(CC) -o $(NAME_1) $(OBJ_1) $(OBJ_ALL)

$(NAME_2):	$(OBJ_2) $(OBJ_ALL)
		$(CC) -o $(NAME_2) $(OBJ_2) $(OBJ_ALL)

$(NAME_3):	$(OBJ_3) $(OBJ_ALL)
		$(CC) -o $(NAME_3) $(OBJ_3) $(OBJ_ALL)

clean	:
		$(RM) $(OBJ_ALL)
		$(RM) $(OBJ_1)
		$(RM) $(OBJ_2)
		$(RM) $(OBJ_3)

fclean	:	clean
		$(RM) $(NAME_1)
		$(RM) $(NAME_2)
		$(RM) $(NAME_3)

re	:	fclean all

.PHONY	:	all clean fclean re
