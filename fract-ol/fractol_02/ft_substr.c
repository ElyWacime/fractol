/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:57:29 by welyousf          #+#    #+#             */
/*   Updated: 2024/03/30 22:06:58 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (0);
	if (len > ft_strlen(s) - (size_t)start)
		len = ft_strlen(s) - (size_t)start;
	if (start >= (unsigned int)ft_strlen(s))
		len = 0;
	sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[(size_t)start + i] != '\0')
	{
		sub[i] = s[(size_t)start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
