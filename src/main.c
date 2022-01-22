/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:58:02 by iguidado          #+#    #+#             */
/*   Updated: 2021/12/21 13:58:04 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
	{
		ft_putendl_fd("Usage : ./fractol [Mandelbrot/Julia/BurningShip]", 2);
		return (1);
	}
	if (!ft_setup_env(&env, argc, argv))
		return (-1);
	ft_place_bounds(&env, env.fractal_id);
	mlx_hook(env.win, DestroyNotify, StructureNotifyMask,
		&ft_free_render, &env);
	mlx_hook(env.win, KeyPress, KeyPressMask, &ft_input, &env);
	mlx_hook(env.win, MotionNotify, PointerMotionMask, &ft_mouse_coord, &env);
	mlx_hook(env.win, ButtonPress, ButtonPressMask, &ft_button_press, &env);
	mlx_loop_hook(env.mlx, &ft_render_fractal, &env);
	mlx_loop(env.mlx);
	ft_free_render(&env);
	return (0);
}
