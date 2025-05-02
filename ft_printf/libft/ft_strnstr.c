/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:50:36 by rysato            #+#    #+#             */
/*   Updated: 2025/04/28 18:55:49 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t				i;
	size_t				j;
	const unsigned char	*data;
	const unsigned char	*word;

	data = (const unsigned char *)haystack;
	word = (const unsigned char *)needle;
	j = 0;
	if (*word == '\0')
		return ((char *)data);
	while (j < len && data[j] != '\0')
	{
		i = 0;
		while (data[j + i] == word[i] && (j + i) < len && word[i] != '\0')
			i++;
		if (word[i] == '\0')
			return ((char *)(data + j));
		j++;
	}
	return (NULL);
}
