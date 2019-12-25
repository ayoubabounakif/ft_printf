/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_min_precision_s_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:58:21 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:41 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_min_precision_s_2_helper(char *varg, int first, int second)
{
	int		size;

	size = 0;
	if ((size_t)first >= ft_strlen(varg))
	{
		size = first - ft_strlen(varg);
		ft_calculate(size, ' ');
	}
	if ((size_t)second <= ft_strlen(varg))
	{
		size = second;
		while (size)
		{
			ft_putchar(*varg++);
			size--;
		}
	}
}

void	star_min_precision_s_2_helper_2(char *varg, int first, int second)
{
	int		size;

	size = 0;
	(void)first;
	if ((size_t)second > ft_strlen(varg))
	{
		size = ft_strlen(varg);
		while (size)
		{
			ft_putchar(*varg++);
			size--;
		}
	}
}

void	star_min_precision_s_2(char *varg, int first, int second)
{
	if ((first > 0) && first <= second)
	{
		star_min_precision_s_2_helper(varg, first, second);
		star_min_precision_s_2_helper_2(varg, first, second);
	}
}
