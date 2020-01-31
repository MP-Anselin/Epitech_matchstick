##
## Makefile for  in /home/M-P.anselin/delivery/CPE/CPE_2016_matchstick
## 
## Made by Anselin Mackendy-pierre
## Login   <M-P.anselin@epitech.net>
## 
## Started on  Tue Feb 14 13:27:12 2017 Anselin Mackendy-pierre
## Last update Sun Feb 26 22:12:55 2017 Anselin Mackendy-pierre
##

NAME	=	matchstick

SRCS	=	install_the_game.c		\
		src/my_get_next_line.c		\
		src/fonction_basic.c		\
		src/map/prepare_map.c		\
		src/map/install_the_stick.c	\
		src/check_arg_gnl.c		\
		src/my_ia/ia.c			\
		src/my_ia/others_fonction.c	\
		src/my_ia/next_ia.c		\
		src/my_ia/remove_stick.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I include

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L. libmy.a

clean:
	rm -f $(OBJS)

re:	clean all
