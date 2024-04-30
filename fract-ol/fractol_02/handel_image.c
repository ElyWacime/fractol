/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:19:02 by welyousf          #+#    #+#             */
/*   Updated: 2024/04/29 13:13:55 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_image(t_fractol *var)
{
	var->img.height = 1000;
	var->img.width = 1000;
	var->img.img_ptr = mlx_new_image(var->mlx_ptr, var->img.height,
			var->img.width);
	if (var->img.img_ptr == NULL)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		exit(0);
	}
	var->img.img_pixels = mlx_get_data_addr(var->img.img_ptr, &var->img.bpp,
			&var->img.size_line, &var->img.endian);
}

void	upgraded_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->size_line) + (x * (img->bpp / 8));
	*(unsigned int *)(img->img_pixels + offset) = color;
}

void	replace_img(t_fractol *var)
{
	void	*tmp;

	tmp = var->img.img_ptr;
	design_mendel_img(var);
	mlx_destroy_image(var->mlx_ptr, tmp);
}

void	design_mendel_img(t_fractol *var)
{
	create_image(var);
	var->x = -500;
	while (var->x < 500)
	{
		var->y = -500;
		while (var->y < 500)
		{
			var->zx = 0;
			var->zy = 0;
			from_window_to_grid(var);
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
