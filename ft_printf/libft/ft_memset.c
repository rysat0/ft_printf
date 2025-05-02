/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:50:20 by rysato            #+#    #+#             */
/*   Updated: 2025/04/28 18:55:14 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int fill, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)buf)[i] = (char)fill;
		i++;
	}
	return (buf);
}
//元はsize_t
// 32bitでunsigned int,64bitでunsigned long
