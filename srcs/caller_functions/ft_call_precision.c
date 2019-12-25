/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:35:42 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:04:26 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call_precision(va_list arg, char *traverse)
{
	if (ft_check(traverse) == '%')
		ft_putchar('%');
	if (ft_check(traverse) == 's')
		precision_s(arg, traverse);
	if (ft_check(traverse) == 'c')
		precision_c(arg, traverse);
	if (ft_check(traverse) == 'd' || ft_check(traverse) == 'i')
		precision_d_i(arg, traverse);
	if (ft_check(traverse) == 'u')
		precision_u(arg, traverse);
	if (ft_check(traverse) == 'x')
		precision_x_87(arg, traverse);
	if (ft_check(traverse) == 'X')
		precision_x_55(arg, traverse);
	if (ft_check(traverse) == 'p')
		precision_p(arg);
}
