/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_min_precision_s.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 06:00:45 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:46 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_completion_s_first(va_list arg, char *fmt)
{
	int		j;
	int		first;

	j = 0;
	while (*(fmt + j) != '.')
	{
		if (*(fmt + j) == '*')
		{
			first = va_arg(arg, int);
			break ;
		}
		else
			first = ft_atoi(fmt);
		j++;
	}
	return (first);
}

void	ft_star_completion_s(char *varg, int first, int second, int i)
{
	if (first == 0 && second != 0 && ft_strlen(varg) > 0)
		first = 1;
	if (first != 0 && second >= 0)
	{
		if (i == 1)
		{
			star_min_precision_s_2(varg, first * -1, second);
			star_min_precision_s_3(varg, first * -1, second);
		}
		else
		{
			star_min_precision_s_1(varg, first, second, i);
			star_min_precision_s_2(varg, first, second);
			star_min_precision_s_3(varg, first, second);
		}
	}
}

void	ft_star_completion_s_2(char *varg, int first, int second, int i)
{
	if (first == 0 && second != 0 && ft_strlen(varg) > 0)
		first = 1;
	if (first != 0 && second < 0)
	{
		if (first < 0 && second < 0 && ft_strlen(varg) == 0)
			ft_calculate((first * -1) - ft_strlen(varg), ' ');
		else if ((first < 0 && second < 0) ||
				(first < 0 && second < 0 && first == second))
			star_min_precision_s_1(varg, first, second, i);
		else
		{
			star_min_precision_s_1(varg, first, second, i);
			star_min_precision_s_2(varg, first, second);
			star_min_precision_s_3(varg, first, second);
		}
	}
}

void	star_min_precision_s(va_list arg, char *traverse, int i)
{
	int		first;
	int		second;
	int		search;
	char	*varg;

	second = 0;
	first = ft_completion_s_first(arg, traverse);
	if (i == 1 && first < 0)
		first *= -1;
	search = ft_search(ft_strchr(traverse, '.'));
	if (search == 1)
		second = va_arg(arg, int);
	else
		second = ft_atoi(ft_strchr(traverse, '.'));
	varg = va_arg(arg, char *);
	if (varg == NULL)
		varg = "(null)";
	ft_star_completion_s(varg, first, second, i);
	ft_star_completion_s_2(varg, first, second, i);
}
