/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_min_precision_neg_x_87.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:17:54 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:21 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_neg_calcul_x_87_2(unsigned int varg, int change, int second)
{
	int		size;

	size = 0;
	if (second == 0)
	{
		size = change - ft_strlen(ft_hex_87(varg));
		if (second == 0 && varg == 0)
		{
			ft_putstr("");
			size++;
		}
		else
			ft_putstr(ft_hex_87((varg)));
		ft_calculate_hex(size, ' ');
	}
}

int		star_size_calcul_87(unsigned int varg, int change, int second, int j)
{
	int		size;

	size = 0;
	if (second > (int)ft_strlen(ft_hex_87(varg)))
		size = change - second;
	else
		size = change - ft_strlen(ft_hex_87(varg)) - j;
	return (size);
}

void	star_neg_calcul_x_87_3(unsigned int varg, int change, int second)
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
			size = second - ft_strlen(ft_hex_87(varg));
			j = ft_calculate_hex(size, '0');
			ft_putstr(ft_hex_87((varg)));
			size = star_size_calcul_87(varg, change, second, j);
			ft_calculate_hex(size, ' ');
		}
		else if (change < second)
		{
			size = second - ft_strlen(ft_hex_87(varg));
			ft_calculate_hex(size, '0');
			ft_putstr(ft_hex_87((varg)));
		}
	}
}

void	star_neg_calcul_x_87(va_list arg, int first, char second)
{
	int				size;
	unsigned int	varg;
	int				change;

	size = 0;
	change = first * -1;
	varg = va_arg(arg, unsigned int);
	if (first <= second)
	{
		star_neg_calcul_x_87_2(varg, change, second);
		star_neg_calcul_x_87_3(varg, change, second);
	}
	else if (first > second)
	{
		star_neg_calcul_x_87_2(varg, change, second);
		star_neg_calcul_x_87_3(varg, change, second);
	}
}
