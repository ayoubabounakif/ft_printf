/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_s_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 06:48:41 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:41 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_a;

void	precision_c(va_list arg, char *traverse)
{
	int		size;
	int		varg;

	varg = va_arg(arg, int);
	size = 0;
	size = ft_atoi(traverse) - 1;
	ft_calculate(size, 0);
	if (varg == 0 || varg == '\0')
		g_a++;
	ft_putchar(varg);
}

void	precision_s_2_helper(int first_arg, char *second_arg)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (first_arg < 0)
	{
		size = ft_strlen(second_arg);
		while (i < size)
		{
			ft_putchar(second_arg[i]);
			i++;
		}
	}
	else if (first_arg > 0)
	{
		size = first_arg;
		while (i < size && i < ft_strlen(second_arg))
		{
			ft_putchar(second_arg[i]);
			i++;
		}
	}
}

void	precision_s_2(va_list arg)
{
	int		first_arg;
	char	*second_arg;
	size_t	i;

	i = 0;
	first_arg = va_arg(arg, int);
	second_arg = va_arg(arg, char *);
	if (second_arg == NULL)
		second_arg = "(null)";
	precision_s_2_helper(first_arg, second_arg);
}

void	precision_s(va_list arg, char *traverse)
{
	size_t	size;
	size_t	i;
	char	*varg;

	i = 0;
	size = 0;
	traverse++;
	if (*traverse == '*')
		precision_s_2(arg);
	varg = va_arg(arg, char *);
	if (varg == NULL)
		varg = "(null)";
	if (*traverse == 's' || ft_atoi(traverse) == 0)
		ft_putstr("");
	else
	{
		size = ft_atoi(traverse);
		while (i < size && i < ft_strlen(varg))
		{
			ft_putchar(varg[i]);
			i++;
		}
	}
}
