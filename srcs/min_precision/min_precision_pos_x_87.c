/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_pos_x_87.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 07:29:53 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:04 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	helper_calcul_x_87_2(unsigned int varg, char *second, int size)
{
	ft_calculate_hex(size, '0');
	if (varg == 0 && ft_atoi(second) == 0)
	{
		ft_putchar(' ');
		ft_putstr("");
	}
	else
		ft_putstr(ft_hex_87((varg)));
}

void	calcul_x_87_2(unsigned int varg, char *first, char *second, int s_ind)
{
	int		size;

	size = 0;
	if (ft_atoi(second) == 0)
		size = ft_atoi(first) - ft_strlen(ft_hex_87(varg));
	else if (ft_atoi(second) != 0)
	{
		if (ft_atoi(second) < (int)ft_strlen(ft_hex_87(varg)))
			size = ft_atoi(first) - ft_strlen(ft_hex_87(varg));
		else
			size = ft_atoi(first) - ft_atoi(second);
	}
	if (s_ind == 1 && ft_atoi(second) < 0)
		ft_calculate_hex(size, '0');
	else
		ft_calculate_hex(size, ' ');
	size = ft_atoi(second) - ft_strlen(ft_hex_87(varg));
	helper_calcul_x_87_2(varg, second, size);
}

void	calcul_x_87_3(unsigned int varg, char *first, char *second)
{
	int		size;

	size = 0;
	if (ft_atoi(first) <= ft_atoi(second))
	{
		size = ft_atoi(second) - ft_strlen(ft_hex_87(varg));
		ft_calculate_hex(size, '0');
		ft_putstr(ft_hex_87((varg)));
	}
}

void	calcul_x_87(va_list arg, char *first, char *second, int s_ind)
{
	int		varg;
	int		size;

	varg = va_arg(arg, unsigned int);
	size = 0;
	if (varg == 0 && ft_atoi(first) == 0 && ft_atoi(second) == 0)
		ft_putstr("");
	else if (ft_atoi(first) > ft_atoi(second))
		calcul_x_87_2(varg, first, second, s_ind);
	else if (first <= second)
		calcul_x_87_3(varg, first, second);
}
