/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 14:17:29 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/10 18:14:08 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *p;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		p = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = p;
	}
}
