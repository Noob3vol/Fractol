/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:26:03 by iguidado          #+#    #+#             */
/*   Updated: 2021/12/19 13:47:11 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp_end(char *str, char *end)
{
	int	i;
	int	j;

	i = ft_strlen(str);
	j = ft_strlen(end);
	while (i > 0 && j > 0 && str[i] == end[j])
	{
		i--;
		j--;
	}
	return (str[i] - end[j]);
}
