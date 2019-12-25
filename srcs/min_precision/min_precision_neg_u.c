/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_neg_u.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 07:43:40 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:47 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	neg_calcul_u_2(unsigned int varg, int change, char *second)
{
	int		size;

	size = 0;
	if (ft_atoi(second) == 0)
	{
		size = change - ft_strlen(ft_unsigned_itoa(varg));
		if (ft_atoi(second) == 0 && varg == 0)
		{
			ft_putstr("");
			size++;
		}
		else
			ft_putunsignednbr(varg);
		ft_calculate(size, ' ');
	}
}

void	neg_calcul_u_3(unsigned int varg, int change, char *second)
{
	int		size;

	size = 0;
	if (ft_atoi(second) != 0)
	{
		if (change >= ft_atoi(second))
		{
			size = ft_atoi(second) - ft_strlen(ft_unsigned_itoa(varg));
			ft_calculate(size, '0');
			ft_putunsignednbr(varg);
			if (ft_atoi(second) < (int)ft_strlen(ft_unsigned_itoa(varg)))
				size = change - ft_strlen(ft_unsigned_itoa(varg));
			else
				size = change - ft_atoi(second);
			ft_calculate(size, ' ');
		}
		else if (change < ft_atoi(second))
		{
			size = ft_atoi(second) - ft_strlen(ft_unsigned_itoa(varg));
			ft_calculate(size, '0');
			ft_putunsignednbr(varg);
		}
	}
}

void	neg_calcul_u(va_list arg, char *first, char *second)
{
	int					size;
	unsigned int		varg;
	int					change;
	int					indicator;

	size = 0;
	indicator = 0;
	change = ft_atoi(first) * -1;
	varg = va_arg(arg, unsigned int);
	if (ft_atoi(first) <= ft_atoi(second)
	|| (ft_atoi(first) < 0 && ft_atoi(second) < 0))
	{
		neg_calcul_u_2(varg, change, second);
		neg_calcul_u_3(varg, change, second);
	}
}
