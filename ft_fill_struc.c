/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:11:06 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/21 20:11:07 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struc	*ft_fill_struc(va_list arg_ptr, t_struc *struc, const char *format,
	int i)
{
	int		j;
	char	*str;
	char	*arr;

	j = 0;
	str = "#+-0 .123456789hljz*";
	arr = ft_strchr(format + i, '%') + 1;
	struc = ft_create_struc(struc);
	while (arr[j] != '\0' && ft_is_needle(str, arr[j]))
	{
		j = ft_check_flag(arr, struc, j);
		j = ft_check_width(arr, arg_ptr, struc, j);
		j = ft_check_prec(arr, arg_ptr, struc, j);
		j = ft_check_size(arr, struc, j);
	}
	struc->tmp = i + j;
	return (struc);
}
