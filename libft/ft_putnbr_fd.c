/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:58:17 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/06/27 16:31:42 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_num(int n, int fd)
{
	if (n == 0)
		return ;
	ft_put_num(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2", fd);
		n = 147483648;
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
	ft_put_num(n, fd);
	return ;
}
