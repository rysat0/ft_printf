/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:53:02 by rysato            #+#    #+#             */
/*   Updated: 2025/05/05 15:00:13 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <limits.h>   /* INT_MIN, UINT_MAX */
#include <stdio.h>    /* printf */
#include "ft_printf.h"

static void separator(void)
{
	puts("------------------------------------------------------------");
}

/* 比較用ヘルパ：同じフォーマットを ft_printf / printf へ投げて戻り値を表示 */
static void test(const char *fmt, ...)
{
	int   ret_ft;
	int   ret_lib;
	va_list ap1;
	va_list ap2;

	va_start(ap1, fmt);
	va_copy(ap2, ap1);          /* 同じ引数列を 2 回使う */

	/* --- ft_printf --- */
	ret_ft = ft_vprintf(fmt, ap1);
	printf("  [ft_printf return]  %d\n", ret_ft);

	/* --- libc printf --- */
	ret_lib = vprintf(fmt, ap2);
	printf("  [printf    return]  %d\n", ret_lib);

	va_end(ap1);
	va_end(ap2);
	separator();
}

int	main(void)
{
	separator();
	puts("BASIC SET ---------------------------------------------------");
	test("char : %c | string : %s | percent : %%\n", 'A', "Hello");
	test("dec  : %d | int   : %i | unsigned : %u\n", 42, -42, 42u);
	test("hex  : %x | HEX   : %X\n", 0xdeadbeef, 0xdeadbeef);
	test("ptr  : %p\n", (void *)0x1234abcd);

	puts("EDGE CASES --------------------------------------------------");
	test("INT_MIN   : %d\n", INT_MIN);
	test("UINT_MAX  : %u\n", UINT_MAX);
	test("NULL str  : %s\n", (char *)NULL);
	test("NULL ptr  : %p\n", (void *)NULL);
	test("zero hex  : %x\n", 0);

	return (0);
}
