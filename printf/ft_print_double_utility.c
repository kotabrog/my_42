/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double_utility.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:12:31 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/24 10:40:53 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_double_arr(int arr[BUF], int *n)
{
	int i;

	i = 0;
	while (i < *n + 1)
	{
		arr[BUF - 1 - i] *= 2;
		if (i != 0 && arr[BUF - 1 - (i - 1)] >= 10)
		{
			arr[BUF - 1 - i] += arr[BUF - 1 - (i - 1)] / 10;
			arr[BUF - 1 - (i - 1)] %= 10;
			if (i == *n)
				(*n)++;
		}
		i++;
	}
}

void	ft_halve_arr(int arr[BUF], int n)
{
	int i;

	i = 0;
	while (i <= n)
	{
		if (arr[i] % 2)
			arr[i + 1] += 10;
		arr[i++] /= 2;
	}
}

void	ft_add_arr(int arr[BUF], int ans[BUF], int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ans[BUF - 1 - i] += arr[n - i];
		if (ans[BUF - 1 - i] >= 10)
		{
			ans[BUF - 1 - (i + 1)] += ans[BUF - 1 - i] / 10;
			ans[BUF - 1 - i] %= 10;
		}
		i++;
	}
}

void	ft_add_arr2(int arr[BUF], int ans[BUF], int *n, int start)
{
	int i;

	i = 0;
	while (i < *n)
	{
		ans[BUF - 1 - i - start] += arr[BUF - 1 - i];
		if (ans[BUF - 1 - i - start] >= 10)
		{
			ans[BUF - 1 - (i + 1) - start] += ans[BUF - 1 - i - start] / 10;
			ans[BUF - 1 - i - start] %= 10;
			if (i == *n - 1)
				(*n)++;
		}
		i++;
	}
}

void	ft_reset_arr(int *arr, int n)
{
	while (--n >= 0)
		arr[n] = 0;
}
