/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_min_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 00:30:03 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:04:09 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call_min_precision(va_list arg, char *traverse)
{
	if (ft_check(traverse) == '%')
		min_width_percent(arg, traverse);
	if (ft_check(traverse) == 's')
		min_precision_s(arg, traverse++);
	if (ft_check(traverse) == 'c')
		min_precision_c(arg, traverse++);
	if (ft_check(traverse) == 'd' || ft_check(traverse) == 'i')
		min_precision_d_i(arg, traverse++);
	if (ft_check(traverse) == 'u')
		min_precision_u(arg, traverse++);
	if (ft_check(traverse) == 'x')
		min_precision_x_87(arg, traverse++);
	if (ft_check(traverse) == 'X')
		min_precision_x_55(arg, traverse++);
	if (ft_check(traverse) == 'p')
		min_precision_p(arg, traverse++);
}
