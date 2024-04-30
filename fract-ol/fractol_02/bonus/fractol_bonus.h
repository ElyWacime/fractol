/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:34:40 by welyousf          #+#    #+#             */
/*   Updated: 2024/04/30 12:11:01 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <math.h>
# include "../minilibx_opengl_20191021/mlx.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct parsing
{
	char		*usage;
}				t_parsing;

typedef struct s_img
{
	void		*img_ptr;
	char		*img_pixels;
	int			bpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_fractol
{
	t_img		img;
	int			mouse_on_off;
	void		*data;
	size_t		color;
	size_t		max_itter;
	char		*title;
	void		*mlx_ptr;
	void		*win_ptr;
	long double	zx;
	long double	zy;
	long double	cx;
	long double	cy;
	long double	cxo;
	long double	cyo;
	long double	tmp;
	long double	tmp2;
	long double	distance_x;
	long double	distance_y;
	long double	x;
	long double	y;
	size_t		i;
	long double	zoom;
	long double	zoom_out;
	long double	x_offset;
	long double	y_offset;
	long double	majal_xa;
	long double	majal_xb;
	long double	majal_ya;
	long double	majal_yb;
	long double	mouse_x;
	long double	mouse_y;
	long double	mouse_xx;
	long double	mouse_yy;
	int			r1;
	int			r2;
	int			r3;
}				t_fractol;

void			design_mendel_img(t_fractol *var);
void			calculate_mandelbrot(t_fractol *var);
int				ft_close(int keycode, t_fractol *var);
int				ft_close_17(t_fractol *var);
int				recieve_mouse(int button, int x, int y, t_fractol *var);
void			create_image(t_fractol *var);
void			upgraded_mlx_pixel_put(t_img *img, int x, int y, int color);
void			replace_img(t_fractol *var);
void			design_mendel_img(t_fractol *var);
int				check_conv_dive(t_fractol *var);
void			from_window_to_grid(t_fractol *var);
void			calculate_mandelbrot(t_fractol *var);
int				ft_strlen(char *str);
char			*ft_substr(char *s, unsigned int start, size_t len);

void			calculate_julia(t_fractol *var, int ac, char **av);
void			design_julia_img(t_fractol *var);
void			run_julia(int ac, char **av);
long double		ft_atoi(char *str);
long double		ft_atof(char	*str, long double result);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				recieve_mouse_julia(int button, int x, int y, t_fractol *var);
void			from_window_to_grid_julia_mouse(t_fractol *var);
int				check_args(char	*av);
void			reset(int keycode, t_fractol *var);
int				mouse_move_julia(int x, int y, t_fractol *var);

void			calculate_ship(t_fractol *var);
void			from_window_to_grid_ship(t_fractol *var);
int				check_conv_dive_ship(t_fractol *var);
void			design_ship(t_fractol *var);
int				recieve_mouse_ship(int button, int x, int y, t_fractol *var);

int				listen_to_events_ship(int keycode, t_fractol *var);
int				listen_to_events_julia(int keycode, t_fractol *var);
int				listen_to_events_madelbrot(int keycode, t_fractol *var);
void			listen_to_events_ship_1(int keycode, t_fractol *var);
void			listen_to_events_madelbrot_1(int keycode, t_fractol *var);
void			listen_to_events_julia_1(int keycode, t_fractol *var);
int				mouse_move(int x, int y, t_fractol *var);

size_t			calculate_color(t_fractol *var);

#endif