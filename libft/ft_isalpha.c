/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:27:38 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/10 10:39:49 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

int	ft_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

int	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
