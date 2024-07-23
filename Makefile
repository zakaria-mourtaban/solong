NAME = so_long
CFLAGS = -Wall -Werror -Wextra -g
SRCS = so_longsrc/main.c so_longsrc/handleinput.c so_longsrc/fillframes.c  so_longsrc/checkmap.c so_longsrc/free.c so_longsrc/draw.c so_longsrc/draw2.c so_longsrc/move.c so_longsrc/utils.c
OBJS = $(SRCS:%.c=%.o)

# Paths to ft_printf, libft, and MinilibX directories
PRINTF_DIR = ./ft_printf
LIBFT_DIR = ./libft
MINILIBX_DIR = ./minilibx_linux

# Library files
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a

# Targets
all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB) $(MINILIBX_LIB) $(PRINTF_DIR)/*.c $(LIBFT_DIR)/*.c $(MINILIBX_DIR)/*.c
	gcc $(CFLAGS) -o $(NAME) $(OBJS) -Iso_longsrc -L$(PRINTF_DIR) -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -lftprintf -lft -lmlx -lXext -lX11 -lm

%.o: so_longsrc/%.c so_longsrc/solong.h
	gcc $(CFLAGS) -c $< -o $@

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(MINILIBX_LIB):
	@make -C $(MINILIBX_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
