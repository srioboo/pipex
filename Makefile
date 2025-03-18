# name
NAME = pipex

# Compile
CC = @cc
CFLAGS = -Wall -Wextra -Werror
# Other comands
AR = @ar rcs
RM = @rm
# Libft include
LIBFT = -Llibft -l:libft.a -Ilibft/src

# Source files
SRCS = pipex.c \
		pipex_utils.c
# Objects
OBJS = $(SRCS:.c=.o )

all: $(NAME)

$(NAME): $(OBJS)
#	$(AR) $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

%c: %.o
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

libft:
	@make -C libft full

test: libft all
	./$(NAME) enter.txt program1 program2 exit.txt

.PHONY: all clean fclean re test libft
