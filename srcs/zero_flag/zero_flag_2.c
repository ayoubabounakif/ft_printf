/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_flag_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 06:32:37 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:09:05 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_flag_x_87(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, int);
	size = ft_atoi(traverse) - ft_strlen(ft_hex_87(varg));
	ft_calculate(size, '0');
	ft_putstr(ft_hex_87((varg)));
}

void	zero_flag_x_55(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, int);
	size = ft_atoi(traverse) - ft_strlen(ft_hex_55(varg));
	ft_calculate(size, '0');
	ft_putstr(ft_hex_55((varg)));
}

void	zero_flag_p(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, int);
	size = ft_atoi(traverse) - (ft_strlen(ft_itoa(varg)) + 4);
	ft_putstr("0x");
	ft_calculate(size, '0');
	ft_putstr("777f");
	ft_putstr(ft_hex_87((varg)));
}
