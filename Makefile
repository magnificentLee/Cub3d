NAME		= cub3d

SRCS		= main.c \
			./utils/ft_atoi.c \
			./utils/ft_split.c \
			./utils/ft_str_is_numeric.c \
			./utils/get_next_line.c \
			./utils/get_next_line_utils.c \
			./utils/utils.c \
			./utils/map_parsing_utils.c \
			./parsing/parsing.c \
			./parsing/parse_check.c\
			./parsing/parse_error.c\
			./parsing/valid_color_texture.c \
			./parsing/get_color_texture.c \
			./parsing/process_map_line.c \
			./parsing/initialize.c \
			./parsing/dup_check.c \
			./mapping/mapping.c \
			./mapping/image_texture.c \
			./mapping/event.c \
			./mapping/player.c \

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		=  -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
#		make -C ./mlx
		cc -o $(NAME) $(OBJS) -L./mlx -lmlx -framework OpenGL -framework AppKit -g -fsanitize=address

%.o			:	%.c
		cc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
#		make clean -C ./mlx		

fclean		:	clean
		rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
