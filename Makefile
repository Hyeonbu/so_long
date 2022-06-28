NAME		= so_long
LIBFT_PATH	= ./libft/
LIBFT_LIB	= libft.a

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
		make all -C $(LIBFT_PATH)/
		gcc -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@

clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT_PATH)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT_PATH)

re			:	fclean all

.PHONY		:	all clean fclean re
