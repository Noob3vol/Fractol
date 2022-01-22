/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 07:48:14 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/20 18:25:59 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	*ft_clear_lst(t_list *l, t_list *last, void (*del)(void *))
{
	t_list	*next;

	next = NULL;
	while (l != last)
	{
		next = l->next;
		del(l->content);
		free(l);
		l = NULL;
		l = next;
	}
	del(l->content);
	free(l);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*crawl;

	if (!lst)
		return (NULL);
	new = NULL;
	crawl = NULL;
	(void)del;
	new = (t_list *)malloc(sizeof(t_list));
	if (!(new))
		return (NULL);
	new->content = f(lst->content);
	new->next = NULL;
	crawl = new;
	while (lst->next)
	{
		lst = lst->next;
		(crawl->next) = (t_list *)malloc(sizeof(t_list));
		if (!(crawl->next))
			return (ft_clear_lst(new, crawl, del));
		crawl = crawl->next;
		crawl->content = f(lst->content);
	}
	crawl->next = NULL;
	return (new);
}
