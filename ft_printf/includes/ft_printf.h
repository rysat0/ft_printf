/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:04:46 by rysato            #+#    #+#             */
/*   Updated: 2025/05/05 16:38:47 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# include "../libft/libft.h"

int	ft_printf(const char *format, ...);
int	put_out_c(int c);
int	put_out_s(char *str);
int	put_out_p(void *ptr);
int	put_out_int(int num);
int	put_out_u(unsigned int num);
int	put_out_smallx(unsigned int num);
int	put_out_largex(unsigned int num);
int	put_out_per(void);

#endif
