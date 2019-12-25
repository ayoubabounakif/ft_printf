/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 00:24:37 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:09:10 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_a;

void	format_specifiers_completion(va_list arg, char *traverse)
{
	int		i;

	i = 0;
	if (traverse[i] == 'x')
		ft_putstr(ft_hex_87(va_arg(arg, unsigned int)));
	if (traverse[i] == 'X')
		ft_putstr(ft_hex_55(va_arg(arg, unsigned int)));
	if (traverse[i] == 'p')
	{
		ft_putstr("0x");
		ft_putstr(ft_memory(va_arg(arg, unsigned long long)));
	}
}

void	format_specifiers(va_list arg, char *traverse)
{
	int		i;
	int		varg;

	i = 0;
	if (traverse[i] == '%')
		ft_putchar('%');
	if (traverse[i] == 's')
		ft_putstr(va_arg(arg, char *));
	if (traverse[i] == 'c')
	{
		varg = va_arg(arg, int);
		if (varg == 0 || varg == '\0')
			g_a++;
		ft_putchar(varg);
	}
	if (traverse[i] == 'd' || traverse[i] == 'i')
		ft_putnbr(va_arg(arg, int));
	if (traverse[i] == 'u')
		ft_putunsignednbr(va_arg(arg, unsigned int));
	format_specifiers_completion(arg, traverse);
}
