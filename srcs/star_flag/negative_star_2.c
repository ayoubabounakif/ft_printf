/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_star_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 06:09:38 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:54 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	negative_star_flag_x_87(va_list arg)
{
	int		size;
	int		varg_1;
	int		varg_2;

	size = 0;
	varg_1 = va_arg(arg, int);
	varg_2 = va_arg(arg, int);
	if (varg_1 < 0)
		varg_1 *= -1;
	size = varg_1 - ft_strlen(ft_hex_87(varg_2));
	ft_putstr(ft_hex_87((varg_2)));
	ft_calculate(size, ' ');
}

void	negative_star_flag_x_55(va_list arg)
{
	int		size;
	int		varg_1;
	int		varg_2;

	size = 0;
	varg_1 = va_arg(arg, int);
	varg_2 = va_arg(arg, int);
	if (varg_1 < 0)
		varg_1 *= -1;
	size = varg_1 - ft_strlen(ft_hex_55(varg_2));
	ft_putstr(ft_hex_55((varg_2)));
	ft_calculate(size, ' ');
}

void	negative_star_flag_p(va_list arg)
{
	int					first;
	int					size;
	unsigned long long	varg;

	size = 0;
	first = va_arg(arg, int);
	varg = (unsigned long long)va_arg(arg, void *);
	if (first < 0)
		first *= -1;
	size = first - (ft_strlen(ft_memory(varg)) + 2);
	ft_putstr("0x");
	ft_putstr(ft_memory(varg));
	ft_calculate(size, ' ');
}
