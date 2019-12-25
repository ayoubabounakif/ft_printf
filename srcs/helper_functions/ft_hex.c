/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:46:10 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:26 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_error;

static char		*ft_calculate_x(unsigned int decimal, char *hex, int c)
{
	int		remaining;
	int		i;

	i = 0;
	while (decimal != 0)
	{
		remaining = decimal % 16;
		if (remaining > 9)
			hex[i] = (char)(remaining + c);
		else
			hex[i] = (char)(remaining + 48);
		decimal /= 16;
		i++;
	}
	hex[i] = '\0';
	ft_strrev(hex);
	return (hex);
}

char			*ft_hex_55(int d)
{
	char			*hex;
	int				i;
	unsigned int	decimal;

	i = 0;
	decimal = (unsigned int)d;
	if (decimal == 0)
		return (ft_strdup("0"));
	while (decimal /= 16)
		i++;
	decimal = (unsigned int)d;
	if (!(hex = malloc(i + 2)))
	{
		g_error = -1;
		return (NULL);
	}
	hex = ft_calculate_x(decimal, hex, 55);
	return (hex);
}

char			*ft_hex_87(int d)
{
	char			*hex;
	int				i;
	unsigned int	decimal;

	i = 0;
	decimal = (unsigned int)d;
	if (decimal == 0)
		return (ft_strdup("0"));
	while (decimal /= 16)
		i++;
	decimal = (unsigned int)d;
	if (!(hex = malloc(i + 2)))
	{
		g_error = -1;
		return (NULL);
	}
	hex = ft_calculate_x(decimal, hex, 87);
	return (hex);
}
