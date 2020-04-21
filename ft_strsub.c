/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:15:39 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/21 20:15:40 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*arr;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(arr = (char *)malloc(sizeof(char) * ((int)len + 1))))
		return (NULL);
	while ((int)len > 0)
	{
		arr[i] = s[start];
		i++;
		start++;
		len--;
	}
	arr[i] = '\0';
	return (arr);
}
