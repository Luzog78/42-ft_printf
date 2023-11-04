CC			= gcc
CFLAGS		= -Werror -Wall -Wextra
NAME		= libftprintf.a
HEADER		= ft_printf.h
SRC_FILES	= ft_printf.c \
				utils/ft_ctox.c \
				utils/ft_format.c \
				utils/ft_parse.c \
				utils/ft_print_chr.c \
				utils/ft_print_hex.c \
				utils/ft_print_nbr.c \
				utils/ft_print_ptr.c \
				utils/ft_print_str.c \
				utils/ft_print_unbr.c
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
