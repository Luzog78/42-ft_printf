/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:19:41 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/07 01:59:47 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef long long	t_signed_size;

/**
 * @brief	Store a printf argument
 * @note	FORMAT: %[flags][width][.precision][length]type
 * 
 * @note	INDICATION: '-' for all types
 * @note	INDICATION: '+' only with INTEGER or FLOATING TYPES
 * @note	INDICATION: ' ' only with INTEGER or FLOATING TYPES
 * @note	INDICATION: '0' only with INTEGER or FLOATING or HEXADECIMAL TYPES
 * @note	INDICATION: '#' only with HEXADECIMAL TYPES
 * 
 * @note	EXCLUSION: '+' and ' '
 * @note	EXCLUSION: '-' and '0'
 * @note	EXCLUSION: '0' and PRECISION with NON-FLOATING TYPES
 * @note	EXCLUSION: '+' and PRECISION with NON-FLOATING TYPES
 * 
 * @note	EXCEPTION: Type '%' does not have flags, width, precision or length
 * 
 * @param	flag_minus	Boolean flag for '-', default 0
 * @param	flag_plus	Boolean flag for '+', default 0
 * @param	flag_space	Boolean flag for ' ', default 0
 * @param	flag_zero	Boolean flag for '0', default 0
 * @param	flag_hash	Boolean flag for '#', default 0
 * 
 * @param	width		Integer, default -1, -2 if '*'
 * 
 * @param	precision	Integer, default -1, -2 if '*'
 * 
 * @param	size		Integer, default 0,
 * 						[  1: hh  |  2: h  |  3: l  |  4: ll  ]
 * 
 * @param	type		Character [cspdiuxXo%]
 * 
 * @param	length		Integer, Length of the NON-FOMATTED argument
 * 						WITHOUT the starting '%' character
*/
typedef struct s_arg
{
	int				flag_minus;
	int				flag_plus;
	int				flag_space;
	int				flag_zero;
	int				flag_hash;
	int				width;
	int				precision;
	int				size;
	char			type;
	t_signed_size	length;
}	t_arg;

/* ******************************* */
/* === ->>  Main function  <<- === */
/* ******************************* */

/**
 * @brief	Reproduce the behavior of the printf function
 * 
 * @param	format	Character string to be formatted
 * @param	...		Arguments to be formatted
 * 
 * @note	ERROR: Only if the format string is NULL
 * 					OR there is a %\0 without a previous invalid argument
 * 
 * @return	int		Number of characters printed OR -1 if error (see note)
*/
int				ft_printf(const char *format, ...);

/* ************************************** */
/* === ->>  Formatting functions  <<- === */
/* ************************************** */

t_signed_size	ft_format(t_arg *arg, va_list *args);

t_signed_size	ft_format_c(t_arg *arg, va_list *args);
t_signed_size	ft_format_s(t_arg *arg, va_list *args);
t_signed_size	ft_format_p(t_arg *arg, va_list *args);
t_signed_size	ft_format_d(t_arg *arg, va_list *args);
t_signed_size	ft_format_ld(t_arg *arg, va_list *args);
t_signed_size	ft_format_lld(t_arg *arg, va_list *args);
t_signed_size	ft_format_hd(t_arg *arg, va_list *args);
t_signed_size	ft_format_hhd(t_arg *arg, va_list *args);
t_signed_size	ft_format_u(t_arg *arg, va_list *args);
t_signed_size	ft_format_lu(t_arg *arg, va_list *args);
t_signed_size	ft_format_llu(t_arg *arg, va_list *args);
t_signed_size	ft_format_hu(t_arg *arg, va_list *args);
t_signed_size	ft_format_hhu(t_arg *arg, va_list *args);
t_signed_size	ft_format_x(t_arg *arg, va_list *args);
t_signed_size	ft_format_lx(t_arg *arg, va_list *args);
t_signed_size	ft_format_llx(t_arg *arg, va_list *args);
t_signed_size	ft_format_hx(t_arg *arg, va_list *args);
t_signed_size	ft_format_hhx(t_arg *arg, va_list *args);
t_signed_size	ft_format_o(t_arg *arg, va_list *args);
t_signed_size	ft_format_lo(t_arg *arg, va_list *args);
t_signed_size	ft_format_llo(t_arg *arg, va_list *args);
t_signed_size	ft_format_ho(t_arg *arg, va_list *args);
t_signed_size	ft_format_hho(t_arg *arg, va_list *args);

/* *********************************** */
/* === ->>  Parsing functions  <<- === */
/* *********************************** */

t_arg			*ft_parse(const char *str);

t_signed_size	ft_parse_flags(t_arg *arg, const char *str);
t_signed_size	ft_parse_width(t_arg *arg, const char *str);
t_signed_size	ft_parse_precision(t_arg *arg, const char *str);
t_signed_size	ft_parse_length(t_arg *arg, const char *str);

/* ********************************* */
/* === ->>  Utils functions  <<- === */
/* ********************************* */

// chr
t_signed_size	ft_print_chr(char c);

// str
t_signed_size	ft_print_str(char const *str);
t_signed_size	ft_print_n_str(char const *str, t_signed_size n);

// ptr
t_signed_size	ft_print_ptr(void *ptr, t_signed_size len);
t_signed_size	ft_ptrlen(void *ptr, t_signed_size len);

// nbr
t_signed_size	ft_print_nbr(long long n, char spacing, t_signed_size len);
t_signed_size	ft_nbrlen(long long n, char spacing);
t_signed_size	ft_nbrnlen(long long n, char spacing, t_signed_size len);
t_signed_size	ft_print_simplified_nbr(long long n);

// unbr
t_signed_size	ft_print_unbr(unsigned long long n, t_signed_size len);
t_signed_size	ft_unbrlen(unsigned long long n);
t_signed_size	ft_unbrnlen(unsigned long long n, t_signed_size len);
t_signed_size	ft_print_simplified_unbr(unsigned long long n);

// hex.
t_signed_size	ft_print_hex(unsigned long long n,
					int is_prefixed, t_signed_size len, char type);
t_signed_size	ft_hexlen(unsigned long long n, int is_prefixed);
t_signed_size	ft_hexnlen(unsigned long long n,
					int is_prefixed, t_signed_size len);
void			ft_print_simplified_hex(unsigned long long n, int is_upper);

// oct.
t_signed_size	ft_print_oct(unsigned long long n,
					int is_prefixed, t_signed_size len);
t_signed_size	ft_octlen(unsigned long long n);
t_signed_size	ft_octnlen(unsigned long long n,
					int is_prefixed, t_signed_size len);
void			ft_print_simplified_oct(unsigned long long n);

// miscellanous
int				ft_abs(int n);
char			ft_ctox(unsigned long long c, int is_upper);
void			ft_init_flags(t_arg *arg);
t_signed_size	ft_max(t_signed_size a, t_signed_size b);
t_signed_size	ft_min(t_signed_size a, t_signed_size b);
size_t			ft_str_contains(const char *str, char c);
t_signed_size	ft_str_len(const char *str);
int				ft_uatoi(const char *str);

#endif
