/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:50:38 by rysato            #+#    #+#             */
/*   Updated: 2025/04/30 17:15:56 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*loc;

	loc = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			loc = (char *)s;
		s++;
	}
	if (*s == '\0' && (char)c == '\0')
		return ((char *)s);
	return (loc);
}
