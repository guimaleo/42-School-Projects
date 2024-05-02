#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
#ifndef HEX_LOW
# define HEX_LOW ("0123456789abcdef")
#endif
#ifndef HEX_UPPER
# define HEX_UPPER ("0123456789ABCDEF")
#endif
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(const char *str);
int	ft_putunsigned(unsigned int u);
int	ft_putptr(void *address);
int	ft_convert_any_base(unsigned long l, char *base);

#endif
