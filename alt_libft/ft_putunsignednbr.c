/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:57:34 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:05:50 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsignednbr(unsigned int n)
{
	unsigned int	size;
	unsigned int	temp;

	size = 1;
	temp = n;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = n;
	while (size)
	{
		ft_putchar((temp / size) + '0');
		temp %= size;
		size /= 10;
	}
}
