/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_neg_x_87.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 07:29:46 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:52 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	neg_calcul_x_87_2(unsigned int varg, int change, char *second)
{
	int		size;

	size = 0;
	if (ft_atoi(second) == 0)
	{
		size = change - ft_strlen(ft_hex_87(varg));
		if (ft_atoi(second) == 0 && varg == 0)
		{
			ft_putstr("");
			size++;
		}
		else
			ft_putstr(ft_hex_87((varg)));
		ft_calculate_hex(size, ' ');
	}
}

int		size_calcul_87(unsigned varg, int change, char *second, int j)
{
	int		size;

	size = 0;
	if (ft_atoi(second) < (int)ft_strlen(ft_hex_87(varg)))
		size = change - ft_strlen(ft_hex_87(varg)) - j;
	else
		size = change - ft_atoi(second);
	return (size);
}

void	neg_calcul_x_87_3(unsigned int varg, int change, char *second)
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
			size = ft_atoi(second) - ft_strlen(ft_hex_87(varg));
			j = ft_calculate_hex(size, '0');
			ft_putstr(ft_hex_87((varg)));
			size = size_calcul_87(varg, change, second, j);
			ft_calculate_hex(size, ' ');
		}
		else if (change < ft_atoi(second))
		{
			size = ft_atoi(second) - ft_strlen(ft_hex_87(varg));
			ft_calculate_hex(size, '0');
			ft_putstr(ft_hex_87((varg)));
		}
	}
}

void	neg_calcul_x_87(va_list arg, char *first, char *second)
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
		neg_calcul_x_87_2(varg, change, second);
		neg_calcul_x_87_3(varg, change, second);
	}
}
