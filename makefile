# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 14:39:13 by pmorgan-          #+#    #+#              #
#    Updated: 2019/01/07 16:54:49 by pmorgan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	./srcs/*.c	\
		./includes/libft/*.c	
OBJS = 	$(SRCS:.c=.o)
INCS1 = ./includes/fillit.h
INCS2 = ./includes/libft/libft.h

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -g $(SRCS) -I$(INCS1) -I$(INCS2) -o $(NAME)

clean:
	/bin/rm -f $(NAME)

fclean: clean

re: fclean all
