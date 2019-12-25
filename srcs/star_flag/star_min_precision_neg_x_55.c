/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_min_precision_neg_x_55.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:15:20 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:19 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_neg_calcul_x_55_2(unsigned int varg, int change, int second)
{
	int		size;

	size = 0;
	if (second == 0)
	{
		size = change - ft_strlen(ft_hex_55(varg));
		if (second == 0 && varg == 0)
		{
			ft_putstr("");
			size++;
		}
		else
			ft_putstr(ft_hex_55((varg)));
		ft_calculate_hex(size, ' ');
	}
}

int		star_size_calcul_55(unsigned int varg, int change, int second, int j)
{
	int		size;

	size = 0;
	if (second > (int)ft_strlen(ft_hex_55(varg)))
		size = change - second;
	else
		size = change - ft_strlen(ft_hex_55(varg)) - j;
	return (size);
}

void	star_neg_calcul_x_55_3(unsigned int varg, int change, int second)
{
	int		size;
	int		i;
	int		j;

	size = 0;
	i = 0;
	j = 0;
	if (second != 0)
	{
		if (change >= second)
		{
			size = second - ft_strlen(ft_hex_55(varg));
			j = ft_calculate_hex(size, '0');
			ft_putstr(ft_hex_55((varg)));
			size = star_size_calcul_55(varg, change, second, j);
			ft_calculate_hex(size, ' ');
		}
		else if (change < second)
		{
			size = second - ft_strlen(ft_hex_55(varg));
			ft_calculate_hex(size, '0');
			ft_putstr(ft_hex_55((varg)));
		}
	}
}

void	star_neg_calcul_x_55(va_list arg, int first, char second)
{
	int				size;
	unsigned int	varg;
	int				change;

	size = 0;
	change = first * -1;
	varg = va_arg(arg, unsigned int);
	if (first <= second)
	{
		star_neg_calcul_x_55_2(varg, change, second);
		star_neg_calcul_x_55_3(varg, change, second);
	}
	else if (first > second)
	{
		star_neg_calcul_x_55_2(varg, change, second);
		star_neg_calcul_x_55_3(varg, change, second);
	}
}
