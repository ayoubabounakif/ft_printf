/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_width_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:05:50 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:27 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_min_width_percent_arg(int varg, char *traverse, int j, int ind)
{
	int		size;

	size = 0;
	if (*traverse == '-')
	{
		size = varg + j - 1;
		size *= -1;
		ft_putchar('%');
		ft_calculate(size, ' ');
	}
	else
	{
		size = varg - 1;
		ft_putchar('%');
		if (*traverse == '0' && ind == 0)
			ft_calculate(size, '0');
		else
			ft_calculate(size, ' ');
	}
}

void	min_width_percent_arg(va_list arg, char *traverse, int j)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, int);
	if (varg < 0)
		star_min_width_percent_arg(varg * -1, traverse, j, 1);
	else if (*traverse == '-')
	{
		size = varg + j - 1;
		size *= -1;
		ft_putchar('%');
		ft_calculate(size, ' ');
	}
	else
	{
		size = varg - 1;
		if (*traverse == '0')
			ft_calculate(size, '0');
		else
			ft_calculate(size, ' ');
		ft_putchar('%');
	}
}

void	min_width_percent_helper(va_list arg, char *traverse, int j, int s)
{
	if (ft_strchr(traverse, '*') == 0)
	{
		if (*traverse == '-')
		{
			s = ft_atoi(traverse) + j;
			s *= -1;
			ft_putchar('%');
			ft_calculate(s, ' ');
		}
		else
		{
			s = ft_atoi(traverse) - 1;
			if (*traverse == '0')
				ft_calculate(s, '0');
			else
				ft_calculate(s, ' ');
			ft_putchar('%');
		}
	}
	else if ((s = where_star(traverse)) == '>')
		ft_putchar('%');
	else
		min_width_percent_arg(arg, traverse, j);
}

void	min_width_percent(va_list arg, char *traverse)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = 0;
	while (*(traverse + i) != '%')
		i++;
	while (*(traverse + i) != '\0')
	{
		j++;
		i++;
	}
	if (j > 1)
		min_width_percent_helper(arg, traverse, j - 1, size);
	else
		min_width_percent_helper(arg, traverse, j, size);
}
