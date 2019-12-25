/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_zero_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:40:09 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:04:40 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call_zero_flag(va_list arg, char *traverse)
{
	if (ft_check(traverse) == 's')
		zero_flag_s(arg, traverse);
	if (ft_check(traverse) == 'c')
		zero_flag_c(arg, traverse);
	if (ft_check(traverse) == 'd' || ft_check(traverse) == 'i')
		zero_flag_d_i(arg, traverse);
	if (ft_check(traverse) == 'u')
		zero_flag_u(arg, traverse);
	if (ft_check(traverse) == 'x')
		zero_flag_x_87(arg, traverse);
	if (ft_check(traverse) == 'X')
		zero_flag_x_55(arg, traverse);
	if (ft_check(traverse) == '%')
		zero_flag_percent(traverse);
}
