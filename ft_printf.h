/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:55:49 by asekmani          #+#    #+#             */
/*   Updated: 2022/12/09 14:25:11 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_putstr(char const *s);
int		ft_putptr(void *p);
int		ft_printf(const char *str, ...);
int		ft_putnbr_base(int nbr, char format);
int		ft_unsigned_base(unsigned int nbr, char format);
int		ft_format(va_list ap, char format);

#endif
