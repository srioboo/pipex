# name
NAME = pipex

# Compile
CC = @cc
CFLAGS = -Wall -Wextra -Werror
# Other comands
AR = @ar rcs
RM = @rm

# Source files
SRCS = pipex.c \
	   pipex_utils.c
# Objects
OBJS = $(SRCS:.c=.o )

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%c: %.o
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
