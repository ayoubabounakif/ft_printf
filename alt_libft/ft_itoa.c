/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:55:21 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:05:41 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int	g_error;

static int	find_size(int nb)
{
	int		size;

	size = 1;
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	while (((nb /= 10) > 0))
		size *= 10;
	return (size);
}

static int	find_digits(int n)
{
	int		i;

	i = 0;
	if (n == 0)
	{
		i++;
		return (i);
	}
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*alloc(char *str, int n)
{
	if (!(str = (char *)malloc(sizeof(char) * (find_digits(n) + 1))))
	{
		g_error = -1;
		return (NULL);
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	int		sign;
	int		size;
	char	*str;

	i = 0;
	str = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = alloc(str, n);
	sign = n;
	if (sign < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	size = find_size(n);
	while (size)
	{
		str[i++] = (n / size) + '0';
		n %= size;
		size /= 10;
	}
	str[i++] = '\0';
	return (str);
}
