/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:17:49 by rysato            #+#    #+#             */
/*   Updated: 2025/05/02 13:43:40 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>

static void	free_array_all(char **array, size_t index)
{
	while (index > 0)
	{
		index--;
		free(array[index]);
	}
	free(array);
}

static size_t	count_words(char const *str, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] == '\0')
			break ;
		words++;
		while (str[i] != '\0' && (str[i] != c))
			i++;
	}
	return (words);
}

static char	*malloc_and_fill(const char *str, size_t len, char **array,
		size_t index)
{
	size_t	n;
	char	*dst;

	n = 0;
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
	{
		free_array_all(array, index);
		return (NULL);
	}
	while (n < len)
	{
		dst[n] = str[n];
		n++;
	}
	dst[n] = '\0';
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	size_t		index;
	char		**dst;
	char const	*start;

	if (s == NULL)
		return (NULL);
	dst = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (dst == NULL)
		return (NULL);
	index = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && (*s == c))
			s++;
		if (*s == '\0')
			break ;
		start = s;
		while (*s != '\0' && !(*s == c))
			s++;
		dst[index] = malloc_and_fill(start, (size_t)(s - start), dst, index);
		if (dst[index++] == NULL)
			return (NULL);
	}
	dst[index] = NULL;
	return (dst);
}

// void	print_split(char **split_result)
// {
// 	int	i;

// 	i = 0;
// 	if (!split_result)
// 	{
// 		printf("Result: NULL\n");
// 		return ;
// 	}
// 	while (split_result[i])
// 	{
// 		printf("[%d]: \"%s\"\n", i, split_result[i]);
// 		i++;
// 	}
// }

// void	free_split(char **split_result)
// {
// 	int	i;

// 	i = 0;
// 	if (!split_result)
// 		return ;
// 	while (split_result[i])
// 	{
// 		free(split_result[i]);
// 		i++;
// 	}
// 	free(split_result);
// }

// void	test_split(const char *s, char c)
// {
// 	char	**result;

// 	printf("Input: \"%s\" (delimiter: '%c')\n", s, c);
// 	result = ft_split(s, c);
// 	print_split(result);
// 	free_split(result);
// 	printf("--------------------------------\n");
// }

// int	main(void)
// {
// 	test_split("hello world", ' ');
// 	test_split("a,,b,c", ',');
// 	test_split(",a,b,c,", ',');
// 	test_split("no_separator", ',');
// 	test_split(",,,", ',');
// 	test_split("", ',');
// 	return (0);
// }
