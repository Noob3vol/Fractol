/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:02:09 by iguidado          #+#    #+#             */
/*   Updated: 2021/12/21 12:02:10 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_free_render(t_env *env)
{
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	exit(EXIT_SUCCESS);
	return (0);
}
