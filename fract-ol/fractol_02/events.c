/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:19:05 by welyousf          #+#    #+#             */
/*   Updated: 2024/04/03 03:22:55 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	recieve_mouse(int button, int x, int y, t_fractol *var)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		var->zoom *= 1.1;
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_mendel_img(var);
	}
	else if (button == 5)
	{
		var->zoom /= 1.1;
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
		var->zoom *= 1.1;
		mlx_destroy_image(var->mlx_ptr, var->img.img_ptr);
		design_julia_img(var);
	}
	else if (button == 5)
	{
		var->zoom /= 1.1;
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
