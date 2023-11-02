CC			= clang
CFLAGS		= -Werror -Wall -Wextra
NAME		= libftprintf.a
HEADER		= libftprintf.h
SRC_FILES	= *.c */*.c */*/*.c
OBJ_FILES	= $(MANDATORY_SRC_FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean :
	rm -rf $(OBJ_FILES)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
