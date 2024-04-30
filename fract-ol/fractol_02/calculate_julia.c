/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_julia.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:03:32 by welyousf          #+#    #+#             */
/*   Updated: 2024/04/29 13:13:02 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_conv_dive_julia(t_fractol *var)
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

void	from_window_to_grid_julia(t_fractol *var)
{
	var->zx = ((var->x + var->x_offset) * 2 / var->zoom);
	var->zy = ((var->y - var->y_offset) * 2 / var->zoom);
}

void	design_julia_img(t_fractol *var)
{
	create_image(var);
	var->x = -500;
	while (var->x < 500)
	{
		var->y = -500;
		while (var->y < 500)
		{
			from_window_to_grid_julia(var);
			var->i = check_conv_dive(var);
			if (var->i == 0)
				var->i = 1;
			if (var->i == 200)
				upgraded_mlx_pixel_put(&var->img, var->x + 500, var->y + 500,
					0x000000);
			else
				upgraded_mlx_pixel_put(&var->img, var->x + 500, var->y + 500,
					var->color / var->i);
			var->y++;
		}
		var->x++;
	}
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img.img_ptr, 0, 0);
}

void	calculate_julia(t_fractol *var, int ac, char **av)
{
	if (ac == 4)
	{
		var->cx = ft_atoi(av[2]);
		var->cy = ft_atoi(av[3]) * (-1);
	}
	var->title = "Julia";
	var->win_ptr = mlx_new_window(var->mlx_ptr, 1000, 1000, var->title);
	if (var->win_ptr == NULL)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		free(var->win_ptr);
		free(var->mlx_ptr);
		return ;
	}
	design_julia_img(var);
}
