/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:03:25 by rysato            #+#    #+#             */
/*   Updated: 2025/04/28 18:55:59 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*str;
	size_t	available;
	size_t	i;

	slen = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (slen < start)
		available = 0;
	else
		available = slen - start;
	if (available > len)
		available = len;
	str = malloc(sizeof(char) * (available + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < available)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char *res;

	res = ft_substr("HelloWorld", 5, 5);
	printf("Test1: %s\n", res);
	free(res);

	res = ft_substr("Hello", 0, 2);
	printf("Test2: %s\n", res);
	free(res);

	res = ft_substr("Hello", 3, 10);
	printf("Test3: %s\n", res);
	free(res);

	res = ft_substr("Hello", 10, 5);
	printf("Test4: %s\n", res);
	free(res);

	res = ft_substr("Hello", 2, 0);
	printf("Test5: %s\n", res);
	free(res);

	res = ft_substr("", 0, 5);
	printf("Test6: %s\n", res);
	free(res);

	res = ft_substr("Hello", 0, 0);
	printf("Test7: %s\n", res);
	free(res);

	return (0);
}*/
