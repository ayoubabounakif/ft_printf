/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_negative_width.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:52:55 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:04:22 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call_negative_width(va_list arg, char *traverse)
{
	while (*traverse == '-')
		traverse++;
	traverse--;
	if (ft_check(traverse) == '%')
		negative_width_percent(traverse);
	if (ft_check(traverse) == 's')
		negative_width_s(arg, traverse);
	if (ft_check(traverse) == 'c')
		negative_width_c(arg, traverse);
	if (ft_check(traverse) == 'd' || ft_check(traverse) == 'i')
		negative_width_d_i(arg, traverse);
	if (ft_check(traverse) == 'u')
		negative_width_u(arg, traverse);
	if (ft_check(traverse) == 'x')
		negative_width_x_87(arg, traverse);
	if (ft_check(traverse) == 'X')
		negative_width_x_55(arg, traverse);
	if (ft_check(traverse) == 'p')
		negative_width_p(arg, traverse);
}
