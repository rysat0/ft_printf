/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_out_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:40:29 by rysato            #+#    #+#             */
/*   Updated: 2025/05/05 17:06:33 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_out_u(unsigned int num);
int	put_out_smallx(unsigned int num);
int	put_out_largex(unsigned int num);
int	put_out_per(void);

int	put_out_u(unsigned int num)
{
	int		written;
	char	c;

	written = 0;
	if (num >= 10)
	{
		written = put_out_u(num / 10);
		if (written == -1)
			return (-1);
	}
	c = (num % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (written + 1);
}

int	put_out_smallx(unsigned int num)
{
	const char	*base;
	int			written;

	written = 0;
	base = "0123456789abcdef";
	if (num >= 16)
	{
		written = put_out_smallx(num / 16);
		if (written == -1)
			return (-1);
	}
	if (write(1, &base[num % 16], 1) == -1)
		return (-1);
	return (written + 1);
}

int	put_out_largex(unsigned int num)
{
	const char	*base;
	int			written;

	written = 0;
	base = "0123456789ABCDEF";
	if (num >= 16)
	{
		written = put_out_largex(num / 16);
		if (written == -1)
			return (-1);
	}
	if (write(1, &base[num % 16], 1) == -1)
		return (-1);
	return (written + 1);
}

int	put_out_per(void)
{
	char	c;

	c = '%';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}
