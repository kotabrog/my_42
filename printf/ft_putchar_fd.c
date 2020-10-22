/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:32:29 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/23 14:25:13 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putchar_re_fd(char c, int fd, int n)
{
	char	*p;
	int		i;

	if (n <= 0)
		return ;
	if ((p = (char *)malloc(sizeof(char) * n)) == NULL)
		return ;
	i = 0;
	while (i < n)
		p[i++] = c;
	write(fd, p, n);
	free(p);
}

int		ft_putchar_uni_next(wint_t c, int fd)
{
	char temp;

	if (c <= 0xFFFF)
	{
		temp = ((c & 0b1111000000000000) >> 12) | 0b11100000;
		write(fd, &temp, 1);
		temp = ((c & 0b0000111111000000) >> 6) | 0b10000000;
		write(fd, &temp, 1);
		temp = (c & 0b0000000000111111) | 0b10000000;
		write(fd, &temp, 1);
		return (3);
	}
	temp = ((c & 0b111000000000000000000) >> 18) | 0b11110000;
	write(fd, &temp, 1);
	temp = ((c & 0b000111111000000000000) >> 12) | 0b10000000;
	write(fd, &temp, 1);
	temp = ((c & 0b000000000111111000000) >> 6) | 0b10000000;
	write(fd, &temp, 1);
	temp = (c & 0b000000000000000111111) | 0b10000000;
	write(fd, &temp, 1);
	return (4);
}

int		ft_putchar_uni(wint_t c, int fd)
{
	char	temp;

	if (c <= 0x7F)
	{
		write(fd, &c, 1);
		return (1);
	}
	else if (c <= 0x7FF)
	{
		temp = ((c & 0b11111000000) >> 6) | 0b11000000;
		write(fd, &temp, 1);
		temp = (c & 0b00000111111) | 0b10000000;
		write(fd, &temp, 1);
		return (2);
	}
	else
		return (ft_putchar_uni_next(c, fd));
}
