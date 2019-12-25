/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:00:59 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:06:24 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_escape(char *traverse)
{
	int		i;

	i = 0;
	if (traverse[i] != '%')
	{
		while (traverse[i] != 'c' && traverse[i] != 'd' && traverse[i] != 'i'
				&& traverse[i] != 's' && traverse[i] != 'x' &&
				traverse[i] != 'X' && traverse[i] != 'p' && traverse[i] != 'u'
				&& traverse[i] != '%')
			i++;
	}
	return (i);
}
