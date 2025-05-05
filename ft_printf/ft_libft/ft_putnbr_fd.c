/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:08:53 by rysato            #+#    #+#             */
/*   Updated: 2025/04/29 17:15:53 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// #include <fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	output;
	long	num;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd((num / 10), fd);
	output = (num % 10) + '0';
	write(fd, &output, 1);
}

// void test_putnbr_fd(int n, int fd, const char *desc)
// {
// 	printf("Test: %s\n", desc);
// 	printf("Expected output: %d\n", n);
// 	printf("Actual output:   ");
// 	ft_putnbr_fd(n, fd);
// 	write(fd, "\n", 1);
// 	printf("--------------------------------\n");
// }

// int	main(void)
// {
// 	// 標準出力
// 	test_putnbr_fd(12345, 1, "Positive number");
// 	test_putnbr_fd(-42, 1, "Negative number");
// 	test_putnbr_fd(0, 1, "Zero");
// 	test_putnbr_fd(2147483647, 1, "INT_MAX");
// 	test_putnbr_fd(-2147483648, 1, "INT_MIN");

// 	// 標準エラー出力
// 	write(2, "Standard error output:\n", 24);
// 	ft_putnbr_fd(999, 2);
// 	write(2, "\n", 1);

// 	// ファイル出力
// 	int fd = open("number_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd != -1)
// 	{
// 		write(1, "Writing to file: number_output.txt\n", 35);
// 		ft_putnbr_fd(123456789, fd);
// 		write(fd, "\n", 1);
// 		close(fd);
// 	}
// 	else
// 	{
// 		printf("Failed to open file.\n");
// 	}

// 	return (0);
// }
