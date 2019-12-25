/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 00:27:31 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:06 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_flag_d_i_2(int i, int size, int varg_2)
{
	if (i == 0)
	{
		if (varg_2 < 0)
		{
			ft_putchar('-');
			varg_2 *= -1;
		}
		ft_calculate(size, '0');
	}
	else
	{
		ft_calculate(size, ' ');
		if (varg_2 < 0)
		{
			ft_putchar('-');
			varg_2 *= -1;
		}
	}
	ft_putunsignednbr(varg_2);
}

void	star_flag_d_i(va_list arg, int i)
{
	int		size;
	int		varg_1;
	int		varg_2;

	size = 0;
	varg_1 = va_arg(arg, int);
	varg_2 = va_arg(arg, int);
	if (varg_1 < 0)
	{
		size = (varg_1 * -1) - ft_strlen(ft_itoa(varg_2));
		if (varg_2 < 0)
		{
			ft_putchar('-');
			varg_2 *= -1;
		}
		ft_putunsignednbr(varg_2);
		ft_calculate(size, ' ');
	}
	else
	{
		size = varg_1 - ft_strlen(ft_itoa(varg_2));
		star_flag_d_i_2(i, size, varg_2);
	}
}

void	star_flag_u_2(int i, int size, int varg_2)
{
	if (i == 0)
		ft_calculate(size, '0');
	else
		ft_calculate(size, ' ');
	ft_putunsignednbr(varg_2);
}

void	star_flag_u(va_list arg, int i)
{
	int		size;
	int		varg_1;
	int		varg_2;

	size = 0;
	varg_1 = va_arg(arg, int);
	varg_2 = va_arg(arg, unsigned int);
	if (varg_1 < 0)
	{
		size = (varg_1 * -1) - ft_strlen(ft_unsigned_itoa(varg_2));
		ft_putunsignednbr(varg_2);
		if (i == 0)
			ft_calculate(size, '0');
		else
			ft_calculate(size, ' ');
	}
	else
	{
		size = varg_1 - ft_strlen(ft_unsigned_itoa(varg_2));
		star_flag_u_2(i, size, varg_2);
	}
}
