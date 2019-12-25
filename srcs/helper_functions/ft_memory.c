/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:49:34 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:31 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int	g_error;

static char		*ft_calculate_memory(unsigned long long decimal, char *hex)
{
	unsigned long long	remaining;
	int					i;

	i = 0;
	if (decimal == 0)
	{
		hex[i] = '0';
		i++;
	}
	while (decimal)
	{
		remaining = decimal % 16;
		if (remaining > 9)
			hex[i] = (char)(remaining + 87);
		else
			hex[i] = (char)(remaining + 48);
		decimal /= 16;
		i++;
	}
	hex[i] = '\0';
	ft_strrev(hex);
	return (hex);
}

char			*ft_memory(unsigned long long d)
{
	char				*hex;
	int					i;
	unsigned long long	decimal;

	i = 0;
	decimal = d;
	while (decimal /= 16)
		i++;
	decimal = d;
	if (decimal == 0)
		i++;
	if (!(hex = malloc(i + 2)))
	{
		g_error = -1;
		return (NULL);
	}
	hex = ft_calculate_memory(decimal, hex);
	return (hex);
}
