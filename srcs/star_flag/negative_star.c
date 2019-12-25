/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_star.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:22:35 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:56 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	negative_star_flag_s(va_list arg)
{
	int		size;
	int		varg_1;
	char	*varg_2;

	size = 0;
	varg_1 = va_arg(arg, int);
	varg_2 = va_arg(arg, char *);
	if (varg_2 == NULL)
		varg_2 = "(null)";
	if (varg_1 < 0)
		varg_1 *= -1;
	size = varg_1 - ft_strlen(varg_2);
	ft_putstr(varg_2);
	ft_calculate(size, ' ');
}

void	negative_star_flag_c(va_list arg)
{
	int		size;
	int		varg_1;
	int		varg_2;

	size = 0;
	varg_1 = va_arg(arg, int);
	varg_2 = va_arg(arg, int);
	if (varg_1 < 0)
		varg_1 *= -1;
	size = varg_1 - 1;
	ft_putchar(varg_2);
	ft_calculate(size, ' ');
}

void	negative_star_flag_d_i(va_list arg)
{
	int		size;
	int		varg_1;
	int		varg_2;

	size = 0;
	varg_1 = va_arg(arg, int);
	varg_2 = va_arg(arg, int);
	if (varg_1 < 0)
		varg_1 *= -1;
	size = varg_1 - ft_strlen(ft_itoa(varg_2));
	ft_putnbr(varg_2);
	ft_calculate(size, ' ');
}

void	negative_star_flag_u(va_list arg)
{
	int		size;
	int		varg_1;
	int		varg_2;

	size = 0;
	varg_1 = va_arg(arg, int);
	varg_2 = va_arg(arg, unsigned int);
	if (varg_1 < 0)
		varg_1 *= -1;
	size = varg_1 - ft_strlen(ft_unsigned_itoa(varg_2));
	ft_putunsignednbr(varg_2);
	ft_calculate(size, ' ');
}

void	negative_star_flag_percent(va_list arg)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, int);
	if (varg < 0)
		varg *= -1;
	size = varg - 1;
	ft_putchar('%');
	ft_calculate(size, ' ');
}
