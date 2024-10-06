/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:09:52 by lede-gui          #+#    #+#             */
/*   Updated: 2024/10/06 14:09:56 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define HEX_LOW "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(const char *str);
int		ft_putunsigned(unsigned int u);
int		ft_putptr(void *address);
int		ft_convert_any_base(unsigned long l, char *base);
size_t	ft_strlen(char *s);

#endif
