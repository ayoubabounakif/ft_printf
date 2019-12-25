/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_x_87.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 07:29:37 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:19 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_completion_x_87(va_list arg, char *first, char *traverse, int s_i)
{
	int		size;
	int		varg;
	char	*second;

	size = 0;
	second = NULL;
	second = ft_fill(arg, second, ft_strchr(traverse, '.'), 'x');
	if (ft_atoi(first) < 0)
		neg_calcul_x_87(arg, first, second);
	else if (ft_atoi(first) >= 0 || ft_atoi(second) >= 0)
		calcul_x_87(arg, first, second, s_i);
	else
	{
		varg = va_arg(arg, unsigned int);
		size = ft_atoi(traverse) - ft_strlen(ft_hex_87(varg));
		ft_calculate_hex(size, ' ');
		ft_putstr(ft_hex_87((varg)));
	}
}

void	min_precision_x_87(va_list arg, char *traverse)
{
	int				size;
	int				star_indicator;
	char			*first;

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
	ft_completion_x_87(arg, first, traverse, star_indicator);
}
