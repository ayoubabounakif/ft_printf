/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_pos_u.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 07:44:26 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:00 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	helper_calcul_u_2(unsigned int varg, char *second, int size)
{
	ft_calculate(size, '0');
	if (varg == 0 && ft_atoi(second) == 0)
	{
		ft_putchar(' ');
		ft_putstr("");
	}
	else
		ft_putunsignednbr(varg);
}

void	calcul_u_2(unsigned int varg, char *first, char *second, int star_ind)
{
	int		size;

	size = 0;
	if (ft_atoi(second) == 0)
		size = ft_atoi(first) - ft_strlen(ft_unsigned_itoa(varg));
	else if (ft_atoi(second) != 0)
	{
		if (ft_atoi(second) < (int)ft_strlen(ft_unsigned_itoa(varg)))
			size = ft_atoi(first) - ft_strlen(ft_unsigned_itoa(varg));
		else
			size = ft_atoi(first) - ft_atoi(second);
	}
	if (star_ind == 1 && ft_atoi(second) < 0)
		ft_calculate(size, '0');
	else
		ft_calculate(size, ' ');
	size = ft_atoi(second) - ft_strlen(ft_unsigned_itoa(varg));
	helper_calcul_u_2(varg, second, size);
}

void	calcul_u_3(unsigned int varg, char *first, char *second)
{
	int					size;

	size = 0;
	if (ft_atoi(first) <= ft_atoi(second))
	{
		size = ft_atoi(second) - ft_strlen(ft_unsigned_itoa(varg));
		ft_calculate(size, '0');
		ft_putunsignednbr(varg);
	}
}

void	calcul_u(va_list arg, char *first, char *second, int star_indicator)
{
	unsigned int		varg;
	int					size;

	varg = va_arg(arg, unsigned int);
	size = 0;
	if (varg == 0 && ft_atoi(first) == 0 && ft_atoi(second) == 0)
		ft_putstr("");
	else if (ft_atoi(first) > ft_atoi(second))
		calcul_u_2(varg, first, second, star_indicator);
	else if (first <= second)
		calcul_u_3(varg, first, second);
}
