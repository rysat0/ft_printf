/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:50:26 by rysato            #+#    #+#             */
/*   Updated: 2025/04/30 17:05:15 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// dstのケツにsrcを結合
// dstsizeがdst+src+1以上で完全結合
//それ以外はnull分を残して結合
//最後null
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	available;
	size_t	dlen;
	size_t	slen;

	i = 0;
	dlen = 0;
	slen = 0;
	while (dst[dlen] != '\0' && dlen < dstsize)
		dlen++;
	slen = ft_strlen(src);
	if (dlen == dstsize)
		return (dlen + slen);
	available = dstsize - dlen - 1;
	while (i < available && src[i] != '\0')
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
