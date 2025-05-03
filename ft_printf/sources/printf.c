/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:41:48 by rysato            #+#    #+#             */
/*   Updated: 2025/05/03 17:43:51 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	judge_pattern(char symbol, va_list ap);
static int	ft_vprintf(const char *format, va_list ap);
int			ft_printf(const char *format, ...);

static int	judge_pattern(char symbol, va_list ap)
{
	if (symbol == 'c')
		return (put_out_c(va_arg(ap, int)));
	else if (symbol == 's')
		return (put_out_s(va_arg(ap, char *)));
	else if (symbol == 'p')
		return (put_out_p(va_arg(ap, void *)));
	else if (symbol == 'd' || symbol == 'i')
		return (put_out_int(va_arg(ap, int)));
	else if (symbol == 'u')
		return (put_out_u(va_arg(ap, unsigned int)));
	else if (symbol == 'x')
		return (put_out_smallx(va_arg(ap, unsigned int)));
	else if (symbol == 'X')
		return (put_out_largex(va_arg(ap, unsigned int)));
	else if (symbol == '%')
		return (put_out_per());
	return (-1);
}

static int	ft_vprintf(const char *format, va_list ap)
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
				return (-1);
			format++;
			count++;
			continue ;
		}
		format++;
		tmp = judge_pattern(*format, ap);
		if (tmp == -1)
			return (-1);
		count = count + tmp;
		format++;
	}
	return (count);
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
