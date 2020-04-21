/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver_to_bin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:09:40 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/21 20:09:42 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_to_binary(int nb)
{
	int		div;
	char	*arr;
	int		i;

	arr = ft_strnew(21);
	div = 0;
	i = 0;
	while (div < nb)
	{
		i++;
		div = ft_recursive_power(2, i);
	}
	i = 0;
	while ((div = div / 2) > 0)
	{
		if (div <= nb)
		{
			arr[i] = '1';
			nb = nb % div;
		}
		else
			arr[i] = '0';
		i++;
	}
	return (arr);
}

int		ft_nb_len(char *arr)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (arr[i] == '0')
		i++;
	count = ft_strlen(arr + i);
	ft_strdel(&arr);
	return (count);
}
