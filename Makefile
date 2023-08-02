CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
MDIR = mlx
MFLAGS = -Imlx -lmlx -framework OpenGL -framework AppKit
NAME = cub3d
RM = rm
RMFLAGS = -f

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

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
				make -C $(MDIR)
				$(CC) $(CFLAGS) -L./$(MDIR) $(MFLAGS) $^ -o $@

clean:
				$(RM) $(RMFLAGS) $(OBJS)
				make clean -C $(MDIR)

fclean:
				make clean
				$(RM) $(RMFLAGS) $(NAME)

re:
				make fclean
				make all

.PHONY: all clean fclean re
