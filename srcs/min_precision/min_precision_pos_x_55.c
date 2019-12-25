/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_pos_x_55.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 07:27:30 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:02 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	helper_calcul_x_55_2(unsigned int varg, char *second, int size)
{
	ft_calculate_hex(size, '0');
	if (varg == 0 && ft_atoi(second) == 0)
	{
		ft_putchar(' ');
		ft_putstr("");
	}
	else
		ft_putstr(ft_hex_55((varg)));
}

void	calcul_x_55_2(unsigned int varg, char *first, char *second, int s_ind)
{
	int		size;

	size = 0;
	if (ft_atoi(second) == 0)
		size = ft_atoi(first) - ft_strlen(ft_hex_55(varg));
	else if (ft_atoi(second) != 0)
	{
		if (ft_atoi(second) < (int)ft_strlen(ft_hex_55(varg)))
			size = ft_atoi(first) - ft_strlen(ft_hex_55(varg));
		else
			size = ft_atoi(first) - ft_atoi(second);
	}
	if (s_ind == 1 && ft_atoi(second) < 0)
		ft_calculate_hex(size, '0');
	else
		ft_calculate_hex(size, ' ');
	size = ft_atoi(second) - ft_strlen(ft_hex_55(varg));
	helper_calcul_x_55_2(varg, second, size);
}

void	calcul_x_55_3(unsigned int varg, char *first, char *second)
{
	int		size;

	size = 0;
	if (ft_atoi(first) <= ft_atoi(second))
	{
		size = ft_atoi(second) - ft_strlen(ft_hex_55(varg));
		ft_calculate_hex(size, '0');
		ft_putstr(ft_hex_55((varg)));
	}
}

void	calcul_x_55(va_list arg, char *first, char *second, int s_ind)
{
	int		varg;
	int		size;

	varg = va_arg(arg, unsigned int);
	size = 0;
	if (varg == 0 && ft_atoi(first) == 0 && ft_atoi(second) == 0)
		ft_putstr("");
	else if (ft_atoi(first) > ft_atoi(second))
		calcul_x_55_2(varg, first, second, s_ind);
	else if (first <= second)
		calcul_x_55_3(varg, first, second);
}
