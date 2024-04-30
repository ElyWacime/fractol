/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:19:05 by welyousf          #+#    #+#             */
/*   Updated: 2024/04/30 12:17:11 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	recieve_mouse(int button, int x, int y, t_fractol *var)
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
		design_mendel_img(var);
	}
	else if (button == 5)
	{
		from_window_to_grid_julia_mouse(var);
		var->majal_xa += (((var->mouse_xx) - (var->majal_xa)) / var->zoom);
		var->majal_ya += (((var->mouse_yy) - (var->majal_ya)) / var->zoom);
		var->majal_xb -= (var->majal_xb - var->mouse_xx) / var->zoom;
		var->majal_yb -= (var->majal_yb - var->mouse_yy) / var->zoom;
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_mendel_img(var);
	}
	return (0);
}

int	recieve_mouse_julia(int button, int x, int y, t_fractol *var)
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
		design_julia_img(var);
	}
	else if (button == 5)
	{
		from_window_to_grid_julia_mouse(var);
		var->majal_xa += (((var->mouse_xx) - (var->majal_xa)) / var->zoom);
		var->majal_ya += (((var->mouse_yy) - (var->majal_ya)) / var->zoom);
		var->majal_xb -= (var->majal_xb - var->mouse_xx) / var->zoom;
		var->majal_yb -= (var->majal_yb - var->mouse_yy) / var->zoom;
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_julia_img(var);
	}
	return (0);
}

int	ft_close(int keycode, t_fractol *var)
{
	if (keycode == 53)
	{
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		exit(0);
	}
	return (0);
}

int	ft_close_17(t_fractol *var)
{
	mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
	mlx_destroy_window(var->mlx_ptr, var->win_ptr);
	exit(0);
	return (0);
}

int	mouse_move_julia(int x, int y, t_fractol *var)
{
	if (x >= 0 && x <= 1000 & y >= 0 && y <= 1000)
	{
		var->mouse_x = x;
		var->mouse_y = y;
		if (var->mouse_on_off)
		{
			var->cx = ((var->mouse_x / 1000) * (var->majal_xb - var->majal_xa))
				+ var->majal_xa;
			var->cy = ((var->mouse_y / 1000) * (var->majal_yb - var->majal_ya))
				+ var->majal_ya;
			mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
			design_julia_img(var);
		}
	}
	return (0);
}
