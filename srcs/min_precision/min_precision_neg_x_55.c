/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_neg_x_55.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 07:26:09 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:50 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	neg_calcul_x_55_2(unsigned int varg, int change, char *second)
{
	int		size;

	size = 0;
	if (ft_atoi(second) == 0)
	{
		size = change - ft_strlen(ft_hex_55(varg));
		if (ft_atoi(second) == 0 && varg == 0)
		{
			ft_putstr("");
			size++;
		}
		else
			ft_putstr(ft_hex_55((varg)));
		ft_calculate_hex(size, ' ');
	}
}

int		size_calcul_55(unsigned varg, int change, char *second, int j)
{
	int		size;

	size = 0;
	if (ft_atoi(second) < (int)ft_strlen(ft_hex_55(varg)))
		size = change - ft_strlen(ft_hex_55(varg)) - j;
	else
		size = change - ft_atoi(second);
	return (size);
}

void	neg_calcul_x_55_3(unsigned int varg, int change, char *second)
{
	int		size;
	int		i;
	int		j;

	size = 0;
	i = 0;
	j = 0;
	if (ft_atoi(second) != 0)
	{
		if (change >= ft_atoi(second))
		{
			size = ft_atoi(second) - ft_strlen(ft_hex_55(varg));
			j = ft_calculate_hex(size, '0');
			ft_putstr(ft_hex_55((varg)));
			size = size_calcul_55(varg, change, second, j);
			ft_calculate_hex(size, ' ');
		}
		else if (change < ft_atoi(second))
		{
			size = ft_atoi(second) - ft_strlen(ft_hex_55(varg));
			ft_calculate_hex(size, '0');
			ft_putstr(ft_hex_55((varg)));
		}
	}
}

void	neg_calcul_x_55(va_list arg, char *first, char *second)
{
	int				size;
	unsigned int	varg;
	int				change;

	size = 0;
	change = ft_atoi(first) * -1;
	varg = va_arg(arg, unsigned int);
	if (ft_atoi(first) <= ft_atoi(second)
	|| (ft_atoi(first) < 0 && ft_atoi(second) < 0))
	{
		neg_calcul_x_55_2(varg, change, second);
		neg_calcul_x_55_3(varg, change, second);
	}
}
