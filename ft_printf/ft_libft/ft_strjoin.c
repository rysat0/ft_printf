/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:52:45 by rysato            #+#    #+#             */
/*   Updated: 2025/05/02 13:44:11 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static void	join_string(char *dst, char const *str, size_t *i)
{
	size_t	len;
	size_t	j;

	j = 0;
	len = ft_strlen(str);
	while (j < len)
	{
		dst[*i] = str[j];
		j++;
		(*i)++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*dst;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	join_string(dst, s1, &i);
	join_string(dst, s2, &i);
	dst[i] = '\0';
	return (dst);
}
/*
int	main(void)
{
	char	*s1;
	char	*s2;
	char	*dst;

	s1 = "abcde";
	s2 = "123456";
	dst = ft_strjoin(s1, s2);
	printf("%s\n", dst);
	return (0);
}
*/
