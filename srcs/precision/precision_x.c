/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 06:49:37 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:46 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_x(va_list arg, char *traverse, int c)
{
	int		varg;
	int		size;

	size = 0;
	varg = va_arg(arg, unsigned int);
	if (varg == 0)
		ft_putstr("");
	else
	{
		if (c == 87)
		{
			size = ft_atoi(traverse) - ft_strlen(ft_hex_87(varg) + 1);
			ft_calculate(size, '0');
			ft_putstr(ft_hex_87(varg));
		}
		else if (c == 55)
		{
			size = ft_atoi(traverse) - ft_strlen(ft_hex_55(varg) + 1);
			ft_calculate(size, '0');
			ft_putstr(ft_hex_55(varg));
		}
	}
}

void	precision_x_87_2(va_list arg)
{
	int		first_arg;
	int		second_arg;
	int		size;

	size = 0;
	first_arg = va_arg(arg, int);
	second_arg = va_arg(arg, unsigned int);
	if (first_arg == 0 && second_arg == 0)
		ft_putstr("");
	else if (first_arg <= 0)
		ft_putstr(ft_hex_87(second_arg));
	size = first_arg - ft_strlen(ft_hex_87(second_arg));
	ft_calculate(size, '0');
	if (first_arg > 0)
		ft_putstr(ft_hex_87(second_arg));
}

void	precision_x_87(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	traverse++;
	if (*traverse == '*')
		precision_x_87_2(arg);
	else if (*traverse == 'x' || ft_atoi(traverse) == 0)
		precision_x(arg, traverse, 87);
	else
	{
		varg = va_arg(arg, unsigned int);
		size = ft_atoi(traverse) - ft_strlen(ft_hex_87(varg));
		ft_calculate(size, '0');
		ft_putstr(ft_hex_87(varg));
	}
}

void	precision_x_55_2(va_list arg)
{
	int		first_arg;
	int		second_arg;
	int		size;

	size = 0;
	first_arg = va_arg(arg, int);
	second_arg = va_arg(arg, unsigned int);
	if (first_arg == 0 && second_arg == 0)
		ft_putstr("");
	else if (first_arg <= 0)
		ft_putstr(ft_hex_55(second_arg));
	size = first_arg - ft_strlen(ft_hex_55(second_arg));
	ft_calculate(size, '0');
	if (first_arg > 0)
		ft_putstr(ft_hex_55(second_arg));
}

void	precision_x_55(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	traverse++;
	if (*traverse == '*')
		precision_x_55_2(arg);
	else if (*traverse == 'x' || ft_atoi(traverse) == 0)
		precision_x(arg, traverse, 55);
	else
	{
		varg = va_arg(arg, int);
		size = ft_atoi(traverse) - ft_strlen(ft_hex_55(varg));
		ft_calculate(size, '0');
		ft_putstr(ft_hex_55(varg));
	}
}
