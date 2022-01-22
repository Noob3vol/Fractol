/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_countc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:55:22 by iguidado          #+#    #+#             */
/*   Updated: 2021/12/19 13:46:30 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_countc(char *str, char c)
{
	int	count;

	count = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}
