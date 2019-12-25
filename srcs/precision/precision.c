/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:35:49 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:48 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_d_i_1(va_list arg, char *traverse)
{
	int		varg;
	int		size;

	size = 0;
	varg = va_arg(arg, int);
	if (varg == 0)
		ft_putstr("");
	else
	{
		size = ft_atoi(traverse) - ft_strlen(ft_itoa(varg));
		ft_calculate(size, '0');
		ft_putnbr(varg);
	}
}

int		precision_d_i_2_helper(int first_arg, int second_arg)
{
	int		size;

	size = 0;
	if (first_arg <= 0 && second_arg != 0)
	{
		ft_putnbr(second_arg);
		return (1);
	}
	else if (first_arg > 0 && second_arg > 0)
	{
		size = first_arg - ft_strlen(ft_itoa(second_arg));
		ft_calculate(size, '0');
		ft_putnbr(second_arg);
		return (1);
	}
	return (0);
}

void	precision_d_i_2_helper_2(int first_arg, int second_arg, int indicator)
{
	int		size;

	size = 0;
	if (second_arg == 0 && indicator == 0)
	{
		if (first_arg == 0)
			ft_putstr("");
		else
		{
			size = first_arg - ft_strlen(ft_itoa(second_arg));
			ft_calculate(size, '0');
			ft_putnbr(second_arg);
		}
	}
	else if (second_arg < 0 && indicator == 0)
	{
		size = first_arg - ft_strlen(ft_itoa(second_arg));
		ft_putchar('-');
		size++;
		ft_calculate(size, '0');
		if (second_arg == INT32_MIN)
			ft_putunsignednbr(INT32_MIN);
		else
			ft_putnbr(second_arg * -1);
	}
}

void	precision_d_i_2(va_list arg)
{
	int		first_arg;
	int		second_arg;
	int		size;
	int		indicator;

	size = 0;
	first_arg = va_arg(arg, int);
	second_arg = va_arg(arg, int);
	indicator = precision_d_i_2_helper(first_arg, second_arg);
	precision_d_i_2_helper_2(first_arg, second_arg, indicator);
}

void	precision_d_i(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	size = 0;
	traverse++;
	if (*traverse == '*')
		precision_d_i_2(arg);
	else if (*traverse == 'd' || *traverse == 'i' || ft_atoi(traverse) == 0)
		precision_d_i_1(arg, traverse);
	else
	{
		varg = va_arg(arg, int);
		if (varg < 0)
		{
			ft_putchar('-');
			varg *= -1;
			size++;
		}
		size = ft_atoi(traverse) - ft_strlen(ft_itoa(varg));
		ft_calculate(size, '0');
		ft_putunsignednbr(varg);
	}
}
