#include "philo.h"

inline bool    ft_isspace(char c)
{
    return (c == 32 || (c > 8 && c < 14));
}

inline bool    ft_isdigit(char c)
{
    return (c > 47 && c < 58);
}