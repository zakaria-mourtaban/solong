NAME = so_long
CFLAGS = -g #-Wall -Werror -Wextra -g
SRCS = so_longsrc/main.c
OBJS = $(SRCS:.c=.o)

# Paths to ft_printf, libft, and MinilibX directories
PRINTF_DIR = ./ft_printf
LIBFT_DIR = ./libft
MINILIBX_DIR = ./minilibx_linux

# Library flags
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(PRINTF_DIR)
	@make -C $(LIBFT_DIR)
	# Make sure to include -L$(MINILIBX_DIR) for MinilibX
	gcc $(CFLAGS) $(OBJS) so_longsrc/solong.h -L$(PRINTF_DIR) -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -lftprintf -lft -lmlx -lXext -lX11 -lm -o $(NAME)

%.o: so_longsrc/%.c
	gcc $(CFLAGS) -Iso_longsrc -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(PRINTF_DIR) clean
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re 
