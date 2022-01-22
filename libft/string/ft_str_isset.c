/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:51:40 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/29 23:27:53 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_isset(char *str, char *set)
{
	if (!str || !set)
		return (0);
	if (!*str || !*set)
		return (0);
	while (*str)
	{
		if (ft_strindex(set, *str) < 0)
			return (0);
		str++;
	}
	return (1);
}
