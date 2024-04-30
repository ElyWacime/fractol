/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:16:27 by welyousf          #+#    #+#             */
/*   Updated: 2024/04/29 13:08:37 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	ft_atoi(char *str)
{
	int			i;
	long double	sign;
	long double	result;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == '+')
	{
		sign = !(str[i] == '-') - (str[i] == '-');
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = 10 * result + (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
		i++;
	return (ft_atof(str + i, result) * sign);
}
