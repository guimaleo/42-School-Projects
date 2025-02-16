#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>

# define USE "Usage: <number of philosophers> <time to die> <time to eat> <time to sleep>\n"
# define PHI_ERR "Number of philosophers exceeded\n"
# define NEG "Negative input found\n"
# define DIG "Non numeric char found\n"
# define CREAT "Threads creation generated an error\n"

typedef void    *(*routines)(void *);

typedef struct s_threads
{
    pthread_t       ph;
    pthread_mutex_t mtx;
}       t_threads;

typedef struct s_args
{
    int     nb;
    int     die;
    int     eat;
    int     sleep;
    int     meals;
}       t_args;

typedef struct s_philo
{
    int         *id;
    int         nb;
    int         die;
    int         eat;
    int         sleep;
    int         meals;
    t_args      *var;
    t_threads   *threads;
    pthread_mutex_t mtx;
}      t_philo;

typedef enum    e_func
{
    CREATE,
    JOIN,
    INIT,
    DESTROY,
    LOCK,
    UNLOCK,
    DETACH
}       t_func;


t_philo	*philos(void);
int     ft_uatoi(char *str);
size_t  ft_strlen(char *s);
bool    ft_isspace(char c);
bool    ft_isdigit(char c);
bool    ft_error(char *msg, void *ptr);
bool    welcome_drink(void);

#endif