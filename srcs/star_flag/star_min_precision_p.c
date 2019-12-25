/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_min_precision_p.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:07:35 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:24 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_calcul_p(size_t varg, int first)
{
	int		size;

	size = 0;
	if (varg == 0)
	{
		size = first - ft_strlen(ft_memory(varg)) - 1;
		ft_calculate(size, ' ');
		ft_putstr("0x");
	}
	else
	{
		size = first - ft_strlen(ft_memory(varg)) - 2;
		ft_calculate(size, ' ');
		ft_putstr("0x");
		ft_putstr(ft_memory(varg));
	}
}

void	star_neg_calcul_p(size_t varg, int first)
{
	int		size;

	size = 0;
	if (varg == 0)
	{
		size = first - ft_strlen(ft_memory(varg)) - 1;
		ft_putstr("0x");
		ft_calculate(size, ' ');
	}
	else
	{
		ft_putstr("0x");
		ft_putstr(ft_memory(varg));
		size = first - ft_strlen(ft_memory(varg)) - 2;
		ft_calculate(size, ' ');
	}
}

void	star_min_precision_p(va_list arg, int i)
{
	int					first;
	unsigned long long	varg;

	first = va_arg(arg, int);
	varg = (unsigned long long)va_arg(arg, void *);
	if (first < 0)
		star_neg_calcul_p(varg, first * -1);
	else if (first >= 0)
	{
		if (i == 1)
			star_neg_calcul_p(varg, first);
		else
			star_calcul_p(varg, first);
	}
}
