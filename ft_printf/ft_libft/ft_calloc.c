/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:49:53 by rysato            #+#    #+#             */
/*   Updated: 2025/04/30 18:04:44 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	entire;
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		if (ptr == NULL)
			return (NULL);
		return (ft_memset(ptr, 0, 1));
	}
	if (size < 1 || nmemb > SIZE_MAX / size)
		return (NULL);
	entire = nmemb * size;
	ptr = malloc(entire);
	if (ptr == NULL)
		return (NULL);
	return (ft_memset(ptr, 0, entire));
}
