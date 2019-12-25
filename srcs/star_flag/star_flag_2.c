/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_flag_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 06:24:01 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:59 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_a;

void	star_flag_s_2(int i, int size, char *varg_2)
{
	if (i == 0)
		ft_calculate(size, '0');
	else
		ft_calculate(size, ' ');
	ft_putstr(varg_2);
}

void	star_flag_s(va_list arg, int i)
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
	{
		size = (varg_1 * -1) - ft_strlen(varg_2);
		ft_putstr(varg_2);
		if (i == 0)
			ft_calculate(size, '0');
		else
			ft_calculate(size, ' ');
	}
	else
	{
		size = varg_1 - ft_strlen(varg_2);
		star_flag_s_2(i, size, varg_2);
	}
}

void	star_flag_c_2(int i, int size, int varg_2)
{
	if (i == 0)
		ft_calculate(size, '0');
	else
		ft_calculate(size, ' ');
	ft_putchar(varg_2);
}

void	star_flag_c(va_list arg, int i)
{
	int		size;
	int		varg_1;
	int		varg_2;

	size = 0;
	varg_1 = va_arg(arg, int);
	varg_2 = va_arg(arg, int);
	if (varg_2 == 0 || varg_2 == '\0')
		g_a++;
	if (varg_1 < 0)
	{
		size = (varg_1 * -1) - 1;
		ft_putchar(varg_2);
		if (i == 0)
			ft_calculate(size, '0');
		else
			ft_calculate(size, ' ');
	}
	else
	{
		size = varg_1 - 1;
		star_flag_c_2(i, size, varg_2);
	}
}
