/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:45:37 by iguidado          #+#    #+#             */
/*   Updated: 2021/12/19 13:45:39 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_quickpivot(int **tab, int begin, int end, int pivot)
{
	int	i;
	int	j;

	i = begin;
	if (pivot != end)
		ft_swapi(&(*tab)[pivot], &(*tab)[end]);
	while (i != end)
	{
		if ((*tab)[i] > (*tab)[end])
		{
			j = i;
			while ((*tab)[j] > (*tab)[end])
				j++;
			if (j != end)
				ft_swapi(&(*tab)[i], &(*tab)[j]);
		}
		i++;
	}
	i = begin;
	while ((*tab)[i] < (*tab)[end])
		i++;
	if (i != end)
		ft_swapi(&(*tab)[i], &(*tab)[end]);
	return (i);
}

int	*ft_quicksort(int *tab, int begin, int end)
{
	int	pivot;
	int	middle;

	if (end <= begin)
		return (tab);
	middle = (begin + end) / 2;
	pivot = ft_median_of_3_tab(tab, begin, (begin + end) / 2, end);
	pivot = ft_quickpivot(&tab, begin, end, pivot);
	ft_quicksort(tab, begin, pivot - 1);
	ft_quicksort(tab, pivot + 1, end);
	return (tab);
}
