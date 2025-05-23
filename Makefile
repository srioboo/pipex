# name
NAME = pipex

# Compile and other commands
CC = @cc
CFLAGS = -Wall -Wextra -Werror
AR = @ar rcs
RM = @rm

# Libft include
LIBFT = ./libft/libft.a
INCLUDES = -I./ -Ilibft/src -Ilibft/ft_printf

# Source files and objects
SRCS = pipex.c \
		pipex_process.c \
		pipex_utils.c \
		pipex_log.c
OBJS = $(SRCS:.c=.o )

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

%c: %.o
	$(CC) $(CFLAGS) -c $< -o $@

clean: libft-clean
	$(RM) $(OBJS)

fclean: libft-fclean clean
	$(RM) $(NAME)

re: fclean all

# libft build and full project clean
libft:
	@make -C ./libft -s full

libft-clean:
	@make -C ./libft -s clean full-clean

libft-fclean:
	@make -C ./libft -s fclean full-clean

debug: libft
	$(CC) -D DEBBUG=1 $(SRCS) $(LIBFT) -o $(NAME)

norm:
	norminette *.c *.h

# detect memory leaks
sane: libft all
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) -o $(NAME) -fsanitize=address,undefined -g
	./$(NAME)

val: all
	valgrind --leak-check=full ./$(NAME)

vall: all
	valgrind --leak-check=full --verbose --track-origins=yes --log-file=leaks.txt ./$(NAME)

.PHONY: all clean fclean re libft libft-clean libft-fclean sane val vall debug
