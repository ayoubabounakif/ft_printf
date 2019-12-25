/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 06:55:53 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:33 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int	g_error;

char	where_star(char *traverse)
{
	while (*traverse != '.')
	{
		traverse++;
		if (*traverse == '*')
			return ('<');
	}
	return ('>');
}

char	*ft_fill_2(char *dst, char *src, int i, int c)
{
	if (!(dst = malloc(i + 1)))
	{
		g_error = -1;
		return (NULL);
	}
	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_fill(va_list arg, char *dst, char *src, int c)
{
	char	*temp;
	int		i;

	temp = src;
	i = 0;
	if (*src == '%')
		src++;
	if (*src == '0')
	{
		src++;
		if (*src == '*')
			return (dst = ft_itoa(va_arg(arg, int)));
	}
	if (*src == '.')
		src++;
	while (temp[i] != c && temp[i] != '\0')
		i++;
	if (*src == '*')
		return (dst = ft_itoa(va_arg(arg, int)));
	dst = ft_fill_2(dst, src, i, c);
	return (dst);
}

char	*fill(char *dst, char *src, int c)
{
	char	*temp;
	int		i;

	temp = src;
	i = 0;
	if (*src == '%')
		src++;
	if (*src == '.')
		src++;
	while (temp[i] != c)
		i++;
	if (!(dst = malloc(i + 1)))
	{
		g_error = -1;
		return (NULL);
	}
	i = 0;
	while (src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
