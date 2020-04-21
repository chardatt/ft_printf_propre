/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:12:03 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/21 20:12:09 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_join(char *s1, char *s2)
{
	char	*arr;
	size_t	len1;
	size_t	len2;

	len1 = 1;
	len2 = 1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = s1 == NULL ? 0 : ft_strlen(s1);
	len2 = s2 == NULL ? 0 : ft_strlen(s2);
	if (!(arr = ft_strnew(len1 + len2 + 1024)))
		return (NULL);
	if (len1 > 0)
		arr = ft_strcpy(arr, s1);
	arr = ft_strcat(arr, s2);
	if (s1)
		ft_strdel(&s1);
	return (arr);
}
