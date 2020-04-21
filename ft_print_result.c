/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:12:53 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/21 20:12:58 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_result(t_res *res, int i, int sub, int ret)
{
	char	*arr;

	arr = res->arr;
	ret = res->count;
	while (res->count > 0)
	{
		sub = res->count;
		if (res->k > 0 && res->ptr[i] != '\0')
		{
			sub = i == 0 ? ft_atoi(res->ptr[i]) - 1 :
			ft_atoi(res->ptr[i]) - ft_atoi(res->ptr[i - 1]) - 1;
			write(1, arr, sub);
			write(1, "\0", 1);
			res->count = res->count - sub;
			arr = arr + sub;
			i++;
			res->k--;
		}
		else
		{
			write(1, arr, sub - i);
			res->count = 0;
		}
	}
	return (ret);
}
