/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_min_precision_percent.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:38:44 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:26 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_min_precision_percent_helper(char *traverse)
{
	int		size;

	size = ft_atoi(traverse) - 1;
	ft_calculate(size, ' ');
	ft_putchar('%');
}

void	ft_star_completion_percent(int first)
{
	int		size;

	size = 0;
	if (first > 0)
	{
		size = first - 1;
		ft_calculate(size, ' ');
		ft_putchar('%');
	}
	else
	{
		size = (first * -1) - 1;
		ft_putchar('%');
		ft_calculate(size, ' ');
	}
}

void	star_min_precision_percent(va_list arg, int i)
{
	int		first;

	first = va_arg(arg, int);
	if (i == 1 && first > 0)
		first *= -1;
	ft_star_completion_percent(first);
}
