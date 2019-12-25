/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_d_i.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:22:29 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:43 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_completion_d_i(va_list arg, char *first, char *fmt, int s_ind)
{
	char	*second;
	int		varg;
	int		size;

	size = 0;
	second = NULL;
	second = ft_fill(arg, second, ft_strchr(fmt, '.'), 'd');
	if (ft_atoi(first) < 0)
		neg_calcul(arg, first, second);
	else if (ft_atoi(first) >= 0 || ft_atoi(second) >= 0)
		calcul(arg, first, second, s_ind);
	else
	{
		varg = va_arg(arg, int);
		size = ft_atoi(fmt) - ft_strlen(ft_itoa(varg));
		ft_calculate(size, ' ');
		ft_putnbr(varg);
	}
}

void	min_precision_d_i(va_list arg, char *traverse)
{
	int		size;
	int		star_indicator;
	char	*first;

	size = 0;
	star_indicator = 0;
	first = NULL;
	first = traverse;
	while (first[size] != '.')
	{
		if (first[size] == '*')
		{
			first = ft_itoa(va_arg(arg, int));
			star_indicator = 1;
			break ;
		}
		size++;
	}
	ft_completion_d_i(arg, first, traverse, star_indicator);
}
