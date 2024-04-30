/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:16:06 by welyousf          #+#    #+#             */
/*   Updated: 2024/04/30 12:19:01 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mouse_move(int x, int y, t_fractol *var)
{
	if (x >= 0 && x <= 1000 & y >= 0 && y <= 1000)
	{
		var->mouse_x = x;
		var->mouse_y = y;
	}
	return (0);
}
