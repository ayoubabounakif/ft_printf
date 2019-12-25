/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:39:00 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:02 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int	g_error;

static size_t	find_size(size_t nb)
{
	size_t	size;

	size = 1;
	while ((nb /= 10) > 0)
		size *= 10;
	return (size);
}

static size_t	find_digits(size_t n)
{
	int		i;

	i = 0;
	if (n == 0)
	{
		i++;
		return (i);
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_unsigned_itoa(size_t n)
{
	int		i;
	int		size;
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (find_digits(n) + 1))))
	{
		g_error = -1;
		return (NULL);
	}
	i = 0;
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
