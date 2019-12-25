/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_min_precision_pos_d_i.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:33:38 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:28 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_helper_calcul_2(int varg, int second, int size)
{
	ft_calculate(size, '0');
	if (varg == 0 && second == 0)
	{
		ft_putchar(' ');
		ft_putstr("");
	}
	else
	{
		if (varg < 0)
			varg *= -1;
		ft_putunsignednbr(varg);
	}
}

void	star_calcul_2(int varg, int first, int second, int indicator)
{
	int		size;

	size = 0;
	if (second == 0)
		size = first - ft_strlen(ft_itoa(varg));
	else if (second != 0)
	{
		if (second < (int)ft_strlen(ft_itoa(varg)))
			size = first - ft_strlen(ft_itoa(varg));
		else
			size = first - second;
	}
	if (indicator == 1)
		size--;
	ft_calculate(size, ' ');
	size = second - ft_strlen(ft_itoa(varg));
	if (indicator == 1)
		ft_putchar('-');
	star_helper_calcul_2(varg, second, size);
}

void	star_calcul_3(int varg, int second)
{
	int		size;

	size = 0;
	if (varg < 0)
	{
		ft_putchar('-');
		varg *= -1;
	}
	size = second - ft_strlen(ft_itoa(varg));
	ft_calculate(size, '0');
	ft_putunsignednbr(varg);
}

void	star_calcul(va_list arg, int first, int second)
{
	int		varg;
	int		size;
	int		indicator;

	varg = va_arg(arg, int);
	size = 0;
	indicator = 0;
	if (varg == 0 && first == 0 && second == 0)
		ft_putstr("");
	else if (first > second)
	{
		if (varg < 0)
		{
			indicator = 1;
			varg *= -1;
		}
		star_calcul_2(varg, first, second, indicator);
	}
	else if (first <= second)
		star_calcul_3(varg, second);
}
