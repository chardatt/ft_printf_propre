/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_structs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:09:58 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/21 20:09:59 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struc	*ft_create_struc(t_struc *struc)
{
	if (!struc)
		struc = (t_struc *)malloc(sizeof(t_struc));
	ft_bzero(struc->flag, 3);
	ft_bzero(struc->size, 2);
	struc->c_flag = 0;
	struc->width = 0;
	struc->c_width = 0;
	struc->dot = 0;
	struc->prec = 0;
	struc->c_prec = 0;
	struc->type = '\0';
	struc->str = NULL;
	struc->w_str = NULL;
	struc->before_str = NULL;
	struc->after_str = NULL;
	struc->len = 0;
	struc->tmp = 0;
	struc->minus = 0;
	return (struc);
}

t_res	*ft_create_res(t_res *res)
{
	if (!res)
		res = (t_res *)malloc(sizeof(t_res));
	ft_bzero(res->ptr, 1024);
	res->arr = NULL;
	res->count = 0;
	res->nb_null = 0;
	res->k = 0;
	return (res);
}
