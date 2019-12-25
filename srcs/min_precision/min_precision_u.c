/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 07:39:17 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:14 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_completion_u(va_list arg, char *first, char *traverse, char s_ind)
{
	unsigned int	varg;
	char			*second;
	int				size;

	size = 0;
	second = NULL;
	second = ft_fill(arg, second, ft_strchr(traverse, '.'), 'u');
	if (ft_atoi(first) < 0)
		neg_calcul_u(arg, first, second);
	else if (ft_atoi(first) >= 0 || ft_atoi(second) >= 0)
		calcul_u(arg, first, second, s_ind);
	else
	{
		varg = va_arg(arg, unsigned int);
		size = ft_atoi(traverse) - ft_strlen(ft_unsigned_itoa(varg));
		ft_calculate(size, ' ');
		ft_putunsignednbr(varg);
	}
}

void	min_precision_u(va_list arg, char *traverse)
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
	ft_completion_u(arg, first, traverse, star_indicator);
}
