/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:43:12 by welyousf          #+#    #+#             */
/*   Updated: 2024/04/30 12:10:09 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	usage(void)
{
	t_parsing	var;

	var.usage = "[+] Usage: <./app> + <mandelbrot/julia/ship>\n";
	write(1, var.usage, ft_strlen(var.usage));
	var.usage = "[+] In casse of julia set: <./app> <julia> <x> <y>\n";
	write(1, var.usage, ft_strlen(var.usage));
	var.usage = "[+] x and y must be valid floats";
	write(1, var.usage, ft_strlen(var.usage));
	var.usage = "\n\n	##################\n\n";
	write(1, var.usage, ft_strlen(var.usage));
	var.usage = "[+] To move left, right, up and down use the arrow keys\n";
	write(1, var.usage, ft_strlen(var.usage));
	var.usage = "[+] To zoom in and out use the mouse weel\n";
	write(1, var.usage, ft_strlen(var.usage));
	var.usage = "[+] To reset to the initial position click 'r'\n";
	write(1, var.usage, ft_strlen(var.usage));
	var.usage = "[+] To change the julia set using the mousse click 'v'\n";
	write(1, var.usage, ft_strlen(var.usage));
	var.usage = "[+] To change colors click 'c'\n";
	write(1, var.usage, ft_strlen(var.usage));
}

void	run_julia(int ac, char **av)
{
	t_fractol	var;

	var.mlx_ptr = mlx_init();
	if ((var.mlx_ptr) == NULL)
		return ;
	var.mouse_on_off = 0;
	var.max_itter = 200;
	var.zoom = 10;
	var.majal_xa = -2;
	var.majal_xb = 2;
	var.majal_ya = -2;
	var.majal_yb = 2;
	var.r1 = 1;
	var.r2 = 1;
	var.r3 = 0;
	calculate_julia(&var, ac, av);
	mlx_mouse_hook(var.win_ptr, recieve_mouse_julia, &var);
	mlx_hook(var.win_ptr, 2, 0, listen_to_events_julia, &var);
	mlx_hook(var.win_ptr, 3, 0, ft_close, &var);
	mlx_hook(var.win_ptr, 17, 0, ft_close_17, &var);
	mlx_hook(var.win_ptr, 6, 0, mouse_move_julia, &var);
	mlx_loop(var.mlx_ptr);
}

void	run_mandelbrot(void)
{
	t_fractol	var;

	var.mlx_ptr = mlx_init();
	if ((var.mlx_ptr) == NULL)
		return ;
	var.max_itter = 100;
	var.zoom = 10;
	var.majal_xa = -2;
	var.majal_xb = 2;
	var.majal_ya = -2;
	var.majal_yb = 2;
	var.r1 = 1;
	var.r2 = 1;
	var.r3 = 0;
	calculate_mandelbrot(&var);
	mlx_mouse_hook(var.win_ptr, recieve_mouse, &var);
	mlx_hook(var.win_ptr, 2, 0, listen_to_events_madelbrot, &var);
	mlx_hook(var.win_ptr, 3, 0, ft_close, &var);
	mlx_hook(var.win_ptr, 17, 0, ft_close_17, &var);
	mlx_hook(var.win_ptr, 6, 0, mouse_move, &var);
	mlx_loop(var.mlx_ptr);
}

void	run_ship(void)
{
	t_fractol	var;

	var.mlx_ptr = mlx_init();
	if ((var.mlx_ptr) == NULL)
		return ;
	var.max_itter = 100;
	var.zoom = 10;
	var.majal_xa = -2;
	var.majal_xb = 2;
	var.majal_ya = -2;
	var.majal_yb = 2;
	var.r1 = 1;
	var.r2 = 1;
	var.r3 = 0;
	calculate_ship(&var);
	mlx_mouse_hook(var.win_ptr, recieve_mouse_ship, &var);
	mlx_hook(var.win_ptr, 2, 0, listen_to_events_ship, &var);
	mlx_hook(var.win_ptr, 3, 0, ft_close, &var);
	mlx_hook(var.win_ptr, 17, 0, ft_close_17, &var);
	mlx_hook(var.win_ptr, 6, 0, mouse_move, &var);
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
	else if (!ft_strncmp(av[1], "ship", 4))
		run_ship();
	else
		usage();
}
