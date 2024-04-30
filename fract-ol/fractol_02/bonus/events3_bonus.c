/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:49:21 by welyousf          #+#    #+#             */
/*   Updated: 2024/04/30 10:21:59 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	change_color(t_fractol *var)
{
	static int	i;

	if (i < 10)
	{
		var->color += 0x111111;
		i += 1;
	}
	else
	{
		var->color -= (0x111111 * 10);
		i = 0;
	}
}

void	listen_to_events_ship_1(int keycode, t_fractol *var)
{
	if (keycode == 123)
	{
		var->tmp = var->majal_xa;
		var->majal_xa += 0.1 * (var->majal_xb - var->majal_xa);
		var->majal_xb += 0.1 * (var->majal_xb - var->tmp);
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_ship(var);
	}
	else if (keycode == 124)
	{
		var->tmp = var->majal_xa;
		var->majal_xa -= 0.1 * (var->majal_xb - var->majal_xa);
		var->majal_xb -= 0.1 * (var->majal_xb - var->tmp);
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_ship(var);
	}
	else if (keycode == 8)
	{
		var->r1 = random() % 2;
		var->r2 = random() % 2;
		var->r3 = random() % 2;
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_ship(var);
	}
}

void	listen_to_events_madelbrot_1(int keycode, t_fractol *var)
{
	if (keycode == 123)
	{
		var->tmp = var->majal_xa;
		var->majal_xa += 0.1 * (var->majal_xb - var->majal_xa);
		var->majal_xb += 0.1 * (var->majal_xb - var->tmp);
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_mendel_img(var);
	}
	else if (keycode == 124)
	{
		var->tmp = var->majal_xa;
		var->majal_xa -= 0.1 * (var->majal_xb - var->majal_xa);
		var->majal_xb -= 0.1 * (var->majal_xb - var->tmp);
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_mendel_img(var);
	}
	else if (keycode == 8)
	{
		var->r1 = random() % 2;
		var->r2 = random() % 2;
		var->r3 = random() % 2;
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_mendel_img(var);
	}
}

void	listen_to_events_julia_1(int keycode, t_fractol *var)
{
	if (keycode == 123)
	{
		var->tmp = var->majal_xa;
		var->majal_xa += 0.1 * (var->majal_xb - var->majal_xa);
		var->majal_xb += 0.1 * (var->majal_xb - var->tmp);
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_julia_img(var);
	}
	else if (keycode == 124)
	{
		var->tmp = var->majal_xa;
		var->majal_xa -= 0.1 * (var->majal_xb - var->majal_xa);
		var->majal_xb -= 0.1 * (var->majal_xb - var->tmp);
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_julia_img(var);
	}
	else if (keycode == 8)
	{
		var->r1 = random() % 2;
		var->r2 = random() % 2;
		var->r3 = random() % 2;
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_julia_img(var);
	}
}

size_t	calculate_color(t_fractol *var)
{
	if (var->r1 == 0 && var->r2 == 0 && var->r3 == 0)
	{
		var->r1 = 1;
		var->r2 = 1;
	}
	var->color = ((16 * (255 * var->i) / var->max_itter) % 255);
	return ((var->color * var->r1) + ((var->color * var->r2) * 256)
		+ ((var->color * var->r3) * 256 * 256));
}
