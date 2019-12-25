/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_min_precision_neg_d_i.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:33:32 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:15 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_neg_calcul_2(int varg, int change, int second, int indicator)
{
	int		size;

	size = 0;
	if (second == 0)
	{
		size = change - ft_strlen(ft_itoa(varg));
		if (second == 0 && varg == 0)
		{
			ft_putstr("");
			size++;
		}
		else
			ft_putunsignednbr(varg);
		if (indicator == 1)
			size--;
		if (varg == INT32_MIN)
			size++;
		ft_calculate(size, ' ');
	}
}

void	star_neg_calcul_3_helper(int varg, int change, int second, int ind)
{
	int		size;

	size = 0;
	if (change >= second)
	{
		size = second - ft_strlen(ft_itoa(varg));
		ft_calculate(size, '0');
		ft_putunsignednbr(varg);
		if (second < (int)ft_strlen(ft_itoa(varg)))
			size = change - ft_strlen(ft_itoa(varg));
		else
			size = change - second;
		if (ind == 1 && varg != INT32_MIN)
			size--;
		ft_calculate(size, ' ');
	}
	else if (change < second)
	{
		size = second - ft_strlen(ft_itoa(varg));
		ft_calculate(size, '0');
		ft_putunsignednbr(varg);
	}
}

void	star_neg_calcul_3(int varg, int change, int second, int ind)
{
	int		size;

	size = 0;
	if (second != 0)
		star_neg_calcul_3_helper(varg, change, second, ind);
}

void	star_neg_calcul(va_list arg, int first, int second)
{
	int		size;
	int		varg;
	int		indicator;
	int		change;

	size = 0;
	indicator = 0;
	change = first * -1;
	varg = va_arg(arg, int);
	if (varg < 0)
	{
		indicator = 1;
		ft_putchar('-');
		varg *= -1;
	}
	star_neg_calcul_2(varg, change, second, indicator);
	star_neg_calcul_3(varg, change, second, indicator);
}
