# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 15:42:11 by ftholoza          #+#    #+#              #
#    Updated: 2023/12/15 19:33:55 by ftholoza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = $(addprefix srcs/, $(SRC))
SRC = zoom.c ft_strncmp.c events.c draw.c img.c colors.c fractal_maths.c init_struct.c main.c
HEADER = fractol.h
LINK = -lX11 -lXext -L minilibx -lmlx
OBJ = $(SRC:.c=.o)
NAME = fractol

all : $(NAME)
re : fclean $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -I minilibx-linux -I fractol.h $(LINK) -o fractol
$(OBJ) : $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS) -I minilibx -I fractol.h
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
