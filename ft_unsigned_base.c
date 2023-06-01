/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:19:10 by asekmani          #+#    #+#             */
/*   Updated: 2022/12/09 17:31:36 by asekmani         ###   ########.fr       */
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

static int	ft_nbrlen(unsigned int nb, int baselen)
{
	int	i;

	i = 1;
	while (nb / baselen)
	{
		nb = nb / baselen;
		i++;
	}
	return (i);
}

int	ft_unsigned_base(unsigned int nbr, char format)
{
	unsigned int	l;
	int				i;
	char			*base;

	l = 10;
	base = ft_checkbase(format);
	if (format == 'x' || format == 'X')
		l = 16;
	i = ft_nbrlen(nbr, l);
	if (nbr < l)
		write(1, &base[nbr], 1);
	if (nbr >= l)
	{
		ft_unsigned_base(nbr / l, format);
		ft_unsigned_base(nbr % l, format);
	}
	return (i);
}
