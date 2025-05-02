/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:50:18 by rysato            #+#    #+#             */
/*   Updated: 2025/05/02 13:40:32 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*copy_from_back(size_t i, size_t len, unsigned char *d,
		const unsigned char *s)
{
	i = len;
	while (i > 0)
	{
		i--;
		d[i] = s[i];
	}
	return (d);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (d > s)
		dst = copy_from_back(i, len, d, s);
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
