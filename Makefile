# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isam-alv <isam-alv@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 17:26:25 by isam-alv          #+#    #+#              #
#    Updated: 2025/06/18 16:49:16 by isam-alv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft
LIBFT_LIB = $(LIBFT)/libft.a

SRCDIR = .
SRCFILES = ft_printf.c ft_print_char.c ft_print_str.c ft_print_ptr.c ft_print_dig.c \
		   ft_print_unsigned.c ft_print_hex.c

SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT)

$(NAME): $(LIBFT_LIB) $(OBJS)
	cp $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
