/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_int_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 04:10:38 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/20 04:10:58 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	compute_int_max(void)
{
	int	max;

	max = 0;
	max = (~max) ^ (1 << (sizeof(int) * 8 - 1));
	return (max);
}
