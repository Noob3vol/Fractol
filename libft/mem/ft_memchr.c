/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:53:51 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/19 18:58:51 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_trlt;

	s_trlt = (unsigned char *)s;
	while (n)
	{
		if (*s_trlt == (unsigned char)c)
			return ((void *)s_trlt);
		s_trlt++;
		n--;
	}
	return (NULL);
}
