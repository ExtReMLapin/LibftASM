# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/03 09:34:53 by pfichepo          #+#    #+#              #
#    Updated: 2018/05/03 09:34:57 by pfichepo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libfts.a

LIN_COMPILER	= nasm -f elf64 -g 

MAC_COMPILER	= nasm -f macho64

LIB_SRC_DIR		= ./src

LIB_SRC			=	ft_bzero.s \
					ft_strcat.s \
					ft_isalpha.s \
					ft_isdigit.s \
					ft_isalnum.s \
					ft_isascii.s \
					ft_isprint.s \
					ft_toupper.s \
					ft_tolower.s \
					ft_puts.s \
					ft_strlen.s \
					ft_memset.s \
					ft_memcpy.s \
					ft_strdup.s \
					ft_strlen2.s \
					ft_cat.s \
					ft_islower.s \
					ft_isupper.s \
					ft_min.s \
					ft_max.s
					
LIB_OBJ		= $(LIB_SRC:.s=.o)

LIB_SRCS	= $(addprefix $(LIB_SRC_DIR)/, $(LIB_SRC))

all : $(NAME)

$(NAME): $(LIB_OBJ)
	ar rc $(NAME) $(LIB_OBJ)

%.o: $(LIB_SRC_DIR)/%.s
	$(MAC_COMPILER) $< -o $@

clean:
	rm -rf $(LIB_OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf test

re: fclean 
	$(MAKE) all

test: all
	gcc -Wall -Werror -Wextra main.c $(NAME) -o test


.PHONY: all clean fclean re test
