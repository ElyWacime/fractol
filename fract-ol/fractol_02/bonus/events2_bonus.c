/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:45:38 by welyousf          #+#    #+#             */
/*   Updated: 2024/04/29 21:07:43 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	listen_to_events_ship(int keycode, t_fractol *var)
{
	if (keycode == 126)
	{
		var->tmp2 = var->majal_ya;
		var->majal_ya += 0.1 * (var->majal_yb - var->majal_ya);
		var->majal_yb += 0.1 * (var->majal_yb - var->tmp2);
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_ship(var);
	}
	else if (keycode == 125)
	{
		var->tmp2 = var->majal_ya;
		var->majal_ya -= 0.1 * (var->majal_yb - var->majal_ya);
		var->majal_yb -= 0.1 * (var->majal_yb - var->tmp2);
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_ship(var);
	}
	else
		listen_to_events_ship_1(keycode, var);
	return (0);
}

int	listen_to_events_madelbrot(int keycode, t_fractol *var)
{
	if (keycode == 126)
	{
		var->tmp2 = var->majal_ya;
		var->majal_ya += 0.1 * (var->majal_yb - var->majal_ya);
		var->majal_yb += 0.1 * (var->majal_yb - var->tmp2);
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_mendel_img(var);
	}
	else if (keycode == 125)
	{
		var->tmp2 = var->majal_ya;
		var->majal_ya -= 0.1 * (var->majal_yb - var->majal_ya);
		var->majal_yb -= 0.1 * (var->majal_yb - var->tmp2);
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_mendel_img(var);
	}
	else
		listen_to_events_madelbrot_1(keycode, var);
	return (0);
}

int	listen_to_events_julia(int keycode, t_fractol *var)
{
	if (keycode == 126)
	{
		var->tmp2 = var->majal_ya;
		var->majal_ya += 0.1 * (var->majal_yb - var->majal_ya);
		var->majal_yb += 0.1 * (var->majal_yb - var->tmp2);
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_julia_img(var);
	}
	else if (keycode == 125)
	{
		var->tmp2 = var->majal_ya;
		var->majal_ya -= 0.1 * (var->majal_yb - var->majal_ya);
		var->majal_yb -= 0.1 * (var->majal_yb - var->tmp2);
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_julia_img(var);
	}
	if (keycode == 9 || keycode == 15)
		reset(keycode, var);
	else
		listen_to_events_julia_1(keycode, var);
	return (0);
}

int	recieve_mouse_ship(int button, int x, int y, t_fractol *var)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		from_window_to_grid_julia_mouse(var);
		var->majal_xa -= (((var->mouse_xx) - (var->majal_xa)) / var->zoom);
		var->majal_ya -= (((var->mouse_yy) - (var->majal_ya)) / var->zoom);
		var->majal_xb += ((var->majal_xb) - (var->mouse_xx)) / var->zoom;
		var->majal_yb += ((var->majal_yb) - (var->mouse_yy)) / var->zoom;
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_ship(var);
	}
	else if (button == 5)
	{
		from_window_to_grid_julia_mouse(var);
		var->majal_xa += (((var->mouse_xx) - (var->majal_xa)) / var->zoom);
		var->majal_ya += (((var->mouse_yy) - (var->majal_ya)) / var->zoom);
		var->majal_xb -= (var->majal_xb - var->mouse_xx) / var->zoom;
		var->majal_yb -= (var->majal_yb - var->mouse_yy) / var->zoom;
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_ship(var);
	}
	return (0);
}
