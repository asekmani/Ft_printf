/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:00:47 by asekmani          #+#    #+#             */
/*   Updated: 2022/12/09 17:29:40 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *args, ...)
{
	int		i;
	int		j;
	va_list	ap;

	va_start(ap, args);
	i = 0;
	j = 0;
	while (args[i])
	{
		if (args[i] == '%')
		{
			i++;
			j += ft_format(ap, args[i]);
		}
		else
		{
			j += ft_putchar(args[i]);
		}
		i++;
	}
	return (j);
}
