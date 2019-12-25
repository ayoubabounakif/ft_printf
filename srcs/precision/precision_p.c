/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 06:53:56 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:39 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_p(va_list arg)
{
	unsigned long long	varg;

	varg = (unsigned long long)va_arg(arg, void *);
	if (varg == 0)
		ft_putstr("0x");
	else
	{
		ft_putstr("0x");
		ft_putstr(ft_memory(varg));
	}
}
