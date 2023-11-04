/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.normless.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:39:00 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 01:37:29 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define UINT_MAX 4294967295
#define LONG_MAX 9223372036854775807
#define LONG_MIN -9223372036854775808
#define ULONG_MAX 18446744073709551615

int main(void)
{
	char *str = "Hello, world!";
	/*int num = 42;
	int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0;
	int b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0;

	// Testing ft_printf
	a1 = ft_printf("Testing ft_printf:\n");
	a2 = ft_printf("Character: |%c|\n", *str);
	a2 = ft_printf("Character: |%10c|\n", *str);
	a2 = ft_printf("Character: |%-10c|\n", *str);
	a2 = ft_printf("Character: |%-010c|\n", *str);
	a3 = ft_printf("String: %s\n", str);
	a4 = ft_printf("Integer: %d\n", num);
	a5 = ft_printf("Hexadecimal: %x\n", -15);
	a6 = ft_printf("Pointer: %p\n", &num);

	printf("\n");

	// Testing printf
	b1 = printf("Testing    printf:\n");
	b2 = printf("Character: %c\n", *str);
	b3 = printf("String: %s\n", str);
	b4 = printf("Integer: %d\n", num);
	b5 = printf("Hexadecimal: %x\n", -15);
	b6 = printf("Pointer: %p\n", &num);

	// Testing return values
	printf("\nTesting return values:\n");
	printf("Title:  %d  |  %d\n", a1, b1);
	printf("Char:   %d  |  %d\n", a2, b2);
	printf("String: %d  |  %d\n", a3, b3);
	printf("Int:    %d  |  %d\n", a4, b4);
	printf("Hex:    %d  |  %d\n", a5, b5);
	printf("Ptr:    %d  |  %d\n", a6, b6);

	// Custom tests
	printf("\n");
	printf("|%d|\n", 123456);
	printf("|%10d|\n", 123456);
	printf("|%010d|\n", 123456);
	printf("|% 10d|\n", 123456);
	printf("|% -10d|\n", 123456);
	printf("|%0 10d|\n", 123456);
	printf("|%-+10.8d|\n", 123456);
	printf("|%+-30.6f|\n", 123456.7);
	printf("|% -30.6f|\n", 123456.7);
	printf("|%-+10.10d|\n", 123456);
	printf("|%#20.10x|\n", 123456);
	printf("|%#20.1x|\n", 123456);
	printf("|%-#20.1x|\n", 123456);
	printf("|%#020x|\n", 123456);
	printf("|%20s|\n", str);
	printf("|%-20.5s|\n", str);
	printf("|%-*.*s|\n", 40, 5, str);*/

	ft_printf("Test: |%0d|\n", -1);
	printf("Test: |%0d|\n", -1);

	return 0;
}
