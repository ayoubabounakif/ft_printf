/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 07:09:30 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:55 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	calcul_p(unsigned long long varg, char *first)
{
	int		size;

	size = 0;
	if (varg == 0)
	{
		size = ft_atoi(first) - ft_strlen(ft_memory(varg)) - 1;
		ft_calculate(size, ' ');
		ft_putstr("0x");
	}
	else
	{
		size = ft_atoi(first) - ft_strlen(ft_memory(varg)) - 2;
		ft_calculate(size, ' ');
		ft_putstr("0x");
		ft_putstr(ft_memory(varg));
	}
}

void	neg_calcul_p(unsigned long long varg, char *first)
{
	int		size;
	int		change;

	size = 0;
	change = ft_atoi(first) * -1;
	if (varg == 0)
	{
		size = change - ft_strlen(ft_memory(varg)) - 1;
		ft_putstr("0x");
		ft_calculate(size, ' ');
	}
	else
	{
		ft_putstr("0x");
		ft_putstr(ft_memory(varg));
		size = change - ft_strlen(ft_memory(varg)) - 2;
		ft_calculate(size, ' ');
	}
}

void	min_precision_p(va_list arg, char *traverse)
{
	char				*first;
	int					size;
	unsigned long long	varg;

	size = 0;
	first = NULL;
	first = fill(first, traverse, '.');
	varg = (unsigned long long)va_arg(arg, void *);
	if (ft_atoi(first) < 0)
		neg_calcul_p(varg, first);
	else if (ft_atoi(first) >= 0)
		calcul_p(varg, first);
}
