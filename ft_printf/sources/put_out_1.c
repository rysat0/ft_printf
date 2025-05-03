/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:40:26 by rysato            #+#    #+#             */
/*   Updated: 2025/05/03 17:43:02 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_out_c(int c);
int			put_out_s(char *str);
static int	recursive_ptr(uintptr_t num);
int			put_out_p(void *ptr);
int			put_out_int(int num);

int	put_out_c(int c)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	return (write(1, &chr, 1));
}

int	put_out_s(char *str)
{
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	return (write(1, str, ft_strlen(str)));
}

static int	recursive_ptr(uintptr_t num)
{
	int			written;
	const char	*base;

	written = 0;
	base = "0123456789abcdef";
	if (num >= 16)
	{
		written = recursive_ptr(num / 16);
		if (written == -1)
			return (-1);
	}
	if (write(1, &base[num % 16], 1) == -1)
		return (-1);
	return (written + 1);
}

int	put_out_p(void *ptr)
{
	int			written;
	int			rec_write;
	uintptr_t	num;

	if (ptr == NULL)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	num = (uintptr_t)ptr;
	if (write(1, "0x", 2) == -1)
		return (-1);
	written = 2;
	rec_write = recursive_ptr(num);
	if (rec_write == -1)
		return (-1);
	return (written + rec_write);
}

int	put_out_int(int num)
{
	long	lnum;
	char	c;
	int		total;
	int		tmp;

	lnum = (long)num;
	total = 0;
	if (lnum < 0)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		lnum = -lnum;
		total++;
	}
	if (lnum >= 10)
	{
		tmp = put_out_int((int)(lnum / 10));
		if (tmp == -1)
			return (-1);
		total += tmp;
	}
	c = (lnum % 10) + '0';
	if (write(1, &c, 1) != 1)
		return (-1);
	return (total + 1);
}
