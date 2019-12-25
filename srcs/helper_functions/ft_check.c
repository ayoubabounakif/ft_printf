/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:13:46 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:20 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_check(char *format)
{
	char	ch;

	while (*format)
	{
		format++;
		if (*format == 's')
			return (ch = *format);
		else if (*format == 'c')
			return (ch = *format);
		else if (*format == 'd' || *format == 'i')
			return (ch = *format);
		else if (*format == 'u')
			return (ch = *format);
		else if (*format == 'x')
			return (ch = *format);
		else if (*format == 'X')
			return (ch = *format);
		else if (*format == 'p')
			return (ch = *format);
		else if (*format == '%')
			return (ch = *format);
	}
	return (0);
}
