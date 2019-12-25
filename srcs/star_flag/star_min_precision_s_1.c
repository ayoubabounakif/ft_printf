/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_min_precision_s_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:59:45 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:39 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_min_precision_s_1_helper(char *varg, int first, int second)
{
	int		size;

	size = 0;
	if (second == 0)
		size = first;
	else if ((size_t)second > ft_strlen(varg))
		size = first - ft_strlen(varg);
	else if ((size_t)second <= ft_strlen(varg))
		size = first - second;
	ft_calculate(size, ' ');
}

void	star_min_precision_s_1_helper_2(char *varg, int first, int second)
{
	int		size;

	size = 0;
	(void)first;
	if ((size_t)second <= ft_strlen(varg))
	{
		size = second;
		while (size)
		{
			ft_putchar(*varg++);
			size--;
		}
	}
	else if ((size_t)second > ft_strlen(varg))
	{
		size = ft_strlen(varg);
		while (size)
		{
			ft_putchar(*varg++);
			size--;
		}
	}
}

void	star_min_precision_s_1(char *varg, int first, int second, int i)
{
	if (i == 1)
	{
		star_min_precision_s_1_helper_2(varg, first, second);
		star_min_precision_s_1_helper(varg, first, second);
	}
	else if (first <= second && second < 0)
	{
		star_min_precision_s_1_helper_2(varg, first, second);
		star_min_precision_s_1_helper(varg, first * -1, second);
	}
	else if (first > second)
	{
		star_min_precision_s_1_helper(varg, first, second);
		star_min_precision_s_1_helper_2(varg, first, second);
	}
}
