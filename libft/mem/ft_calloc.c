/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:03:39 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/19 16:34:32 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*newstr;
	size_t	i;

	if (!count || !size)
		return (newstr = (char *)malloc(1));
	newstr = (char *)malloc(count * size);
	if (!(newstr))
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		newstr[i] = 0;
		i++;
	}
	return ((void *)newstr);
}
