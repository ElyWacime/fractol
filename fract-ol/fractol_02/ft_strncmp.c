/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:22:53 by welyousf          #+#    #+#             */
/*   Updated: 2024/03/30 22:06:29 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && i < n)
	{
		if (!s1[i] || !s2[i])
			break ;
		i++;
	}
	if (i == n)
		return ((int)(*(unsigned char *)(s1 + i - 1) - *(unsigned char *)(s2 + i
					- 1)));
	return ((int)(*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i)));
}
