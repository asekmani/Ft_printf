/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:06:37 by asekmani          #+#    #+#             */
/*   Updated: 2022/12/09 17:30:45 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_checkbase(char b)
{
	if (b == 'x')
		return ("0123456789abcdef");
	if (b == 'X')
		return ("0123456789ABCDEF");
	return ("0123456789");
}

static int	ft_nbrlen(int nbr, int baselen)
{
	int			i;
	long long	nb;

	nb = nbr;
	i = 1;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb / baselen)
	{
		nb = nb / baselen;
		i++;
	}
	return (i);
}

int	ft_putnbr_base(int nbr, char format)
{
	int			l;
	int			i;
	long long	nb;
	char		*base;

	nb = nbr;
	base = ft_checkbase(format);
	l = 10;
	if (format == 'x' || format == 'X')
		l = 16;
	i = ft_nbrlen(nb, l);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= l)
	{
		ft_putnbr_base(nb / l, format);
		ft_putnbr_base(nb % l, format);
	}
	else if (nb < l)
		write(1, &base[nb], 1);
	return (i);
}
