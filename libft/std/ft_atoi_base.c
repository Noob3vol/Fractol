/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:21:04 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/20 18:20:14 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define ERROR_BASELEN -1
#define ERROR_BASECHAR -2

static int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || !base[i] || !base[i + 1])
		return (ERROR_BASELEN);
	j = -1;
	while (base[++j])
		if (base[j] == ' ' || base[j] == '+' || base[j] == '-')
			return (ERROR_BASECHAR);
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (ERROR_BASECHAR);
			j++;
		}
		i++;
	}
	return (j);
}

static int	ft_process_sign(const char **str)
{
	int	neg;

	neg = 1;
	while (**str == ' ' || **str == '-' || **str == '+')
	{
		if (**str == '-')
			neg *= -1;
		(*str)++;
	}
	return (neg);
}

int	ft_atoi_base(const char *str, char *base)
{
	int	neg;
	int	base_len;
	int	nbr;
	int	digit;

	base_len = ft_check_base(base);
	if ((base_len) < 0)
		return (base_len);
	nbr = 0;
	neg = ft_process_sign(&str);
	digit = ft_strindex(base, *str);
	while (*str && ((digit) > -1))
	{
		nbr *= base_len;
		nbr += digit;
		str++;
		digit = ft_strindex(base, *str);
	}
	return (nbr * neg);
}
