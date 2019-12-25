/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_min_precision_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:21:00 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:11 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_a;

void	star_min_precision_c_helper(va_list arg, char *traverse)
{
	int		size;

	size = ft_atoi(traverse) - 1;
	ft_calculate(size, ' ');
	ft_putchar(va_arg(arg, int));
}

void	ft_star_completion_c(int first, int second)
{
	int		size;

	size = 0;
	if (second == 0 || second == '\0')
		g_a++;
	if (first > 0)
	{
		size = first - 1;
		ft_calculate(size, ' ');
		ft_putchar(second);
	}
	else
	{
		size = (first * -1) - 1;
		ft_putchar(second);
		ft_calculate(size, ' ');
	}
}

void	star_min_precision_c(va_list arg, char *traverse, int i)
{
	int		first;
	int		second;
	int		search;

	first = va_arg(arg, int);
	if (i == 1 && first > 0)
		first *= -1;
	second = 0;
	search = ft_search(traverse);
	if (search == 1)
		second = va_arg(arg, int);
	else if (search == 0)
		second = ft_atoi(traverse);
	ft_star_completion_c(first, second);
}
