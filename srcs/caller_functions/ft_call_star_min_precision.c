/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_star_min_precision.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 00:23:44 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:04:35 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call_star_min_precision(va_list arg, char *traverse, int i)
{
	if (ft_check(traverse) == '%')
		star_min_precision_percent(arg, i);
	if (ft_check(traverse) == 's')
		star_min_precision_s(arg, traverse, i);
	if (ft_check(traverse) == 'c')
		star_min_precision_c(arg, traverse, i);
	if (ft_check(traverse) == 'd' || ft_check(traverse) == 'i')
		star_min_precision_d_i(arg, traverse, i);
	if (ft_check(traverse) == 'u')
		star_min_precision_u(arg, traverse, i);
	if (ft_check(traverse) == 'x')
		star_min_precision_x_87(arg, traverse, i);
	if (ft_check(traverse) == 'X')
		star_min_precision_x_55(arg, traverse, i);
	if (ft_check(traverse) == 'p')
		star_min_precision_p(arg, i);
}
