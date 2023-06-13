NAME		=	push_swap
CC			=	clang
SRC			=	rules.c		\
				rules2000.c	\
				algo3000.c
ALL_SRC		=	main.c \
				$(SRC)
TEST_SRC	=	test/main.c \
				$(SRC)
CFLAGS		=	-Ilibft/includes -Ilibft/includes/ft_printf -Itest -Wextra -Wall -Werror -g
CFLAGSTEST	=	-lcheck
LIBFT_PATH	=	libft/
LIBFT_NAME	=	libft.a
LIBFT		=	$(LIBFT_PATH)$(LIBFT_NAME)
OBJ_ALL_SRC	=	$(ALL_SRC:.c=.o)
OBJ_TEST_SRC=	$(TEST_SRC:.c=.o)

all: $(LIBFT_NAME) $(NAME)

$(NAME): $(OBJ_ALL_SRC)
	$(CC) $(CFLAGS) $(OBJ_ALL_SRC) $(LIBFT) -o $(NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJ_ALL_SRC)
	rm -f $(OBJ_TEST_SRC)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)
	rm -f test_$(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

test_$(NAME): $(LIBFT_NAME) $(OBJ_TEST_SRC)
	$(CC) $(CFLAGSTEST) $(OBJ_TEST_SRC) $(LIBFT) -o $@ 

test: test_$(NAME)
	./$^ -v | ./test/greenest
