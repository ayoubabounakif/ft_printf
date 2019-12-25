/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 05:58:22 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:22 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	little_function(va_list arg, char *format, int i)
{
	if (ft_strchr(format + i, '-') != 0)
		ft_call_negative_width(arg, format + i);
	else if (*(format + i + 1) == '*')
		ft_call_star_flag(arg, format + i, 0);
	else
		ft_call_zero_flag(arg, format + i);
}

void	ft_do_aux(va_list arg, char *format, int i)
{
	if (*(format + i) == '0')
	{
		if (ft_strchr(format + i, '*'))
			ft_call_min_precision(arg, format + i);
		else
			ft_call_min_precision(arg, format + i);
	}
	else if (ft_strchr(format + i, '*'))
		ft_call_star_min_precision(arg, format + i, 0);
	else if (*(format + i) == '%')
	{
		i++;
		if (*(format + i) == '%')
		{
			ft_call_min_precision(arg, format + i);
			i++;
		}
	}
	else
		ft_call_min_precision(arg, format + i);
}

void	ft_do(va_list arg, char *format, int i)
{
	if (*(format + i) == '-' && (!(ft_strchr(format + i, '.')))
			&& (*(format + i + 1) != '*'))
		ft_call_negative_width(arg, format + i);
	else if (*(format + i) == '0' && (!(ft_strchr(format + i, '.'))))
		little_function(arg, format, i);
	else if ((*(format + i) == '-' && ft_strchr(format + i, '*'))
			&& ft_strchr(format + i, '.'))
		ft_call_star_min_precision(arg, format + i, 1);
	else if ((*(format + i) == '-' && ft_strchr(format + i, '*'))
			&& !(ft_strchr(format + i, '.')))
		ft_call_negative_star_flag(arg, format + i);
	else if (*(format + i) == '*' && ft_strchr(format + i, '.'))
		ft_call_star_min_precision(arg, format + i, 0);
	else if (*(format + i) == '*' && (!(ft_strchr(format + i, '.'))))
		ft_call_star_flag(arg, format + i, 1);
	else if (*(format + i) == '.')
		ft_call_precision(arg, format + i);
	else if (1 == format_specifiers_condition(format, i))
		format_specifiers(arg, format + i);
	else if ((ft_atoi(format + i) >= 0 && ft_strchr(format + i, '.'))
			|| (ft_atoi(format + i) < 0))
		ft_do_aux(arg, format, i);
	else if (1 == extra_condition(format, i))
		ft_call_min_width(arg, format + i);
}
