/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_min_precision_d_i.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 06:01:38 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:13 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_star_completion_d_i(va_list arg, int first, char *fmt)
{
	int		second;
	int		search;

	search = ft_search(ft_strchr(fmt, '.'));
	if (search == 1)
		second = va_arg(arg, int);
	else if (search == 0)
		second = ft_atoi(ft_strchr(fmt, '.'));
	if (first < 0)
		star_neg_calcul(arg, first, second);
	else if (first >= 0 || second >= 0)
		star_calcul(arg, first, second);
}

void	star_min_precision_d_i(va_list arg, char *traverse, int i)
{
	int		first;
	int		j;

	j = 0;
	while (*(traverse + j) != '.')
	{
		if (*(traverse + j) == '*')
		{
			first = va_arg(arg, int);
			break ;
		}
		else
			first = ft_atoi(traverse);
		j++;
	}
	if (i == 1 && first >= 0)
		first *= -1;
	ft_star_completion_d_i(arg, first, traverse);
}
