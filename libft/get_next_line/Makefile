# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 09:18:47 by srioboo-          #+#    #+#              #
#    Updated: 2025/03/01 00:17:23 by srioboo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN = main

# compliler and compiler flags
CC = @cc
CFLAGS = -Wall -Wextra -Werror
# auxiliary commands
AR = @ar rcs
RM = @rm -f

# source files
SRCS = get_next_line.c \
		get_next_line_utils.c
# objects
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# TEST Section
test:
	$(CC) $(CFLAGS) *.c -o test.out
	./test.out

tclean: fclean
	$(RM) test.out

testm:
	for number in 10 42 1 10000000 ; do \
		cc $(CFLAGS) -D BUFFER_SIZE=$$number *.c -o test.out; ./test.out ; \
	done

# detect memory leaks
sane:
	$(CC) $(CFLAGS) $(SRCS) -o $(BIN) -fsanitize=address,undefined -g
	./$(BIN)

val:
	$(CC) $(CFLAGS) $(SRCS) -o $(BIN)
	valgrind --leak-check=full ./$(BIN)

vall:
	$(CC) $(CFLAGS) $(SRCS) -o $(BIN)
	valgrind --leak-check=full --verbose --track-origins=yes --log-file=leaks.txt ./$(BIN)

.PHONY: all clean fclean sane val test tclean
