/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:00:38 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:05:56 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_strlen(const char *str)
{
	unsigned long long	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
