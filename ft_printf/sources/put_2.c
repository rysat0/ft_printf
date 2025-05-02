/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:40:29 by rysato            #+#    #+#             */
/*   Updated: 2025/05/02 21:02:06 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int put_out_smallx(unsigned int num)
{
	char *base;
	base = "0123456789abcdef";
	if(num >= 16)
		put_out_smallx(num / 16)

	"base[num % 16]"
}
