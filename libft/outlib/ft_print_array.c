/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:40:26 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/19 19:59:12 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(array[i]);
		if (!(i % 10) && i)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		i++;
	}
}
