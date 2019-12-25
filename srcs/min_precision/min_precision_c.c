/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 07:08:36 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:40 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int	g_a;

void	min_precision_c_helper(va_list arg, char *traverse)
{
	int		size;

	size = ft_atoi(traverse) - 1;
	ft_calculate(size, ' ');
	ft_putchar(va_arg(arg, int));
}

void	min_precision_c(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, int);
	if (varg == 0 || varg == '\0')
		g_a++;
	if (ft_atoi(traverse) > 0)
	{
		size = ft_atoi(traverse) - 1;
		ft_calculate(size, ' ');
		ft_putchar(varg);
	}
	else
	{
		size = (ft_atoi(traverse) * -1) - 1;
		ft_putchar(varg);
		ft_calculate(size, ' ');
	}
}
