/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:35:43 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:08:08 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_search(char *traverse)
{
	int		indicator;
	int		i;

	indicator = 0;
	i = 0;
	if (*(traverse + i) == '*')
		return (1);
	traverse++;
	while (*(traverse + i) != 'd' && *(traverse + i) != 'i'
		&& *(traverse + i) != 's' && *(traverse + i) != 'c'
		&& *(traverse + i) != 'u' && *(traverse + i) != 'x'
		&& *(traverse + i) != 'X' && *(traverse + i) != 'p')
	{
		if (*(traverse + i) == '*')
		{
			indicator = 1;
			return (indicator);
		}
		else if (ft_atoi(traverse) > 0)
			return (indicator);
		i++;
	}
	return (indicator);
}
