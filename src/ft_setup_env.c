/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:57:00 by iguidado          #+#    #+#             */
/*   Updated: 2022/01/22 07:30:13 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "string.h"

int	parse_fractal(t_env *env, int argc, char **argv)
{
	static char		*names[E_MAX] = {
	[E_MANDELBROT] = "Mandelbrot",
	[E_JULIA] = "Julia",
	[E_BURNINGSHIP] = "Burningship"
	};
	unsigned int	i;

	i = 0;
	if (argc != 2)
		return (0);
	while (i < E_MAX)
	{
		if (ft_strncmp(argv[1], names[i], ft_strlen(names[i]) + 1) == 0)
		{
			env->fractal_id = (char)i;
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_place_bounds(t_env *env, int mask)
{
	float	*fractol_param;

	if (mask == E_MANDELBROT)
	{
		fractol_param = &(env->re_start);
		ft_memcpy(&(env->re_start),
			(float []){-2.19, 1.86, -1.15, 1.14}, sizeof(float) * 4);
	}
	else if (mask == E_JULIA)
	{
		env->re_end = 1.957858;
		env->re_start = -1.979132;
		env->im_end = 1.146398;
		env->im_start = -1.11841;
	}
	else if (mask == E_BURNINGSHIP)
	{
		env->re_end = 1.910770;
		env->im_end = 1.146398;
		env->re_start = -2.152622;
		env->im_start = -0.659259;
	}
}

int	ft_setup_mlx(void **mlx, void **win, void **img)
{
	*mlx = mlx_init();
	if (*mlx == NULL)
		return (0);
	*win = mlx_new_window(*mlx, WIDTH, HEIGHT, TITLE);
	if (*win == NULL)
	{
		mlx_destroy_display(*mlx);
		free(*mlx);
		return (0);
	}
	*img = mlx_new_image(*mlx, WIDTH, HEIGHT);
	if (*img == NULL)
	{
		mlx_destroy_window(*mlx, *win);
		mlx_destroy_display(*mlx);
		free(*mlx);
		return (0);
	}
	return (1);
}

int	ft_setup_env(t_env *env, int argc, char **argv)
{
	int	t;

	ft_bzero(env, sizeof(t_env));
	if (!parse_fractal(env, argc, argv))
	{
		ft_putstr_fd("Usage : ./fractol", 2);
		ft_putendl_fd("	[Mandelbrot/Julia/BurningShip]", 2);
		return (0);
	}
	if (!ft_setup_mlx(&env->mlx, &env->win, &env->img))
		return (0);
	env->layout = (int *)mlx_get_data_addr(env->img, &t, &t, &t);
	if (env->layout == NULL)
		return (0);
	env->count_max = ITER_MAX;
	env->toggle_julia = 1;
	env->zoom = 1.0;
	env->x_offset = 0;
	env->y_offset = 0;
	env->color_offset = 0x123425;
	return (1);
}
