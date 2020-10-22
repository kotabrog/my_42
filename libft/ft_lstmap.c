/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 14:35:52 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/06/28 16:05:29 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*q;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((p = ft_lstnew((*f)(lst->content))) == NULL)
		return (NULL);
	q = p;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if ((q->next = ft_lstnew((*f)(lst->content))) == NULL)
		{
			ft_lstclear(&p, del);
			return (NULL);
		}
		q = q->next;
	}
	return (p);
}
