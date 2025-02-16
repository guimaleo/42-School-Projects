#include "philo.h"

inline int     ft_uatoi(char *str)
{
    int     res;

    res = 0;
    if (!str)
        return (-1);
    while (ft_isspace(*str))
        str++;
    if (*str == 43 || *str == 45)
    {
        if (*str == 45)
            return (-1);
        str++;
    }
    while (ft_isdigit(*str))
        res = res * 10 + (*(str++) -48);
    return (res);
}

inline size_t  ft_strlen(char *s)
{
    size_t  i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}