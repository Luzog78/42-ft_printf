/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:19:41 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/02 15:34:37 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

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
 * @param	width		Integer, default 0, -2 if '*'
 * 
 * @param	precision	Integer, default -1, -2 if '*'
 * 
 * @param	length		Integer, default 0,
 * 						[  1: hh  |  2: h  |  3: l  |  4: ll  ]
 * 
 * @param	type		Character [cspdiuxX%]
*/
typedef struct s_arg
{
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		flag_zero;
	int		flag_hash;
	int		width;
	int		precision;
	int		length;
	char	type;
}	t_arg;


int		ft_print_chr(char c);
int		ft_print_nbr(long long n);
int		ft_print_unbr(unsigned long long n);
int		ft_print_str(char const *str);
char	ft_ctox(unsigned long long c, int is_upper);
int		ft_print_hex(unsigned long long n, int is_upper);
int		ft_print_ptr(void *ptr);

int		ft_printf(const char *format, ...);

#endif
