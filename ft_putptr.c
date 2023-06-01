/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:12:11 by asekmani          #+#    #+#             */
/*   Updated: 2022/12/09 17:25:23 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned long long nb)
{
	int	i;

	i = 1;
	while (nb / 16)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

static int	ft_base(unsigned long long nb)
{
	char	*base;
	int		i;

	i = ft_nbrlen(nb);
	base = "0123456789abcdef";
	if (nb < 16)
		write(1, &base[nb], 1);
	if (nb >= 16)
	{
		ft_base(nb / 16);
		ft_base(nb % 16);
	}
	return (i);
}

int	ft_putptr(void *p)
{
	int					i;
	unsigned long long	ptr;

	ptr = (unsigned long long)p;
	i = 0;
	if (p == 0)
	{
		write(1, "(nil)", 5);
		i = 5;
	}
	else
	{
		write(1, "0x", 2);
		i = 2;
		i += ft_base(ptr);
	}
	return (i);
}
