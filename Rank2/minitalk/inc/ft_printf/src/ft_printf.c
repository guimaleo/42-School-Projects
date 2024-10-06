/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:04:59 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 19:55:10 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_my_specifiers(char c, va_list specs)
{
	int	res;

	res = 0;
	if (c == '%')
		res += write(1, "%", 1);
	else if (c == 'c')
		res += ft_putchar(va_arg(specs, int));
	else if (c == 's')
		res += ft_putstr(va_arg(specs, char *));
	else if (c == 'i' || c == 'd')
		res += ft_putnbr(va_arg(specs, int));
	else if (c == 'x')
		res += ft_convert_any_base(va_arg(specs, unsigned int), HEX_LOW);
	else if (c == 'X')
		res += ft_convert_any_base(va_arg(specs, unsigned int), HEX_UPPER);
	else if (c == 'p')
		res += ft_putptr(va_arg(specs, void *));
	else if (c == 'u')
		res += ft_putunsigned(va_arg(specs, unsigned int));
	else
		res = 0;
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	specs;

	res = 0;
	if (!str)
		return (-1);
	res = 0;
	va_start(specs, str);
	while (*str)
	{
		if (*str != 37)
			res += write(1, str, 1);
		else
		{
			++str;
			res += ft_my_specifiers(*str, specs);
		}
		str++;
	}
	va_end(specs);
	return (res);
}
