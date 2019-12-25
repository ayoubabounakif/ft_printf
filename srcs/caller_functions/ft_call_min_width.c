/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_min_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:36:05 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:04:14 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call_min_width(va_list arg, char *traverse)
{
	if (ft_check(traverse) == '%')
		min_width_percent(arg, traverse);
	if (ft_check(traverse) == 's')
		min_width_s(arg, traverse);
	if (ft_check(traverse) == 'c')
		min_width_c(arg, traverse);
	if (ft_check(traverse) == 'd' || ft_check(traverse) == 'i')
		min_width_d_i(arg, traverse);
	if (ft_check(traverse) == 'u')
		min_width_u(arg, traverse);
	if (ft_check(traverse) == 'x')
		min_width_x_87(arg, traverse);
	if (ft_check(traverse) == 'X')
		min_width_x_55(arg, traverse);
	if (ft_check(traverse) == 'p')
		min_width_p(arg, traverse);
}
