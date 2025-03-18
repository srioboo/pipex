# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 16:30:18 by srioboo-          #+#    #+#              #
#    Updated: 2025/03/01 00:31:23 by srioboo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# library name
NAME = libft.a
# compliler and compiler flags
CC = @cc
CFLAGS = -Wall -Wextra -Werror
# auxiliary commands
AR = @ar rcs
RM = @rm -f

# source files
SRCS = src/ft_atoi.c \
		src/ft_bzero.c \
		src/ft_calloc.c \
		src/ft_isalnum.c \
		src/ft_isalpha.c \
		src/ft_isascii.c \
		src/ft_isdigit.c \
		src/ft_isprint.c \
		src/ft_itoa.c \
		src/ft_memchr.c \
		src/ft_memcmp.c \
		src/ft_memcpy.c \
		src/ft_memmove.c \
		src/ft_memset.c \
		src/ft_putchar_fd.c \
		src/ft_putendl_fd.c \
		src/ft_putnbr_fd.c \
		src/ft_putstr_fd.c \
		src/ft_split.c \
		src/ft_strchr.c \
		src/ft_strdup.c \
		src/ft_striteri.c \
		src/ft_strjoin.c \
		src/ft_strlcat.c \
		src/ft_strlcpy.c \
		src/ft_strlen.c \
		src/ft_strmapi.c \
		src/ft_strncmp.c \
		src/ft_strnstr.c \
		src/ft_strrchr.c \
		src/ft_strtrim.c \
		src/ft_substr.c \
		src/ft_tolower.c \
		src/ft_toupper.c

# source files bonus
BONUS_SRCS = src/ft_lstadd_back_bonus.c \
		src/ft_lstadd_front_bonus.c \
		src/ft_lstclear_bonus.c \
		src/ft_lstdelone_bonus.c \
		src/ft_lstiter_bonus.c \
		src/ft_lstlast_bonus.c \
		src/ft_lstmap_bonus.c \
		src/ft_lstnew_bonus.c \
		src/ft_lstsize_bonus.c

# source files
PRINTF_SRCS = ft_printf/ft_printf.c \
		ft_printf/ft_type.c \
		ft_printf/ft_putchar.c \
		ft_printf/ft_putstr.c \
		ft_printf/ft_puthex.c \
		ft_printf/ft_putnumber.c \
		ft_printf/ft_putpointer.c \
		ft_printf/ft_putpercent.c

# source files
GNL_SRCS = get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

# objects
OBJECTS = $(SRCS:.c=.o)
BONUS_OBJECTS = $(BONUS_SRCS:.c=.o)
PRINTF_OBJECTS = $(PRINTF_SRCS:.c=.o)
GNL_OBJECTS = $(GNL_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	$(AR) $(NAME) $?

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# generate full library libft, libft_bonus and ft_printf
full: $(OBJECTS) $(BONUS_OBJECTS) $(PRINTF_OBJECTS) $(GNL_OBJECTS)
	$(AR) $(NAME) $?

full-clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS) $(PRINTF_OBJECTS) $(GNL_OBJECTS)

# TEST Section
test: full
	$(MAKE) -f src-tests/Makefile test

tclean:
	$(MAKE) -f src-tests/Makefile tclean

# Memory leaks detection
sane:
	$(MAKE) -f src-tests/Makefile sane

val: 
	$(MAKE) -f src-tests/Makefile val

.PHONY: all clean fclean re bonus test tclean sane val full full-clean
