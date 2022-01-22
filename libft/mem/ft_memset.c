/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:29:01 by iguidado          #+#    #+#             */
/*   Updated: 2022/01/11 02:31:46 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned long	*longword_ptr;
	unsigned long	magicbit;
	unsigned char	ch;
	unsigned int	i;

	ch = (unsigned char)c;
	magicbit = (~0UL / 255) * (unsigned char)c;
	i = -1;
	while (++i < n % 8)
		((unsigned char *)ptr)[i] = ch;
	longword_ptr = (unsigned long *)(ptr + i);
	while (i < n)
	{
		*longword_ptr++ = magicbit;
		i += 8;
	}
	return (ptr);
}

/*
 **	void	*ft_memset(void *b, int c, size_t len)
 **	{
 **		unsigned char	*new;
 **	
 **		new = b;
 **		while (len > 1)
 **		{
 **			new[len - 1] = (unsigned char)c;
 **			len--;
 **		}
 **		if (len)
 **			new[0] = (unsigned char)c;
 **		return (b);
 **	}
 */

/*
 **	void	*ft_print_memory(void *addr, int size);
 **	int	main(void)
 **	{
 **		int c;
 **		size_t size;
 **		char lol;
 **		void *ptr;
 **
 **		ptr = &lol;
 **		size = 5;
 **		c = 'A';
 **		ft_memset(ptr, c, size);
 **		ft_print_memory(ptr, 6);
 **		return (0);
 **	}
 */
