/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_precision_s_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 07:36:46 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:10 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	min_precision_s_3_helper(char *varg, char *first, char *second)
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

void	min_precision_s_3_helper_2(char *first, char *second, int temp)
{
	int		size;

	size = 0;
	if ((ft_atoi(first) * -1) >= ft_atoi(second))
	{
		if (((ft_atoi(first) * -1) >= temp) && ft_atoi(second) >= temp)
			size = (ft_atoi(first) * -1) - temp;
		if (((ft_atoi(first) * -1) >= temp) && ft_atoi(second) < temp)
			size = (ft_atoi(first) * -1) - ft_atoi(second);
		if ((ft_atoi(first) * -1) < temp)
			size = (ft_atoi(first) * -1) - ft_atoi(second);
		ft_calculate(size, ' ');
	}
	else if ((ft_atoi(first) * -1) < ft_atoi(second))
	{
		if ((ft_atoi(first) * -1) > temp)
			size = (ft_atoi(first) * -1) - temp;
		ft_calculate(size, ' ');
	}
}

void	min_precision_s_3(char *varg, char *first, char *second)
{
	int		size;
	int		temp;

	size = 0;
	temp = (int)ft_strlen(varg);
	if (ft_atoi(first) < 0)
	{
		min_precision_s_3_helper(varg, first, second);
		min_precision_s_3_helper_2(first, second, temp);
	}
}
