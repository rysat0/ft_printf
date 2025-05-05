/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:24:00 by rysato            #+#    #+#             */
/*   Updated: 2025/05/02 13:39:46 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>

static char	*int_min_process(char *dst)
{
	int		i;
	long	n;

	n = 2147483648;
	i = 0;
	dst[11] = '\0';
	while (i < 10)
	{
		dst[10 - i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	dst[0] = '-';
	return (dst);
}

static int	count_digits(int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		digit++;
		n = n / 10;
	}
	return (digit);
}

static char	*negative_number_process(int n)
{
	int		digit;
	int		i;
	char	*dst;

	if (n == -2147483648)
	{
		dst = malloc(sizeof(char) * 12);
		if (dst == NULL)
			return (NULL);
		return (int_min_process(dst));
	}
	i = 0;
	digit = count_digits(n);
	dst = malloc(sizeof(char) * (digit + 2));
	if (dst == NULL)
		return (NULL);
	dst[digit + 1] = '\0';
	while (i < digit)
	{
		dst[digit - i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	dst[0] = '-';
	return (dst);
}

char	*ft_itoa(int n)
{
	int		i;
	int		digit;
	char	*dst;

	i = 1;
	if (n < 0)
	{
		n = n * (-1);
		dst = negative_number_process(n);
		return (dst);
	}
	digit = count_digits(n);
	dst = malloc(sizeof(char) * (digit + 1));
	if (dst == NULL)
		return (NULL);
	dst[digit] = '\0';
	while (i <= digit)
	{
		dst[digit - i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	return (dst);
}

// void	test_itoa(int n)
// {
// 	char	*result;

// 	printf("Input: %d\n", n);
// 	result = ft_itoa(n);
// 	if (result)
// 	{
// 		printf("Result: \"%s\"\n", result);
// 		free(result);
// 	}
// 	else
// 		printf("Result: NULL\n");
// 	printf("--------------------------------\n");
// }

// int	main(void)
// {
// 	test_itoa(0);
// 	test_itoa(123);
// 	test_itoa(-123);
// 	test_itoa(42);
// 	test_itoa(-42);
// 	test_itoa(2147483647);  // intの最大値
// 	test_itoa(-2147483648); // intの最小値
// 	return (0);
// }
