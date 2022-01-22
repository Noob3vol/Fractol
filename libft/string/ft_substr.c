/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:20:27 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/20 18:05:10 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	str_l;
	size_t	sub_len;

	if (!str || !len)
		return (NULL);
	str_l = ft_strlen(str);
	if (start >= str_l)
		sub_len = 0;
	if (start + len >= str_l)
		sub_len = str_l - (size_t)start;
	else
		sub_len = len;
	sub = (char *)malloc(sub_len + 1);
	if (!(sub))
		return (NULL);
	return ((char *)ft_memcpy(sub, &str[start], sub_len));
}
/*
**	int	main(void)
**	{
**		char *sub;
**	
**		if(!(sub = ft_substr("0123456789", 5, 200)))
**		{
**			ft_putendl("Bad Allocation");
**		}
**		else
**			ft_putendl(sub);
**		ft_print_memory(sub, 20);
**		free(sub);
**		return (0);
**	}
*/
