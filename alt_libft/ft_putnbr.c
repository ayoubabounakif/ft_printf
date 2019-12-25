/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:30:32 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:05:45 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	int		size;
	int		temp;

	size = 1;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	if (n < 0 && n != -2147483648)
	{
		ft_putchar('-');
		n = -n;
	}
	temp = n;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = n;
	while (size && n != -2147483648)
	{
		ft_putchar((temp / size) + '0');
		temp %= size;
		size /= 10;
	}
}
