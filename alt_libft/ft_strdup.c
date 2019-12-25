/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:57:01 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:05:54 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	size_t		len;
	size_t		i;
	char		*ptr;

	len = ft_strlen(s1);
	i = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	while (i < len)
	{
		ptr[i] = (char)s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
