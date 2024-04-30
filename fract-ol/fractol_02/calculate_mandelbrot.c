/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_mandelbrot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:18:59 by welyousf          #+#    #+#             */
/*   Updated: 2024/04/23 12:00:27 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_conv_dive(t_fractol *var)
{
	var->i = 0;
	while (var->i < 200)
	{
		var->tmp = (var->zx * var->zx) - (var->zy * var->zy) + var->cx;
		var->zy = 2 * var->zy * var->zx + var->cy;
		var->zx = var->tmp;
		if (((var->zx * var->zx) + (var->zy * var->zy)) > 8)
			break ;
		var->i++;
	}
	return (var->i);
}

void	from_window_to_grid(t_fractol *var)
{
	var->cx = ((var->x - 122 + var->x_offset) * 2 / var->zoom);
	var->cy = ((var->y - var->y_offset) * 2 / var->zoom);
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
