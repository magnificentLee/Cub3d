# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 23:07:26 by jeongmil          #+#    #+#              #
#    Updated: 2023/07/31 23:07:27 by jeongmil         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

SRCS		= main.c \
			./utils/ft_atoi.c \
			./utils/ft_split.c \
			./utils/get_next_line.c \
			./utils/get_next_line_utils.c \
			./utils/utils.c \
			./parsing/parsing.c \
			./parsing/initialize.c \
			./mapping/mapping.c \
			./mapping/image_texture.c \
			./mapping/event.c \

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		=  -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		cc -o $(NAME) $(OBJS) -L./mlx -lmlx -framework OpenGL -framework AppKit -g -fsanitize=address

%.o			:	%.c
		cc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)

fclean		:	clean
		rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
