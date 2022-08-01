# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 15:28:36 by aniouar           #+#    #+#              #
#    Updated: 2022/07/30 17:14:26 by aniouar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = julia_func.c  fractol.c draw.c   common.c libft.c run_fractol.c
NAME = fractol
OBJS =  $(SRC:.c=.o)
CC = gcc
CFLAGS = -Werror -Wall -Wextra
all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
