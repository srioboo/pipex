# name
NAME = pipex

# Compile
CC = @cc
CFLAGS = -Wall -Wextra -Werror
# Other comands
AR = @ar rcs
RM = @rm
# Libft include
LIBFT = -Llibft -l:libft.a
INCLUDES = -I./ -Ilibft/src -Ilibft/ft_printf

# Source files
SRCS = pipex.c \
		pipex_process.c \
		pipex_utils.c pipex_log.c
# Objects
OBJS = $(SRCS:.c=.o )

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

%c: %.o
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# libft build and full project clean
libft:
	@make -C libft full

full-clean: fclean
	@make -C libft full-clean

debug: libft
	$(CC) -D DEBBUG=1 $(SRCS) $(LIBFT) -o $(NAME)

norma:
	norminette *.c *.h
# libft

# test section
test: libft
	$(CC) $(SRCS) $(LIBFT) -o $(NAME)

# detect memory leaks
sane: libft all
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) -o $(NAME) -fsanitize=address,undefined -g
	./$(NAME)

val: all
	valgrind --leak-check=full ./$(NAME)

vall: all
	valgrind --leak-check=full --verbose --track-origins=yes --log-file=leaks.txt ./$(NAME)

.PHONY: all clean fclean re test libft full-clean sane val vall debug
