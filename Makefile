NAME		= so_long
LIBFT_PATH	= ./libft/
MLX_PATH	= ./mlx/
LIBFT		= libft.a

SRCS		= so_long.c \
			  set_images.c \
			  check_map.c \
			  press_key.c \
			  get_next_line.c \
			  get_next_line_utils.c \

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make -C $(LIBFT_PATH)
		make -C $(MLX_PATH)
		gcc -o $(NAME) $(OBJS) -I./ -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@

clean		:
		make clean -C $(LIBFT_PATH)
		make clean -C $(MLX_PATH)
		rm -f $(OBJS)

fclean		:	clean
		make fclean -C $(LIBFT_PATH)
		rm -f $(NAME)
		rm -f $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re
