/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_s_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 07:34:39 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:07 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	min_precision_s_2_helper(char *varg, char *first, char *second)
{
	int		size;

	size = 0;
	if ((size_t)ft_atoi(first) >= ft_strlen(varg))
	{
		size = ft_atoi(first) - ft_strlen(varg);
		ft_calculate(size, ' ');
	}
	if ((size_t)ft_atoi(second) <= ft_strlen(varg))
	{
		size = ft_atoi(second);
		while (size)
		{
			ft_putchar(*varg++);
			size--;
		}
	}
}

void	min_precision_s_2_helper_2(char *varg, char *first, char *second)
{
	int		size;

	size = 0;
	(void)first;
	if ((size_t)ft_atoi(second) > ft_strlen(varg))
	{
		size = ft_strlen(varg);
		while (size)
		{
			ft_putchar(*varg++);
			size--;
		}
	}
}

void	min_precision_s_2(char *varg, char *first, char *second)
{
	if ((ft_atoi(first) > 0) && ft_atoi(first) <= ft_atoi(second))
	{
		min_precision_s_2_helper(varg, first, second);
		min_precision_s_2_helper_2(varg, first, second);
	}
}
