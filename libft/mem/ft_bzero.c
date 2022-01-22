/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:37:29 by iguidado          #+#    #+#             */
/*   Updated: 2021/12/19 14:12:36 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned long	*longword_ptr;
	unsigned int	i;

	i = -1;
	while (++i < n % 8)
		((unsigned char *)s)[i] = 0;
	longword_ptr = (unsigned long *)(s + i);
	while (i < n)
	{
		*longword_ptr = 0;
		longword_ptr++;
		i += 8;
	}
}
