/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_min_precision_pos_x_55.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:15:39 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:33 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_helper_calcul_x_55_2(int varg, int second, int size)
{
	ft_calculate_hex(size, '0');
	if (varg == 0 && second == 0)
	{
		ft_putchar(' ');
		ft_putstr("");
	}
	else
		ft_putstr(ft_hex_55((varg)));
}

void	star_calcul_x_55_2(int varg, int first, char second)
{
	int		size;

	size = 0;
	if (second == 0)
		size = first - ft_strlen(ft_hex_55(varg));
	else if (second != 0)
	{
		if (second < (int)ft_strlen(ft_hex_55(varg)))
			size = first - ft_strlen(ft_hex_55(varg));
		else
			size = first - second;
	}
	ft_calculate_hex(size, ' ');
	size = second - ft_strlen(ft_hex_55(varg));
	star_helper_calcul_x_55_2(varg, second, size);
}

void	star_calcul_x_55_3(int varg, int first, char second)
{
	int		size;

	size = 0;
	if (first <= second)
	{
		size = second - ft_strlen(ft_hex_55(varg));
		ft_calculate_hex(size, '0');
		ft_putstr(ft_hex_55((varg)));
	}
}

void	star_calcul_x_55(va_list arg, int first, char second)
{
	int		varg;
	int		size;

	varg = va_arg(arg, unsigned int);
	size = 0;
	if (varg == 0 && first == 0 && second == 0)
		ft_putstr("");
	else if (first > second)
		star_calcul_x_55_2(varg, first, second);
	else if (first <= second && first != 0 && second != 0)
		star_calcul_x_55_3(varg, first, second);
	else if (first <= second)
		star_calcul_x_55_3(varg, first, second);
}
