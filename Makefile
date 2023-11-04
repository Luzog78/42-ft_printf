CC			= gcc
CFLAGS		= -Werror -Wall -Wextra
NAME		= libftprintf.a
HEADER		= ft_printf.h
SRC_FILES	= ft_printf.c \
				\
				src/formatting/ft_format.c \
				src/formatting/ft_format_c.c \
				src/formatting/ft_format_s.c \
				src/formatting/ft_format_p.c \
				src/formatting/ft_format_d.c \
				src/formatting/ft_format_u.c \
				src/formatting/ft_format_x.c \
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
				src/utils/misc/ft_ctox.c \
				src/utils/misc/ft_init_flags.c \
				src/utils/misc/ft_min.c \
				src/utils/misc/ft_max.c \
				src/utils/misc/ft_str_contains.c \
				src/utils/misc/ft_str_len.c \
				src/utils/misc/ft_uatoi.c
OBJ_FILES	= $(SRC_FILES:.c=.o)

all : $(NAME)

bonus: all

libft:
	make -C Libft

$(NAME) : libft $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I. -L./Libft -lft

clean :
	make -C Libft clean
	rm -rf $(OBJ_FILES)

fclean : clean
	make -C Libft fclean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
