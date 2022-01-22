/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:56:57 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/19 18:59:22 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;

	if (!n)
		return (0);
	s1_tmp = (unsigned char *)s1;
	s2_tmp = (unsigned char *)s2;
	while (--n && *s1_tmp == *s2_tmp)
	{
		s1_tmp++;
		s2_tmp++;
	}
	return (*s1_tmp - *s2_tmp);
}
