/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 07:34:18 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:12 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	min_precision_s_1_helper(char *varg, char *first, char *second)
{
	int		size;

	size = 0;
	if (ft_atoi(second) == 0)
		size = ft_atoi(first);
	else if ((size_t)ft_atoi(second) > ft_strlen(varg))
		size = ft_atoi(first) - ft_strlen(varg);
	else if ((size_t)ft_atoi(second) <= ft_strlen(varg))
		size = ft_atoi(first) - ft_atoi(second);
	ft_calculate(size, ' ');
}

void	min_precision_s_1_helper_2(char *varg, char *first, char *second)
{
	int		size;

	size = 0;
	(void)first;
	if ((size_t)ft_atoi(second) <= ft_strlen(varg))
	{
		size = ft_atoi(second);
		while (size)
		{
			ft_putchar(*varg++);
			size--;
		}
	}
	else if ((size_t)ft_atoi(second) > ft_strlen(varg))
	{
		size = ft_strlen(varg);
		while (size)
		{
			ft_putchar(*varg++);
			size--;
		}
	}
}

void	min_precision_s_1(char *varg, char *first, char *second)
{
	if (ft_atoi(first) > ft_atoi(second))
	{
		min_precision_s_1_helper(varg, first, second);
		min_precision_s_1_helper_2(varg, first, second);
	}
}

void	min_precision_s(va_list arg, char *traverse)
{
	char	*first;
	char	*second;
	char	*varg;

	first = NULL;
	second = NULL;
	first = fill(first, traverse, '.');
	second = fill(second, ft_strchr(traverse, '.'), 's');
	varg = va_arg(arg, char *);
	if (varg == NULL)
		varg = "(null)";
	if (ft_atoi(first) == 0 && ft_atoi(second) != 0 && ft_strlen(varg) > 0)
		first = "1";
	if (ft_atoi(first) != 0 && ft_atoi(second) >= 0)
	{
		min_precision_s_1(varg, first, second);
		min_precision_s_2(varg, first, second);
		min_precision_s_3(varg, first, second);
	}
}
