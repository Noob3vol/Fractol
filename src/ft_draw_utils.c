/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:17:55 by iguidado          #+#    #+#             */
/*   Updated: 2022/01/02 11:14:19 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixel(int *img, unsigned int x, unsigned int y, int color)
{
	img[y * WIDTH + x] = color;
}

int	ft_get_color(t_env *env, unsigned int count)
{
	static int	colorpal[] = {
		0x264653, 0x2a9d8f, 0xe9c46a,
		0xf4a261, 0xe76f51, -1
	};
	float		scale;
	int			pal_len;

	scale = (float)count / (float)env->count_max;
	pal_len = 0;
	while (colorpal[pal_len] != -1)
		pal_len++;
	return (colorpal[(int)(scale * (float)(pal_len))]);
}

/*
**	void	ft_paint_pixel(t_env *env, unsigned int *coord, int count, int *colrpal)
**	{
**		int	i;
**		int	color_sample;
**	
**		i = 0;
**		if (!colrpal)
**		{
**			color_sample = (float)0xFFFFFF * (float)count / (float)env->count_max;
**		}
**		while (colrpal[i] >= 0)
**			i++;
**		color_sample = colrpal[(float)count / (float)count_max * i];
**		ft_put_pixel(env->img, coord[0], coord[1], color_sample);
**	}
*/
