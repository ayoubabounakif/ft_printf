/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:31:20 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:09:14 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_a;
int		g_error;

static int		ft_printf_completion(va_list arg, const char *format, int i)
{
	if (*(format + i) == '%')
	{
		i++;
		if (*(format + i) == '%')
			ft_putchar('%');
		else
		{
			ft_do(arg, (char *)format, i);
			i += ft_escape((char *)format + i);
		}
	}
	else
		ft_putchar(*(format + i));
	i++;
	return (i);
}

int				ft_printf(const char *format, ...)
{
	int			i;
	va_list		arg;

	va_start(arg, format);
	i = 0;
	g_a = 0;
	g_error = 0;
	while (*(format + i) != '\0')
		i = ft_printf_completion(arg, format, i);
	va_end(arg);
	return ((g_error == 0) ? g_a : g_error);
}
