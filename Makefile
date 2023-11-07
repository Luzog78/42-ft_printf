# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 19:34:29 by ysabik            #+#    #+#              #
#    Updated: 2023/11/07 02:00:05 by ysabik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Werror -Wall -Wextra
NAME		= libftprintf.a
INCLUDES	= .
SRC_FILES	= ft_printf.c \
				\
				src/formatting/ft_format.c \
				src/formatting/ft_format_c.c \
				src/formatting/ft_format_s.c \
				src/formatting/ft_format_p.c \
				src/formatting/ft_format_d.c \
				src/formatting/ft_format_ld.c \
				src/formatting/ft_format_lld.c \
				src/formatting/ft_format_hd.c \
				src/formatting/ft_format_hhd.c \
				src/formatting/ft_format_u.c \
				src/formatting/ft_format_lu.c \
				src/formatting/ft_format_llu.c \
				src/formatting/ft_format_hu.c \
				src/formatting/ft_format_hhu.c \
				src/formatting/ft_format_x.c \
				src/formatting/ft_format_lx.c \
				src/formatting/ft_format_llx.c \
				src/formatting/ft_format_hx.c \
				src/formatting/ft_format_hhx.c \
				src/formatting/ft_format_o.c \
				src/formatting/ft_format_lo.c \
				src/formatting/ft_format_llo.c \
				src/formatting/ft_format_ho.c \
				src/formatting/ft_format_hho.c \
				\
				src/parsing/ft_parse.c \
				src/parsing/ft_parse_flags.c \
				src/parsing/ft_parse_width.c \
				src/parsing/ft_parse_precision.c \
				src/parsing/ft_parse_length.c \
				\
				src/utils/chr/ft_print_chr.c \
				\
				src/utils/str/ft_print_str.c \
				src/utils/str/ft_print_n_str.c \
				\
				src/utils/ptr/ft_print_ptr.c \
				src/utils/ptr/ft_ptrlen.c \
				\
				src/utils/nbr/ft_print_nbr.c \
				src/utils/nbr/ft_nbrlen.c \
				src/utils/nbr/ft_nbrnlen.c \
				src/utils/nbr/ft_print_simplified_nbr.c \
				\
				src/utils/unbr/ft_print_unbr.c \
				src/utils/unbr/ft_unbrlen.c \
				src/utils/unbr/ft_unbrnlen.c \
				src/utils/unbr/ft_print_simplified_unbr.c \
				\
				src/utils/hex/ft_print_hex.c \
				src/utils/hex/ft_hexlen.c \
				src/utils/hex/ft_hexnlen.c \
				src/utils/hex/ft_print_simplified_hex.c \
				\
				src/utils/oct/ft_print_oct.c \
				src/utils/oct/ft_octlen.c \
				src/utils/oct/ft_octnlen.c \
				src/utils/oct/ft_print_simplified_oct.c \
				\
				src/utils/misc/ft_abs.c \
				src/utils/misc/ft_ctox.c \
				src/utils/misc/ft_init_flags.c \
				src/utils/misc/ft_min.c \
				src/utils/misc/ft_max.c \
				src/utils/misc/ft_str_contains.c \
				src/utils/misc/ft_str_len.c \
				src/utils/misc/ft_uatoi.c
OBJ_FILES	= $(SRC_FILES:.c=.o)

LIBFT_DIR	= ./Libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -I $(LIBFT_DIR) -L $(LIBFT_DIR) -lft
LIBFT_MAKE	= make -C $(LIBFT_DIR)

all : $(NAME)

bonus: all

libft:
	$(LIBFT_MAKE)

$(NAME) : libft $(OBJ_FILES)
	cp $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJ_FILES)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) $(LIBFT_FLAGS)

clean :
	$(LIBFT_MAKE) clean
	rm -rf $(OBJ_FILES)
	rm -rf a.out

fclean : clean
	$(LIBFT_MAKE) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY: bonus libft all clean fclean re
