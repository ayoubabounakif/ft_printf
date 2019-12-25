/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_star_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 00:27:20 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:04:31 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call_star_zero_flag(va_list arg, char *traverse)
{
	if (ft_check(traverse) == '%')
		star_flag_percent(arg, 0);
	if (ft_check(traverse) == 's')
		star_flag_s(arg, 0);
	if (ft_check(traverse) == 'c')
		star_flag_c(arg, 0);
	if (ft_check(traverse) == 'd' || ft_check(traverse) == 'i')
		star_flag_d_i(arg, 0);
	if (ft_check(traverse) == 'u')
		star_flag_u(arg, 0);
	if (ft_check(traverse) == 'x')
		star_flag_x_87(arg, 0);
	if (ft_check(traverse) == 'X')
		star_flag_x_55(arg, 0);
	if (ft_check(traverse) == 'p')
		star_flag_p(arg, 0);
}

void	ft_call_star_flag(va_list arg, char *traverse, int i)
{
	if (i == 0)
		ft_call_star_zero_flag(arg, traverse);
	else
	{
		if (ft_check(traverse) == '%')
			star_flag_percent(arg, 1);
		if (ft_check(traverse) == 's')
			star_flag_s(arg, 1);
		if (ft_check(traverse) == 'c')
			star_flag_c(arg, 1);
		if (ft_check(traverse) == 'd' || ft_check(traverse) == 'i')
			star_flag_d_i(arg, 1);
		if (ft_check(traverse) == 'u')
			star_flag_u(arg, 1);
		if (ft_check(traverse) == 'x')
			star_flag_x_87(arg, 1);
		if (ft_check(traverse) == 'X')
			star_flag_x_55(arg, 1);
		if (ft_check(traverse) == 'p')
			star_flag_p(arg, 1);
	}
}
