/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:01:50 by iguidado          #+#    #+#             */
/*   Updated: 2022/01/02 07:19:09 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_button_press(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (button == M_LEFTCLICK)
	{
		env->toggle_julia ^= 1;
	}
	else if (button == M_UPWHEEL)
		env->zoom *= 0.9;
	else if (button == M_DOWNWHEEL)
		env->zoom *= 1.1;
	return (0);
}

int	ft_mouse_coord(int x, int y, t_env *env)
{
	if (env->toggle_julia)
	{
		if (x >= 0 && x <= WIDTH)
			env->mouse_x = (float)x;
		if (y >= 0 && y <= HEIGHT)
			env->mouse_y = (float)y;
	}
	return (0);
}

int	ft_input(int keynum, t_env *env)
{
	float	offset;

	if (keynum == 0xff1b)
	{
		ft_free_render(env);
		exit(1);
	}
	else if (keynum >= K_LEFTARROW && keynum <= K_DOWNARROW)
	{
		offset = keynum % K_LEFTARROW - 1;
		if (keynum % 2)
			env->x_offset += offset * env->zoom;
		else
			env->y_offset += (offset - 1) * env->zoom;
	}
	return (0);
}
