/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_for_atoi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:30:06 by welyousf          #+#    #+#             */
/*   Updated: 2024/04/29 19:54:50 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1337);
	return (0);
}

int	check_args1(char	*av, int	*i)
{
	while (av[*i] == ' ')
		*i = *i + 1;
	if (!av[*i])
		return (0);
	if (av[*i] == '+' || av[*i] == '-')
		*i = *i + 1;
	if (!ft_isdigit(av[*i]))
		return (0);
	while (ft_isdigit(av[*i]))
		*i = *i + 1;
	return (1);
}

int	check_args(char	*av)
{
	int	i;

	i = 0;
	if (!check_args1(av, &i))
		return (0);
	if ((av[i] == '.' || av[i] == ',') && ft_isdigit(av[i + 1]))
		i++;
	else if (av[i] == ' ')
	{
		while (av[i] == ' ')
			i++;
		return (av[i] == '\0');
	}
	else
		return (0);
	while (ft_isdigit(av[i]))
		i++;
	while (av[i] == ' ')
		i++;
	return (av[i] == '\0');
}

long double	ft_atof(char *str, long double result)
{
	int			i;
	long double	power;

	i = 0;
	power = 10;
	while (ft_isdigit(str[i]))
	{
		result += ((str[i] - 48) / power);
		power *= 10;
		i++;
	}
	return (result);
}
