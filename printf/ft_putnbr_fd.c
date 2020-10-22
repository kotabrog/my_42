/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:58:17 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/23 10:35:56 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_num(unsigned long long n, int fd, char *str)
{
	if (n == 0)
		return ;
	if (str == NULL)
		ft_put_num(n / 10, fd, str);
	else
		ft_put_num(n / 16, fd, str);
	if (str == NULL)
		ft_putchar_fd(n % 10 + '0', fd);
	else
		ft_putchar_fd(str[n % 16], fd);
}

void		ft_putnbr_fd(long long n, int fd)
{
	if (n == LLONG_MIN)
	{
		write(fd, "-9", 2);
		n = 223372036854775808;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	ft_put_num(n, fd, 0);
	return ;
}

void		ft_putnbr_fd_u(unsigned long long n, int fd, int mode)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (mode == 0)
		ft_put_num(n, fd, NULL);
	else if (mode == 1)
		ft_put_num(n, fd, "0123456789abcdef");
	else
		ft_put_num(n, fd, "0123456789ABCDEF");
	return ;
}
