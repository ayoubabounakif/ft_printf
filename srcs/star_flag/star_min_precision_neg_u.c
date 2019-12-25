/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_min_precision_neg_u.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:26:36 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:17 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_neg_calcul_u_2(unsigned int varg, int change, int second)
{
	int		size;

	size = 0;
	if (second == 0)
	{
		size = change - ft_strlen(ft_unsigned_itoa(varg));
		if (second == 0 && varg == 0)
		{
			ft_putstr("");
			size++;
		}
		else
			ft_putunsignednbr(varg);
		ft_calculate(size, ' ');
	}
}

void	star_neg_calcul_u_3(unsigned int varg, int change, int second)
{
	int		size;

	size = 0;
	if (second != 0)
	{
		if (change >= second)
		{
			size = second - ft_strlen(ft_unsigned_itoa(varg));
			ft_calculate(size, '0');
			ft_putunsignednbr(varg);
			if (second > (int)ft_strlen(ft_unsigned_itoa(varg)))
				size = change - second;
			else
				size = change - ft_strlen(ft_unsigned_itoa(varg));
			ft_calculate(size, ' ');
		}
		else if (change < second)
		{
			size = second - ft_strlen(ft_unsigned_itoa(varg));
			ft_calculate(size, '0');
			ft_putunsignednbr(varg);
		}
	}
}

void	star_neg_calcul_u(va_list arg, int first, int second)
{
	int					size;
	unsigned int		varg;
	int					change;

	size = 0;
	change = first * -1;
	varg = va_arg(arg, unsigned int);
	if (first <= second)
	{
		star_neg_calcul_u_2(varg, change, second);
		star_neg_calcul_u_3(varg, change, second);
	}
	else if (first > second)
	{
		star_neg_calcul_u_2(varg, change, second);
		star_neg_calcul_u_3(varg, change, second);
	}
}
