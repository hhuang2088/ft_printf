# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehuang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/20 23:19:16 by hehuang           #+#    #+#              #
#    Updated: 2017/05/27 05:01:58 by hehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ./inc/
SRCDIR = ./src/
EXTRACT = ar -x ./inc/libft.a
TEST_EXT = ar -x libftprintf.a
FLAGS = -g -Wall -Wextra -Werror -c
CC = gcc
OPTIONS = -I$(HEADER) $(FLAGS)
SRC_FILES = ft_printf.c \
			process_tag.c \
			count_handle.c \
			handle_int.c \
			handle_hex.c \
			handle_char.c \
			handle_string.c \
			handle_unsigned.c \
			is_percent.c \
			is_type.c \
			is_flag.c \
			is_length.c \
			handle_oct.c \
			handle_tag.c \
			init_tag.c \
			next_point.c \
			get_type.c \
			scan_flag.c \
			get_width.c \
			create_width.c \
			join_width.c \
			handle_percent.c \
			get_precision.c \
			precision_itoa.c \
			precision_utoa.c \
			procrustean_bed.c \
			get_length.c
LIB_FILES = ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_putstr_fd.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_iswhitespace.c \
			ft_skipwhitespace.c \
			ft_strupper.c \
			ft_strlower.c \
			ft_intiter.c \
			btree_create_node.c \
			btree_apply_prefix.c \
			btree_apply_infix.c \
			btree_apply_suffix.c \
			ft_findchar.c \
			ft_realloc.c \
			get_next_line.c \
			ft_utoa_base.c 
AR = ar rc
SRCS = $(addprefix $(SRCDIR), $(SRC_FILES))
FILES = $(SRC_FILES) $(LIB_FILES)
OBJ_NAME = $(FILES:.c=.o)
RLIB = ranlib

.PHONY: all clean fclean re

all: $(NAME)

$(LIB):
	make -C ./libft

$(NAME):
	$(CC) $(OPTIONS) $(SRCS)
	$(EXTRACT)
	$(AR) $(NAME) $(OBJ_NAME)
	$(RLIB) $(NAME)
	$(TEST_EXT)
	$(CC) $(OPTIONS) test.c -c
	$(CC) $(OBJ_NAME) test.o -o hello

clean:
	rm -f $(OBJ_NAME)

fclean: clean
	rm -f $(NAME)
	rm __.SYMDEF
	rm __.SYMDEF\ SORTED

re: fclean all
