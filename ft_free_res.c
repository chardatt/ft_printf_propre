/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_res.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:11:29 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/21 20:11:31 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_del_struc(t_struc *struc)
{
	if (ft_is_needle("CcdDioOuUxXp", struc->type) || struc->type == 0)
	{
		if (struc->str)
			ft_strdel(&struc->str);
		if (struc->w_str)
			ft_strdel((char **)&struc->w_str);
		if (struc->before_str)
			ft_strdel(&struc->before_str);
		if (struc->after_str)
			ft_strdel(&struc->after_str);
	}
}

void	ft_free_res(t_res *res)
{
	if (res)
	{
		if (res->arr)
			ft_strdel(&res->arr);
		free(res);
	}
}
