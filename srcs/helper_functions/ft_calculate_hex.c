/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:40:34 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:16 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_calculate_hex(int size, char c)
{
	int		i;

	i = 0;
	if (size > 0)
	{
		while (size)
		{
			ft_putchar(c);
			i++;
			size--;
		}
	}
	return (i);
}
