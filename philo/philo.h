/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:41:09 by lbehr             #+#    #+#             */
/*   Updated: 2024/04/17 17:02:47 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_philo
{
	int				id;
	int				forkg;
	int				forkd;
	int				nbeat;
	pthread_t		idthread;
	long long		lasteat;
	struct s_all	*all;
}	t_philo;

typedef struct s_all
{
	int				nbphilo;
	long long		timedie;
	long long		timeeat;
	long long		timesleep;
	int				nbmusteat;
	long long		time;
	t_bool			mort;
	t_bool			tousmangez;
	pthread_mutex_t	nbeat;
	pthread_mutex_t	death;
	pthread_mutex_t	timemu;
	pthread_mutex_t	eat;
	pthread_mutex_t	forkmutex[225];
	pthread_mutex_t	print;
	t_philo			philo[225];
}	t_all;

//checkarg.c
int			checkarg(char **argv, t_all *all, int argc);
int			checkdigit(char **str);
long long	ft_atoi(char *str);

//init.c
void		initphi(t_all *all);
void		initmutex(t_all *all);
void		deletemutex(t_all *all);

//routine.c
void		*routine(void *content);
void		eat(t_philo *philo);
void		print(t_philo *philo, char *string);
void		sleepo(long long time, t_all *all);

//create.c
int			create(t_all *all);

//utils.c
long long	timestamp(void);

#endif