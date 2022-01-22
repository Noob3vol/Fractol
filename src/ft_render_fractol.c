/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_fractol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:03:57 by iguidado          #+#    #+#             */
/*   Updated: 2022/01/11 02:41:38 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_render_julia(t_env *env, unsigned int x, unsigned int y)
{
	static t_fcomplex	c;
	t_fcomplex			z;
	float				scale;

	scale = (float)x / (float)WIDTH;
	z.real = env->x_offset + env->re_start * env->zoom
		+ (env->re_end - env->re_start) * scale * env->zoom;
	scale = (float)y / (float)HEIGHT;
	z.irreal = env->y_offset + env->im_start * env->zoom
		+ (env->im_end - env->im_start) * scale * env->zoom;
	if (env->toggle_julia)
	{
		c.real = ((env->mouse_x / (float)WIDTH) - 0.5) * 4.0;
		c.irreal = ((env->mouse_y / (float)HEIGHT) - 0.5) * 4.0;
	}
	return (ft_fractol(env, c, z, 0));
}

int	ft_render_mandelbrot(t_env *env, unsigned int x, unsigned int y)
{
	t_fcomplex		z;
	t_fcomplex		c;
	float			scale;
	unsigned int	count;

	count = 0;
	z.real = 0;
	z.irreal = 0;
	scale = (float)x / (float)WIDTH;
	c.real = env->x_offset + env->re_start * env->zoom
		+ scale * (env->re_end - env->re_start) * env->zoom;
	scale = (float)y / (float)HEIGHT;
	c.irreal = env->y_offset + env->im_start * env->zoom
		+ scale * (env->im_end - env->im_start) * env->zoom;
	return (ft_fractol(env, c, z, 0));
}

/*
**	
**	int	ft_blend_color(int color, int new_color)
**	{
**		if (new_color < 0)
**			return (color);
**		if (color < 0)
**			return (new_color);
**		color = (color + new_color) / 2;
**		return (color);
**	}
**	
**
**	int	ft_get_pix(int *layout, int x, int y)
**	{
**		if (x < 0 || x >= WIDTH)
**			return (-1);
**		if (y < 0 || y >= HEIGHT)
**			return (-1);
**		return (layout[x + y * WIDTH]);
**	}
**	void	ft_interp(int *cpy, int *lay)
**	{
**		int	x;
**		int	y;
**		int	*pix;
**	
**		y = 0;
**		while (y < HEIGHT)
**		{
**			x = 0;
**			while (x < WIDTH)
**			{
**				pix = &cpy[x + y * WIDTH];
**				*pix = -1;
**				*pix = ft_blend_color(*pix, ft_get_pix(lay, x - 1, y - 1));
**				*pix = ft_blend_color(*pix, ft_get_pix(lay, x, y - 1));
**				*pix = ft_blend_color(*pix, ft_get_pix(lay, x + 1, y - 1));
**				*pix = ft_blend_color(*pix, ft_get_pix(lay, x - 1, y));
**				*pix = ft_blend_color(*pix, ft_get_pix(lay, x, y + 1));
**				*pix = ft_blend_color(*pix, ft_get_pix(lay, x - 1, y + 1));
**				*pix = ft_blend_color(*pix, ft_get_pix(lay, x + 1, y));
**				*pix = ft_blend_color(*pix, ft_get_pix(lay, x + 1, y + 1));
**				x++;
**			}
**			y++;
**		}
**	}
*/

int	ft_render_fractal(t_env *env)
{
	static int			(*fractal_funcs[E_MAX])(t_env *env,
			unsigned int x, unsigned int y) = {
	[E_MANDELBROT] = &ft_render_mandelbrot,
	[E_JULIA] = &ft_render_julia,
	[E_BURNINGSHIP] = &ft_render_mandelbrot
	};
	unsigned int		x;
	unsigned int		y;
	unsigned int		color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = fractal_funcs[(int)env->fractal_id](env, x, y);
			ft_put_pixel(env->layout, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

int	ft_fractol(t_env *env, t_fcomplex c, t_fcomplex z, unsigned int count)
{
	t_fcomplex	z_tmp;

	if (count >= env->count_max)
		return (0);
	if (env->fractal_id == E_BURNINGSHIP)
	{
		z.real = fabs(z.real);
		z.irreal = fabs(z.irreal);
	}
	z_tmp.real = z.real * z.real - z.irreal * z.irreal + c.real;
	z_tmp.irreal = 2 * z.real * z.irreal + c.irreal;
	if (z.real * z.real + z.irreal * z.irreal >= 4)
		return (ft_get_color(env, count));
	return (ft_fractol(env, c, z_tmp, count + 1));
}
