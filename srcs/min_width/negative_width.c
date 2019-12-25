/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:53:00 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:33 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_a;

void	negative_width_s(va_list arg, char *traverse)
{
	int		size;
	char	*varg;

	size = 0;
	varg = va_arg(arg, char *);
	if (varg == NULL)
		varg = "(null)";
	size = (ft_atoi(traverse) * -1) - ft_strlen(varg);
	ft_putstr(varg);
	ft_calculate(size, ' ');
}

void	negative_width_c(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	varg = va_arg(arg, int);
	size = (ft_atoi(traverse) * -1) - 1;
	if (varg == 0 || varg == '\0')
		g_a++;
	ft_putchar(varg);
	ft_calculate(size, ' ');
}

void	negative_width_d_i(va_list arg, char *traverse)
{
	unsigned int	size;
	int				varg;

	size = 0;
	varg = va_arg(arg, int);
	size = (ft_atoi(traverse) * -1) - ft_strlen(ft_itoa(varg));
	ft_putnbr(varg);
	ft_calculate(size, ' ');
}

void	negative_width_u(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, int);
	size = (ft_atoi(traverse) * -1) - ft_strlen(ft_unsigned_itoa(varg));
	ft_putunsignednbr(varg);
	ft_calculate(size, ' ');
}

void	negative_width_percent(char *traverse)
{
	int		size;

	size = 0;
	size = (ft_atoi(traverse) * -1) - 1;
	ft_putchar('%');
	ft_calculate(size, ' ');
}
