/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_flag_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 06:24:08 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:01 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_flag_x(int i, int size, int varg_2, int c)
{
	if (i == 0)
		ft_calculate(size, '0');
	else
		ft_calculate(size, ' ');
	if (c == 55)
		ft_putstr(ft_hex_55((varg_2)));
	else if (c == 87)
		ft_putstr(ft_hex_87((varg_2)));
}

void	star_flag_x_87(va_list arg, int i)
{
	int		size;
	int		varg_1;
	int		varg_2;

	size = 0;
	varg_1 = va_arg(arg, int);
	varg_2 = va_arg(arg, int);
	if (varg_1 < 0)
	{
		size = (varg_1 * -1) - ft_strlen(ft_hex_87(varg_2));
		ft_putstr(ft_hex_87((varg_2)));
		ft_calculate(size, ' ');
	}
	else
	{
		size = varg_1 - ft_strlen(ft_hex_87(varg_2));
		star_flag_x(i, size, varg_2, 87);
	}
}

void	star_flag_x_55(va_list arg, int i)
{
	int		size;
	int		varg_1;
	int		varg_2;

	size = 0;
	varg_1 = va_arg(arg, int);
	varg_2 = va_arg(arg, int);
	if (varg_1 < 0)
	{
		size = (varg_1 * -1) - ft_strlen(ft_hex_55(varg_2));
		ft_putstr(ft_hex_55((varg_2)));
		ft_calculate(size, ' ');
	}
	else
	{
		size = varg_1 - ft_strlen(ft_hex_55(varg_2));
		star_flag_x(i, size, varg_2, 55);
	}
}

void	star_flag_p_2(int i, int size, int varg)
{
	if (i == 0)
		ft_calculate(size, '0');
	else
		ft_calculate(size, ' ');
	ft_putstr("0x");
	ft_putstr(ft_memory(varg));
}

void	star_flag_p(va_list arg, int i)
{
	int					first;
	int					size;
	unsigned long long	varg;

	size = 0;
	first = va_arg(arg, int);
	varg = (unsigned long long)va_arg(arg, void *);
	if (first < 0)
	{
		first *= -1;
		size = first - (ft_strlen(ft_memory(varg)) + 2);
		ft_putstr("0x");
		ft_putstr(ft_memory(varg));
		ft_calculate(size, ' ');
	}
	else
	{
		size = first - (ft_strlen(ft_memory(varg)) + 2);
		star_flag_p_2(i, size, varg);
	}
}
