/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:41:48 by rysato            #+#    #+#             */
/*   Updated: 2025/05/02 21:01:35 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	judge_pattern(char symbol, va_list ap)
{
	if (symbol == 'c')
		return (put_out_c(va_arg(ap, int)));
	if (symbol == 's')
		return (put_out_s(va_arg(ap, char *)));
	if (symbol == 'p')
		return (put_out_p(va_arg(ap, void *)));
	if (symbol == 'd' || symbol == 'i')
		return (put_out_int(va_arg(ap, int)));
	if (symbol == 'u')
		return (put_out_u(va_arg(ap, unsigned int)));
	if (symbol == 'x')
		return (put_out_smallx(va_arg(ap, unsigned int)));
	if (symbol == 'X')
		return (put_out_largex(va_arg(ap, unsigned int)));
	if (symbol == '%')
		return (put_out_per());
	return (0);
}

int	ft_vprintf(const char *format, va_list ap)
{
	int	count;
	int	tmp;

	tmp = 0;
	count = 0;
	while (*format)
	{
		if (*format != '%')
		{
			if (write(1, format, 1) == -1)
				return (count);
			format++;
			count++;
			continue ;
		}
		format++;
		tmp = judge_pattern(*format, ap);
		if (tmp == -1)
			return (count);
		count = count + tmp;
		ap++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	ap;

	va_start(ap, format);
	res = ft_vprintf(format, ap);
	va_end(ap);
	return (res);
}
