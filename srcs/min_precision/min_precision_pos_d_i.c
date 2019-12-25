/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_pos_d_i.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 07:56:01 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:58 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	helper_calcul_2(int varg, char *second, int size, int indicator)
{
	if (indicator == 1)
		ft_putchar('-');
	ft_calculate(size, '0');
	if (varg == 0 && ft_atoi(second) == 0)
	{
		ft_putchar(' ');
		ft_putstr("");
	}
	else
		ft_putnbr(varg);
}

int		calcul_size(int varg, char *first, char *second, int indicator)
{
	int		size;

	size = 0;
	if (ft_atoi(second) == 0)
		size = ft_atoi(first) - ft_strlen(ft_itoa(varg));
	else if (ft_atoi(second) != 0)
	{
		if (ft_atoi(second) < (int)ft_strlen(ft_itoa(varg)))
			size = ft_atoi(first) - ft_strlen(ft_itoa(varg));
		else
			size = ft_atoi(first) - ft_atoi(second);
	}
	if (indicator == 1 || (indicator == 1 && ft_atoi(second) < 0))
		size--;
	(void)indicator;
	return (size);
}

void	calcul_2(int varg, char *first, char *second, int star_indicator)
{
	int		indicator;
	int		size;

	size = 0;
	indicator = 0;
	if (varg < 0)
	{
		indicator = 1;
		varg *= -1;
	}
	size = calcul_size(varg, first, second, indicator);
	if (star_indicator == 1 && ft_atoi(second) < 0)
	{
		if (indicator == 1)
		{
			indicator = 0;
			ft_putchar('-');
		}
		ft_calculate(size, '0');
	}
	else
		ft_calculate(size, ' ');
	size = ft_atoi(second) - ft_strlen(ft_itoa(varg));
	helper_calcul_2(varg, second, size, indicator);
}

void	calcul_3(int varg, char *first, char *second)
{
	int		size;

	size = 0;
	if (varg == 0 && ft_atoi(first) == 0 && ft_atoi(second) == 0)
		ft_putchar('\0');
	else if (ft_atoi(first) <= ft_atoi(second))
	{
		if (varg < 0)
		{
			ft_putchar('-');
			varg *= -1;
		}
		size = ft_atoi(second) - ft_strlen(ft_itoa(varg));
		ft_calculate(size, '0');
		ft_putnbr(varg);
	}
}

void	calcul(va_list arg, char *first, char *second, int star_indicator)
{
	int		varg;
	int		size;
	int		indicator;

	varg = va_arg(arg, int);
	size = 0;
	indicator = 0;
	if (ft_atoi(first) > ft_atoi(second))
		calcul_2(varg, first, second, star_indicator);
	else
		calcul_3(varg, first, second);
}
