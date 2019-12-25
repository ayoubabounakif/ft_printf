/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 05:56:16 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:05:24 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		extra_condition(char *format, int i)
{
	if ((*(format + i) > '0' && *(format + i) <= '9'
			&& ft_strchr(format + i, '%'))
			|| (*(format + i) > '0' && *(format + i) <= '9'))
		return (1);
	return (0);
}

int		format_specifiers_condition(char *format, int i)
{
	if (*(format + i) == 'd' || *(format + i) == 'i'
			|| *(format + i) == 's'
			|| *(format + i) == 'c' || *(format + i) == 'u'
			|| *(format + i) == 'x' || *(format + i) == 'X'
			|| *(format + i) == 'p' || *(format + i) == '%')
		return (1);
	return (0);
}
