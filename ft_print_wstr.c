/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:13:16 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/21 20:13:18 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_wstr(wchar_t *w_str)
{
	int		i;
	int		count;

	i = 0;
	count = ft_count_bytes_of_unicode(w_str);
	while (w_str[i] && count >= 0)
	{
		if (w_str[i] <= 0x7F)
			count = count - 1;
		else if (w_str[i] > 0x7F && w_str[i] <= 0x7FF)
			count = count - 2;
		else if (w_str[i] > 0x7FF && w_str[i] <= 0xFFFF)
			count = count - 3;
		else if (w_str[i] > 0xFFFF && w_str[i] <= 0x10FFFF)
			count = count - 4;
		if (count >= 0)
		{
			ft_print_wchar(w_str[i], 0, 0);
		}
		i++;
	}
}
