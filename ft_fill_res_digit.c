/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_res_digit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:10:16 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/21 20:10:17 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_res	*ft_fill_res_digit(t_struc *struc, t_res *res)
{
	if (struc->flag[2] == ' ' && ft_is_needle("dDi", struc->type) == 1 &&
		struc->minus == 0)
	{
		res->arr = ft_join(res->arr, " ");
		res->count++;
	}
	if (struc->flag[2] == '+' && struc->minus == 0)
	{
		res->arr = ft_join(res->arr, "+");
		res->count++;
	}
	if (struc->minus == 1)
	{
		res->arr = ft_join(res->arr, "-");
		res->count++;
	}
	return (res);
}
