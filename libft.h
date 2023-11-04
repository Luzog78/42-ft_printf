/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 02:18:56 by luzog             #+#    #+#             */
/*   Updated: 2023/11/01 17:59:15 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# define MAX_UNSIGNED_LONG 18446744073709551615UL

typedef unsigned long long	t_ull;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ******************************** */
/* === ->>  Libc functions  <<- === */
/* ******************************** */

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(char const *str);
void		*ft_memset(void *dest, int c, size_t len);
void		ft_bzero(void *dest, size_t len);
void		*ft_memcpy(void *dest, void const *src, size_t len);
void		*ft_memmove(void *dest, void const *src, size_t len);
size_t		ft_strlcpy(char *dest, char const *src, size_t size);
size_t		ft_strlcat(char *dest, char const *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(char const *str, int c);
char		*ft_strrchr(char const *str, int c);
int			ft_strncmp(char const *s1, char const *s2, size_t n);
void		*ft_memchr(void const *src, int c, size_t len);
int			ft_memcmp(void const *src1, void const *src2, size_t len);
char		*ft_strnstr(char const *str, char const *to_find, size_t len);
int			ft_atoi(char const *str);
void		*ft_calloc(size_t nitems, size_t size);
char		*ft_strdup(char const *src);

/* ************************************** */
/* === ->>  Additional functions  <<- === */
/* ************************************** */

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *str, char const *set);
char		**ft_split(char const *str, char c);
char		*ft_itoa(int integer);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putendl_fd(char *str, int fd);
void		ft_putnbr_fd(int n, int fd);

/* **************************** */
/* === ->>  Bonus Part  <<- === */
/* **************************** */

// Lists
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *list);
t_list		*ft_lstlast(t_list *list);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **list, void (*del)(void *));
void		ft_lstiter(t_list *list, void (*f)(void *));
t_list		*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *));

#endif
