/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_negative_star.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:22:24 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:04:18 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call_negative_star_flag(va_list arg, char *traverse)
{
	if (ft_check(traverse) == '%')
		negative_star_flag_percent(arg);
	if (ft_check(traverse) == 's')
		negative_star_flag_s(arg);
	if (ft_check(traverse) == 'c')
		negative_star_flag_c(arg);
	if (ft_check(traverse) == 'd' || ft_check(traverse) == 'i')
		negative_star_flag_d_i(arg);
	if (ft_check(traverse) == 'u')
		negative_star_flag_u(arg);
	if (ft_check(traverse) == 'x')
		negative_star_flag_x_87(arg);
	if (ft_check(traverse) == 'X')
		negative_star_flag_x_55(arg);
	if (ft_check(traverse) == 'p')
		negative_star_flag_p(arg);
}
