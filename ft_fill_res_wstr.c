/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_res_wstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:10:56 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/21 20:46:44 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_norm(t_struc *struc, t_res *res)
{
	int		i;
	int		c;
	char	*tmp;

	i = 0;
	c = ft_count_bytes_of_unicode(struc->w_str);
	while (struc->w_str[i] && c >= 0)
	{
		if (struc->w_str[i] <= 0x7F)
			c = c - 1;
		else if (struc->w_str[i] > 0x7F && struc->w_str[i] <= 0x7FF)
			c = c - 2;
		else if (struc->w_str[i] > 0x7FF && struc->w_str[i] <= 0xFFFF)
			c = c - 3;
		else if (struc->w_str[i] > 0xFFFF && struc->w_str[i] <= 0x10FFFF)
			c = c - 4;
		if (c >= 0)
		{
			tmp = ft_print_wchar(struc->w_str[i], 0, 0);
			res->arr = ft_strjoin(res->arr, tmp);
			res->count += ft_size_of_unicode(struc->w_str[i]);
			ft_strdel(&tmp);
		}
		i++;
	}
}

t_res		*ft_fill_res_wstr(t_struc *struc, t_res *res)
{
	int		i;

	i = 0;
	if (MB_CUR_MAX > 1)
		ft_norm(struc, res);
	else
	{
		while (struc->w_str[i])
		{
			if ((int)struc->w_str[0] >= 0 && (int)struc->w_str[0] <= 255)
			{
				res->count += 1;
				res->arr = ft_strjoin(res->arr, (char *)struc->w_str);
				struc->w_str++;
			}
			else if ((int)struc->w_str[0] > 255)
			{
				res->count = -1;
				ft_strdel(&res->arr);
				return (res);
			}
		}
	}
	return (res);
}
