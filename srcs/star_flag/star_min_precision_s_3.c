/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_min_precision_s_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:58:26 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:44 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_min_precision_s_3_helper(char *varg, int first, int second)
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

void	star_min_precision_s_3_helper_2(int first, int second, int temp)
{
	int		size;

	size = 0;
	if ((first * -1) < (second * -1))
	{
		if ((first * -1) > temp)
			size = (first * -1) - temp;
		ft_calculate(size, ' ');
	}
	else if ((first * -1) >= second)
	{
		if (((first * -1) >= temp) && second >= temp)
			size = (first * -1) - temp;
		if (((first * -1) >= temp) && second < temp)
			size = (first * -1) - second;
		if ((first * -1) < temp)
			size = (first * -1) - second;
		ft_calculate(size, ' ');
	}
	else if ((first * -1) < second)
	{
		if ((first * -1) > temp)
			size = (first * -1) - temp;
		ft_calculate(size, ' ');
	}
}

void	star_min_precision_s_3(char *varg, int first, int second)
{
	int		size;
	int		temp;

	size = 0;
	temp = (int)ft_strlen(varg);
	if (first < 0 && second >= 0)
	{
		star_min_precision_s_3_helper(varg, first, second);
		star_min_precision_s_3_helper_2(first, second, temp);
	}
	else if ((first < 0 && second < 0) && first > second)
		star_min_precision_s_3_helper_2(first, second, temp);
}
