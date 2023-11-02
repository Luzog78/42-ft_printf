/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 02:18:56 by luzog             #+#    #+#             */
/*   Updated: 2023/11/02 07:50:42 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H "release-1.0"
# include <stdlib.h>
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
void		ft_lstadd_front(t_list **lst, t_list *new_lst);
void		ft_lstadd_back(t_list **lst, t_list *new_lst);
int			ft_lstsize(t_list *list);
t_list		*ft_lstlast(t_list *list);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **list, void (*del)(void *));
void		ft_lstiter(t_list *list, void (*f)(void *));
t_list		*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *));

// Libc
void		*ft_memccpy(void *dest, void const *src, int c, size_t len);
char		*ft_strcpy(char *dest, char const *src);
char		*ft_strncpy(char *dest, char const *src, size_t n);
char		*ft_strcat(char *dest, char const *src);
char		*ft_strncat(char *dest, char const *src, size_t n);
char		*ft_strstr(char *str, char const *to_find);
int			ft_strcmp(char const *s1, char const *s2);

// Miscellanous
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
char		*ft_strmap(char *s, char (*f)(char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
void		ft_putchar(char c);
void		ft_putstr(char const *str);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);

#endif
