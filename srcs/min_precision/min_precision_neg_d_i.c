/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_neg_d_i.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 07:55:55 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:45 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	neg_calcul_2(int varg, int change, char *second, int indicator)
{
	int		size;

	size = 0;
	if (ft_atoi(second) == 0)
	{
		size = change - ft_strlen(ft_itoa(varg));
		if (ft_atoi(second) == 0 && varg == 0)
		{
			ft_putstr("");
			size++;
		}
		else
			ft_putnbr(varg);
		if (indicator == 1)
			size--;
		ft_calculate(size, ' ');
	}
}

void	neg_calcul_3_helper(int varg, int change, char *second, int indicator)
{
	int		size;

	size = 0;
	if (change >= ft_atoi(second))
	{
		size = ft_atoi(second) - ft_strlen(ft_itoa(varg));
		ft_calculate(size, '0');
		ft_putnbr(varg);
		if (ft_atoi(second) < (int)ft_strlen(ft_itoa(varg)))
			size = change - ft_strlen(ft_itoa(varg));
		else
			size = change - ft_atoi(second);
		if (indicator == 1)
			ft_calculate(--size, ' ');
		else
			ft_calculate(size, ' ');
	}
	else if (change < ft_atoi(second))
	{
		size = ft_atoi(second) - ft_strlen(ft_itoa(varg));
		ft_calculate(size, '0');
		ft_putnbr(varg);
	}
}

void	neg_calcul_3(int varg, int change, char *second, int indicator)
{
	int		size;

	size = 0;
	if (ft_atoi(second) != 0)
		neg_calcul_3_helper(varg, change, second, indicator);
}

void	neg_calcul(va_list arg, char *first, char *second)
{
	int		size;
	int		varg;
	int		indicator;
	int		change;

	size = 0;
	indicator = 0;
	change = ft_atoi(first) * -1;
	varg = va_arg(arg, int);
	if (ft_atoi(first) <= ft_atoi(second)
	|| (ft_atoi(first) < 0 && ft_atoi(second) < 0))
	{
		if (varg < 0)
		{
			indicator = 1;
			ft_putchar('-');
			varg *= -1;
		}
		neg_calcul_2(varg, change, second, indicator);
		neg_calcul_3(varg, change, second, indicator);
	}
}
