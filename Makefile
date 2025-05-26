# name
NAME = pipex

# Compile and other commands
CC = @cc
MAKE = @make -C
CFLAGS = -Wall -Wextra -Werror
AR = @ar rcs
RM = @rm
SFLAG = -s

# Libft include
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I./ -Ilibft/src -Ilibft/ft_printf

# Source files and objects
SRCS = pipex.c \
		pipex_process.c \
		pipex_mem.c \
		pipex_utils.c
OBJS = $(SRCS:.c=.o )

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: libft-clean
	$(RM) $(OBJS)

fclean: libft-fclean clean
	$(RM) $(NAME)

re: fclean all

# libft build and full project clean
libft:
	$(MAKE) $(LIBFT_DIR) $(SFLAG) full

libft-clean:
	$(MAKE) $(LIBFT_DIR) $(SFLAG) clean full-clean

libft-fclean:
	$(MAKE) $(LIBFT_DIR) $(SFLAG) fclean full-clean

debug: libft
	$(CC) $(SRCS) $(LIBFT) -o $(NAME)

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
