/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 06:48:04 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:43 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_u_2(va_list arg)
{
	int		first_arg;
	int		second_arg;
	int		size;

	size = 0;
	first_arg = va_arg(arg, int);
	second_arg = va_arg(arg, unsigned int);
	if (first_arg == 0 && second_arg == 0)
		ft_putstr("");
	else if (first_arg <= 0)
		ft_putunsignednbr(second_arg);
	size = first_arg - ft_strlen(ft_unsigned_itoa(second_arg));
	if (second_arg < 0)
		size--;
	ft_calculate(size, '0');
	if (first_arg > 0)
		ft_putunsignednbr(second_arg);
}

void	precision_u_1(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	varg = va_arg(arg, unsigned int);
	if (varg == 0)
		ft_putstr("");
	else
	{
		size = ft_atoi(traverse) - ft_strlen(ft_unsigned_itoa(varg));
		ft_calculate(size, '0');
		ft_putunsignednbr(varg);
	}
}

void	precision_u(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	traverse++;
	if (*traverse == '*')
		precision_u_2(arg);
	else if (*traverse == 'u' || ft_atoi(traverse) == 0)
		precision_u_1(arg, traverse);
	else
	{
		varg = va_arg(arg, unsigned int);
		size = ft_atoi(traverse) - ft_strlen(ft_unsigned_itoa(varg));
		ft_calculate(size, '0');
		ft_putunsignednbr(varg);
	}
}
