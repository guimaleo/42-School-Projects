#include "philo.h"

void    *welcome(void *arg)
{
    int     id;

    id = *(int *)arg;
    pthread_mutex_lock(&philos()->mtx);
    pthread_mutex_unlock(&philos()->mtx);
    return (NULL);
}

bool    welcome_drink(void)
{
    int         i;
    int         *ids;
    pthread_t   *ph;

    i = -1;
    ids = malloc(philos()->nb * sizeof(int));
    ph = malloc(philos()->nb * sizeof(pthread_t));
    if (!ids || !ph)
        return (false, write(2, CREAT, ft_strlen(CREAT)));
    pthread_mutex_init(&philos()->mtx, NULL);
    while (++i < philos()->nb)
    {
        ids[i] = i + 1;
        if (pthread_create(&ph[i], NULL, welcome, &ids[i]))
            return (false);
    }
    i = -1;
    philos()->id = ids;
    // while (++i < philos()->nb)
        // printf("Id: %i\n", philos()->id[i]);
    while (++i < philos()->nb)
    {
        if (pthread_join(ph[i], NULL))
            return (false);
    }
    pthread_mutex_destroy(&philos()->mtx);
    return (true);
}
