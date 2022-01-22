/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median_of_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 04:11:01 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/20 04:11:20 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_median_of_3(int begin, int middle, int end)
{
	if ((begin < middle) ^ (begin < end))
		return (begin);
	if ((middle < begin) ^ (middle < end))
		return (middle);
	return (end);
}

int	ft_median_of_3_tab(int *tab, int begin, int middle, int end)
{
	if ((tab[begin] < tab[middle]) ^ (tab[begin] < tab[end]))
		return (begin);
	if ((tab[middle] < tab[begin]) ^ (tab[middle] < tab[end]))
		return (middle);
	return (end);
}
