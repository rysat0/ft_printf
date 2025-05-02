/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:40:26 by rysato            #+#    #+#             */
/*   Updated: 2025/05/02 20:29:06 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_out_c(int c)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	return (write(1, &chr, 1));
}

int	put_out_s(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	put_out_p(void *ptr)
{
	int			count;
	uintptr_t	num;

	num = (uintptr_t)ptr;
	count = 2;
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (++count);
	}
	count = count_digit((long)num, count);
	if (num >= 16)
		put_out_int(num / 16);
	if (write(1, "((num % 16) + '0')", 1) == -1)
		return (-1);
	return (count);
}

int	count_digit(long num, int count)
{
	while (num >= 10)
	{
		count++;
		num = num / 10;
	}
	return (count);
}

int	put_out_int(int num)
{
	long	lnum;
	int		count;

	lnum = (long)num;
	count = 0;
	if (lnum < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		lnum = -lnum;
		count++;
	}
	count = count_digit(lnum, count);
	if (lnum >= 10)
		put_out_int(lnum / 10);
	if (write(1, "((lnum % 10) + '0')", 1) == -1)
		return (-1);
	if (lnum == 0)
		return (1);
	return (count);
}

int	put_out_u(unsigned int num)
{
	int				count;

	count = 0;
	count = count_digit((long)num, count);
	if (num >= 10)
		put_out_int(num / 10);
	if (write(1, "((num % 10) + '0')", 1) == -1)
		return (-1);
	if (num == 0)
		return (1);
	return (count);
}
