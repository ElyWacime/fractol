/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_mandelbrot_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:18:59 by welyousf          #+#    #+#             */
/*   Updated: 2024/04/27 22:51:49 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	check_conv_dive(t_fractol *var)
{
	var->i = 0;
	while (var->i < 200)
	{
		var->tmp = (var->zx * var->zx) - (var->zy * var->zy) + var->cx;
		var->zy = (2 * var->zy * var->zx) + var->cy;
		var->zx = var->tmp;
		if (((var->zx * var->zx) + (var->zy * var->zy)) > 8)
			break ;
		var->i++;
	}
	return (var->i);
}

void	from_window_to_grid(t_fractol *var)
{
	var->cx = (var->x / 1000) * (var->majal_xb - var->majal_xa) + var->majal_xa;
	var->cy = (var->y / 1000) * (var->majal_yb - var->majal_ya) + var->majal_ya;
}

void	from_window_to_grid_mandel_mouse(t_fractol *var)
{
	var->mouse_xx = ((var->mouse_x / 1000) * (var->majal_xb - var->majal_xa))
		+ var->majal_xa;
	var->mouse_yy = ((var->mouse_y / 1000) * (var->majal_yb - var->majal_ya))
		+ var->majal_ya;
}

void	calculate_mandelbrot(t_fractol *var)
{
	var->title = "Mandelbort";
	var->win_ptr = mlx_new_window(var->mlx_ptr, 1000, 1000, var->title);
	if (var->win_ptr == NULL)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		free(var->win_ptr);
		free(var->mlx_ptr);
		return ;
	}
	design_mendel_img(var);
}

void	design_mendel_img(t_fractol *var)
{
	create_image(var);
	var->x = 0;
	while (var->x < 1000)
	{
		var->y = 0;
		while (var->y < 1000)
		{
			var->zx = 0;
			var->zy = 0;
			from_window_to_grid(var);
			var->i = check_conv_dive(var);
			if (var->i == 200)
				upgraded_mlx_pixel_put(&var->img, var->x, var->y, 0);
			else
				upgraded_mlx_pixel_put(&var->img, var->x, var->y,
					calculate_color(var));
			var->y++;
		}
		var->x++;
	}
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img.img_ptr, 0, 0);
}
