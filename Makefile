NAME		=	push_swap
CC			=	clang
SRC			=	main.c		\
				rules.c		\
				radix.c
CFLAGS		=	-Ilibft -Ilibft/ft_printf -Wextra -Wall -Werror -g
LIBFT_PATH	=	libft/
LIBFT_NAME	=	libft.a
OBJ_SRC		=	$(SRC:.c=.o)

all: $(LIBFT_NAME) $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) $(LIBFT_PATH)$(LIBFT_NAME) -o $(NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJ_SRC)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

run: all
	./$(NAME)
