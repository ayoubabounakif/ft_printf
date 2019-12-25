/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_width_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 06:08:50 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:25 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	min_width_x_87(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, int);
	size = ft_atoi(traverse) - ft_strlen(ft_hex_87(varg));
	ft_calculate(size, ' ');
	ft_putstr(ft_hex_87((varg)));
}

void	min_width_x_55(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, int);
	size = ft_atoi(traverse) - ft_strlen(ft_hex_55(varg));
	ft_calculate(size, ' ');
	ft_putstr(ft_hex_55((varg)));
}

void	min_width_p(va_list arg, char *traverse)
{
	int						size;
	unsigned long long		varg;

	size = 0;
	varg = (unsigned long long)va_arg(arg, void *);
	size = ft_atoi(traverse) - (ft_strlen(ft_memory(varg)) + 2);
	ft_calculate(size, ' ');
	ft_putstr("0x");
	ft_putstr(ft_memory(varg));
}
