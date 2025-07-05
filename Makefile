# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/05 22:29:52 by srioboo-          #+#    #+#              #
#    Updated: 2025/07/05 22:34:03 by srioboo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW= \033[33m
COLOUR_MAGENTA=\033[35m
COLOUR_TURQUOISE=\033[36m	
COLOUR_END=\033[0m

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

all: $(NAME)

$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(COLOUR_GREEN)\n$(NAME) compiled!\n$(COLOUR_END)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOUR_BLUE)Compiling: $(COLOUR_END)$<"

clean: libft-clean
	$(RM) $(OBJS)

fclean: libft-fclean clean
	$(RM) $(NAME)

re: fclean all

# libft build and full project clean
libft:
	$(MAKE) $(LIBFT_DIR) $(SFLAG) full
	@echo "$(COLOUR_YELLOW)Compiling Libft $(COLOUR_END)"
	@echo "$(COLOUR_GREEN)\nlibft compiled!\n$(COLOUR_END)"

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
