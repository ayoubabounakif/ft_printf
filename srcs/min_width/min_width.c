/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:42:08 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:29 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_a;

void	min_width_s(va_list arg, char *traverse)
{
	int		size;
	char	*varg;

	size = 0;
	varg = va_arg(arg, char *);
	if (varg == NULL)
		varg = "(null)";
	size = ft_atoi(traverse) - ft_strlen(varg);
	ft_calculate(size, ' ');
	ft_putstr(varg);
}

void	min_width_c(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	varg = va_arg(arg, int);
	size = ft_atoi(traverse) - 1;
	ft_calculate(size, ' ');
	if (varg == 0 || varg == '\0')
		g_a++;
	ft_putchar(varg);
}

void	min_width_d_i(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, int);
	size = ft_atoi(traverse) - ft_strlen(ft_itoa(varg));
	ft_calculate(size, ' ');
	ft_putnbr(varg);
}

void	min_width_u(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, unsigned int);
	size = ft_atoi(traverse) - ft_strlen(ft_unsigned_itoa(varg));
	ft_calculate(size, ' ');
	ft_putunsignednbr(varg);
}
