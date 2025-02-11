# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pablo <pablo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 14:34:30 by pabmart2          #+#    #+#              #
#    Updated: 2025/02/11 20:39:50 by pablo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR = ../lib
NAME = libft.a

SRC = \
    ft_atoi.c \
    ft_bzero.c \
    ft_calloc.c \
    ft_get_next_line.c \
    ft_isalnum.c \
    ft_isalpha.c \
    ft_isascii.c \
    ft_isdigit.c \
    ft_isprint.c \
    ft_isspace.c \
    ft_itoa.c \
    ft_lstadd_back.c \
    ft_lstadd_front.c \
    ft_lstclear.c \
    ft_lstdelone.c \
    ft_lstindex.c \
    ft_lstiter.c \
    ft_lstlast.c \
    ft_lstmap.c \
    ft_lstnew.c \
    ft_lstsize.c \
	ft_matrix_free.c \
	ft_matrix_len.c \
	ft_matrix_mincol.c \
	ft_matix_maxcol.c \
    ft_memchr.c \
    ft_memcmp.c \
    ft_memcpy.c \
    ft_memjoin.c \
    ft_memmove.c \
    ft_memset.c \
	ft_mindbl.c \
	ft_minint.c  \
    ft_nothing.c \
    ft_putchar_fd.c \
    ft_putendl_fd.c \
    ft_putnbr_fd.c \
    ft_putstr_fd.c \
    ft_split.c \
	ft_splitm.c \
    ft_realloc.c \
    ft_strchr.c \
	ft_strchrm \
    ft_strdup.c \
    ft_striteri.c \
    ft_strjoin.c \
    ft_strlcat.c \
    ft_strlcpy.c \
    ft_strlen.c \
    ft_strmapi.c \
    ft_strncmp.c \
    ft_strndup.c \
    ft_strnstr.c \
    ft_strrchr.c \
    ft_strtkns.c \
    ft_strtrim.c \
    ft_substr.c \
    ft_tolower.c \
    ft_toupper.c \
    ft_uintptrtob.c \
    ft_uitoa.c \
    ft_uitob.c \
	ft_vect_abs.c \
    ft_vect_add.c \
	ft_vect_cross.c \
	ft_vect_div.c \
    ft_vect_dot.c \
	ft_vect_magn.c \
	ft_vect_norm.c \
    ft_vect_ortproj.c \
    ft_vect_prod.c \
    ft_vect_sub.c \
    ft_printf/check_printer.c \
    ft_printf/ft_printf.c \
    ft_printf/printers/c_printer.c \
    ft_printf/printers/di_printer.c \
    ft_printf/printers/p_printer.c \
    ft_printf/printers/prct_printer.c \
    ft_printf/printers/s_printer.c \
    ft_printf/printers/u_printer.c \
    ft_printf/printers/x_low_printer.c \
    ft_printf/printers/x_up_printer.c \



OBJ = $(SRC:.c=.o)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(LIB_DIR)/$(NAME)

re: fclean
	$(MAKE) all

$(NAME) : $(OBJ)
	@mkdir -p $(LIB_DIR)
	@ar rcs $(LIB_DIR)/$(NAME) $(OBJ)
	@echo "\033[32m\n¡$(NAME) compiled! \
	ᕦ(\033[36m⌐■\033[32m_\033[36m■\033[32m)ᕤ\n"

$(OBJ): %.o : %.c
	@echo "\033[34mCompiling $<\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus
