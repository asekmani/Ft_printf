/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:48:31 by asekmani          #+#    #+#             */
/*   Updated: 2022/12/09 17:26:23 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list ap, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(ap, char const *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (format == 'd')
		return (ft_putnbr_base(va_arg(ap, int), 'd'));
	else if (format == 'i')
		return (ft_putnbr_base(va_arg(ap, int), 'i'));
	else if (format == 'u')
		return (ft_unsigned_base(va_arg(ap, unsigned int), 'u'));
	else if (format == 'x')
		return (ft_unsigned_base(va_arg(ap, unsigned int), 'x'));
	else if (format == 'X')
		return (ft_unsigned_base(va_arg(ap, unsigned int), 'X'));
	else if (format == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}
