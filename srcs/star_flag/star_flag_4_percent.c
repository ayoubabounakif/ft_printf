/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_flag_4_percent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 06:24:15 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:03 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_flag_percent_2(int i, int size)
{
	if (i == 0)
		ft_calculate(size, '0');
	else
		ft_calculate(size, ' ');
	ft_putchar('%');
}

void	star_flag_percent(va_list arg, int i)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, int);
	if (varg < 0)
	{
		size = (varg * -1) - 1;
		ft_putchar('%');
		if (i == 0)
			ft_calculate(size, '0');
		else
			ft_calculate(size, ' ');
	}
	else
	{
		size = varg - 1;
		star_flag_percent_2(i, size);
	}
}
