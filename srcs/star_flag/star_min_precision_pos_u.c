/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_min_precision_pos_u.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:26:46 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:31 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_helper_calcul_u_2(unsigned int varg, int second, int size)
{
	ft_calculate(size, '0');
	if (varg == 0 && second == 0)
	{
		ft_putchar(' ');
		ft_putstr("");
	}
	else
		ft_putunsignednbr(varg);
}

void	star_calcul_u_2(unsigned int varg, int first, int second)
{
	int		size;

	size = 0;
	if (second == 0)
		size = first - ft_strlen(ft_unsigned_itoa(varg));
	else if (second != 0)
	{
		if (second < (int)ft_strlen(ft_unsigned_itoa(varg)))
			size = first - ft_strlen(ft_unsigned_itoa(varg));
		else
			size = first - second;
	}
	ft_calculate(size, ' ');
	size = second - ft_strlen(ft_unsigned_itoa(varg));
	star_helper_calcul_u_2(varg, second, size);
}

void	star_calcul_u_3(unsigned int varg, int first, int second)
{
	int					size;

	size = 0;
	if (first <= second)
	{
		size = second - ft_strlen(ft_unsigned_itoa(varg));
		ft_calculate(size, '0');
		ft_putunsignednbr(varg);
	}
}

void	star_calcul_u(va_list arg, int first, int second)
{
	unsigned int		varg;
	int					size;

	varg = va_arg(arg, unsigned int);
	size = 0;
	if (varg == 0 && first == 0 && second == 0)
		ft_putstr("");
	else if (first > second)
		star_calcul_u_2(varg, first, second);
	else if (first <= second && first != 0 && second != 0)
		star_calcul_u_3(varg, first, second);
	else if (first <= second)
		star_calcul_u_3(varg, first, second);
}
