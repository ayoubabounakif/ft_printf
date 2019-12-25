/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:09:21 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:09:04 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_flag_s(va_list arg, char *traverse)
{
	int		size;
	char	*varg;

	size = 0;
	varg = va_arg(arg, char *);
	if (varg == NULL)
		varg = "(null)";
	size = ft_atoi(traverse) - ft_strlen(varg);
	ft_calculate(size, '0');
	ft_putstr(varg);
}

void	zero_flag_c(va_list arg, char *traverse)
{
	int		size;

	size = ft_atoi(traverse) - 1;
	ft_calculate(size, '0');
	ft_putchar(va_arg(arg, int));
}

void	zero_flag_d_i(va_list arg, char *traverse)
{
	int		size;
	int		varg;
	int		indicator;

	size = 0;
	indicator = 0;
	varg = va_arg(arg, int);
	if (varg < 0)
	{
		ft_putchar('-');
		varg *= -1;
		indicator = 1;
	}
	size = ft_atoi(traverse) - ft_strlen(ft_itoa(varg));
	if (indicator == 1)
		size = size - 1;
	ft_calculate(size, '0');
	if (varg < 0)
		ft_putunsignednbr(varg);
	else
		ft_putnbr(varg);
}

void	zero_flag_u(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, unsigned int);
	size = ft_atoi(traverse) - ft_strlen(ft_unsigned_itoa(varg));
	ft_calculate(size, '0');
	ft_putunsignednbr(varg);
}

void	zero_flag_percent(char *traverse)
{
	int		size;

	size = 0;
	size = ft_atoi(traverse) - 1;
	ft_calculate(size, '0');
	ft_putchar('%');
}
