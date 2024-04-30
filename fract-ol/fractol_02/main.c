/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:18:55 by welyousf          #+#    #+#             */
/*   Updated: 2024/04/29 19:46:55 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	t_parsing	var;

	var.usage = "[+] Usage: <./app> + <mandelbrot/julia>\n";
	write(1, var.usage, ft_strlen(var.usage));
	var.usage = "[+] In casse of julia set: <./app> <julia> <x> <y>\n";
	write(1, var.usage, ft_strlen(var.usage));
	var.usage = "\n	##################\n\n";
	write(1, var.usage, ft_strlen(var.usage));
	var.usage = "[+] To zoom in and out use the mouse weel\n";
	write(1, var.usage, ft_strlen(var.usage));
}

void	run_julia(int ac, char **av)
{
	t_fractol	var;

	var.mlx_ptr = mlx_init();
	if ((var.mlx_ptr) == NULL)
		return ;
	var.color = 0x111111;
	var.zoom = 500;
	var.x_offset = 0;
	var.y_offset = 0;
	calculate_julia(&var, ac, av);
	mlx_mouse_hook(var.win_ptr, recieve_mouse_julia, &var);
	mlx_hook(var.win_ptr, 3, 0, ft_close, &var);
	mlx_hook(var.win_ptr, 17, 0, ft_close_17, &var);
	mlx_loop(var.mlx_ptr);
}

void	run_mandelbrot(void)
{
	t_fractol	var;

	var.mlx_ptr = mlx_init();
	if ((var.mlx_ptr) == NULL)
		return ;
	var.color = 0x111111;
	var.zoom = 500;
	var.x_offset = 0;
	var.y_offset = 0;
	calculate_mandelbrot(&var);
	mlx_mouse_hook(var.win_ptr, recieve_mouse, &var);
	mlx_hook(var.win_ptr, 3, 0, ft_close, &var);
	mlx_hook(var.win_ptr, 17, 0, ft_close_17, &var);
	mlx_loop(var.mlx_ptr);
}

int	main(int ac, char **av)
{
	if (ac != 2 && ac != 4)
	{
		usage();
		return (0);
	}
	else if (!ft_strncmp(av[1], "julia", 5) && ac == 4)
	{
		if (check_args(av[2]) * check_args(av[3]) == 0)
		{
			usage();
			return (0);
		}
		run_julia(ac, av);
	}
	else if (!ft_strncmp(av[1], "mandelbrot", 10))
		run_mandelbrot();
	else
		usage();
	return (0);
}
