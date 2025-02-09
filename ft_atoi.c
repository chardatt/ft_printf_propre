/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:09:16 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/21 20:09:17 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	ft_is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	unsigned long long int	n;
	int						flag;
	int						i;

	n = 0;
	i = 0;
	flag = 1;
	while (ft_is_space(str[i]) == 1)
		i++;
	if (str[i] == '-')
		flag = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		if ((n > FT_LIM || (n == FT_LIM && (str[i] - 48) > 7))
			&& flag == 1)
			return (-1);
		else if ((n > FT_LIM || (n == FT_LIM && (str[i] - 48) > 8))
			&& flag == -1)
			return (0);
		n = n * 10 + str[i] - 48;
		i++;
	}
	return (n * flag);
}
