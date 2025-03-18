# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 09:18:47 by srioboo-          #+#    #+#              #
#    Updated: 2025/02/28 12:29:29 by srioboo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# library name
NAME = libftprintf.a
# compliler and compiler flags
CC = @cc
CFLAGS = -Wall -Wextra -Werror
# auxiliary commands
AR = @ar rcs
RM = @rm -f

# source files
SRCS = ft_printf.c \
		ft_type.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_puthex.c \
		ft_putnumber.c \
		ft_putpointer.c \
		ft_putpercent.c
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
test: all
	$(MAKE) -f src-tests/Makefile test

tclean:
	$(MAKE) -f src-tests/Makefile tclean

# Memory leaks detection
sane:
	$(MAKE) -f src-tests/Makefile sane

val: 
	$(MAKE) -f src-tests/Makefile val

.PHONY: all clean fclean re test tclean
