/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_width_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 06:10:33 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:31 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	negative_width_x_87(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, int);
	size = (ft_atoi(traverse) * -1) - ft_strlen(ft_hex_87(varg));
	ft_putstr(ft_hex_87((varg)));
	ft_calculate(size, ' ');
}

void	negative_width_x_55(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, int);
	size = (ft_atoi(traverse) * -1) - ft_strlen(ft_hex_55(varg));
	ft_putstr(ft_hex_55((varg)));
	ft_calculate(size, ' ');
}

void	negative_width_p(va_list arg, char *traverse)
{
	int			size;
	size_t		varg;

	size = 0;
	varg = (size_t)va_arg(arg, void *);
	size = (ft_atoi(traverse) * -1) - (ft_strlen(ft_memory(varg)) + 2);
	ft_putstr("0x");
	ft_putstr(ft_memory((varg)));
	ft_calculate(size, ' ');
}
