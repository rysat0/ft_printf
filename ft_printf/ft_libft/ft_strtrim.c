/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:20:32 by rysato            #+#    #+#             */
/*   Updated: 2025/05/02 13:45:15 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>

static int	search_from_start(char const *s1, char const *set, int start)
{
	int	i;

	while (s1[start] != '\0')
	{
		i = 0;
		while (set[i] != '\0')
		{
			if (s1[start] == set[i])
				break ;
			i++;
		}
		if (set[i] == '\0')
			return (start);
		start++;
	}
	return (-1);
}

static int	search_from_end(char const *s1, char const *set, int end)
{
	int	i;

	while (end > 0)
	{
		i = 0;
		while (set[i] != '\0')
		{
			if (s1[end] == set[i])
				break ;
			i++;
		}
		if (set[i] == '\0')
			break ;
		end--;
	}
	return (end);
}

static char	*empty_return(void)
{
	char	*dst;

	dst = malloc(sizeof(char) * 1);
	if (dst == NULL)
		return (NULL);
	dst[0] = '\0';
	return (dst);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*dst;

	i = 0;
	start = 0;
	if (s1 == NULL)
		return (NULL);
	end = (ft_strlen(s1) - 1);
	start = search_from_start(s1, set, start);
	if (start == -1)
		return (empty_return());
	end = search_from_end(s1, set, end);
	dst = malloc(sizeof(char) * (end - start + 2));
	if (dst == NULL)
		return (NULL);
	while (start + i <= end)
	{
		dst[i] = s1[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
void	test_trim(const char *s1, const char *set)
{
	char	*result;

	printf("s1: \"%s\"\n", s1 ? s1 : "(NULL)");
	printf("set: \"%s\"\n", set ? set : "(NULL)");
	result = ft_strtrim(s1, set);
	if (result)
		printf("Result: \"%s\"\n", result);
	else
		printf("Result: NULL\n");
	printf("--------------------------------\n");
	free(result);
}

int	main(void)
{
	test_trim("  Hello World  ", " ");
	test_trim("xx42Tokyo!!xx", "x!");
	test_trim("42Tokyo", "!");
	test_trim("xxxxxx", "x");
	test_trim("", "x");
	test_trim("hello", "");
	// NULL入力は本当は注意だけど試してみたいなら
	// test_trim(NULL, "abc");
	return (0);
}
*/
