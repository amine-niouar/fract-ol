# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 15:28:36 by aniouar           #+#    #+#              #
#    Updated: 2022/07/27 11:29:32 by aniouar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = fractol.c draw.c square.c circle.c math.c complex.c julia.c common.c
NAME = fractol
OBJS =  $(SRC:.c=.o)
CC = gcc
CFLAGS = 

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
