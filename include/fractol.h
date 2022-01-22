/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 07:35:41 by iguidado          #+#    #+#             */
/*   Updated: 2022/01/11 03:07:25 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/X.h>
# include "mlx.h"
# include "math.h"
# include "libft.h"
# include <stdio.h>

# include <stdlib.h>
# include <errno.h>

# define WIDTH 1200
# define HEIGHT 600
# define TITLE "Fract'ol"

# define K_LEFTARROW                     0xFF51 
# define K_UPARROW                        0xFF52
# define K_RIGHTARROW                     0xFF53
# define K_DOWNARROW                      0xFF54 
# define M_UPWHEEL		5
# define M_DOWNWHEEL		4
# define M_LEFTCLICK		1

# define RE_START			-2
# define RE_END				1
# define IM_START			-1
# define IM_END				1
# define ITER_MAX			50

enum	e_fractals
{
	E_MANDELBROT,
	E_JULIA,
	E_BURNINGSHIP,
	E_MAX
};

typedef struct s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*layout;
	int				*lay_cpy;
	unsigned int	width;
	unsigned int	height;
	char			fractal_id;
	unsigned int	count_max;
	float			zoom;
	float			x_offset;
	float			y_offset;
	int				color_offset;
	float			re_start;
	float			re_end;
	float			im_start;
	float			im_end;
	float			mouse_x;
	float			mouse_y;
	t_bool			toggle_julia;
}				t_env;

typedef struct s_fcomplex
{
	float	real;
	float	irreal;
}				t_fcomplex;

/*
**	draw	Utils
*/
void	ft_put_pixel(int *img, unsigned int x, unsigned int y, int color);
int		ft_get_color(t_env *env, unsigned int count);

/*
**  Setup environnement
*/
int		ft_setup_env(t_env *env, int argc, char **argv);
void	ft_place_bounds(t_env *env, int mask);

/*
** Rendering
*/
int		ft_fractol(t_env *env, t_fcomplex c, t_fcomplex z, unsigned int count);
int		ft_render_julia(t_env *env, unsigned int x, unsigned int y);
int		ft_render_mandelbrot(t_env *env, unsigned int x, unsigned int y);
int		ft_render_fractal(t_env *env);

/*
** Manage event
*/
int		ft_input(int keynum, t_env *env);
int		ft_release_input(int keycode, void *param);
int		ft_mouse_coord(int x, int y, t_env *env);

int		ft_button_press(int button, int x, int y, t_env *env);
int		ft_button_release(int button, int x, int y, t_env *env);
/*
** Manage event
*/
int		ft_key_manage(t_env *env);

int		ft_free_render(t_env *env);

#endif
