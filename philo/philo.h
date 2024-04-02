/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:41:09 by lbehr             #+#    #+#             */
/*   Updated: 2024/04/02 14:17:50 by lbehr            ###   ########.fr       */
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
	pthread_t		idthread;
	long long		lasteat;
	struct s_all	*all;
}	t_philo;

typedef struct s_all
{
	int				nbphilo;
	int				timedie;
	int				timeeat;
	int				timesleep;
	int				nbmusteat;
	long long		time;
	t_bool			mort;
	pthread_mutex_t	eat;
	pthread_mutex_t	forkmutex[225];
	pthread_mutex_t	print;
	t_philo			philo[225];
}	t_all;


//checkarg.c
int		checkarg(char **argv, t_all *all, int argc);
int		checkdigit(char **str);
int		ft_atoi(char *str);

//init.c
void	initphi(t_all *all);
void	initmutex(t_all *all);
void	deletemutex(t_all *all);

//routine.c
void	*routine(void *content);
void	eat(t_philo *philo);
void	print(t_philo *philo, char *string);

//create.c
int	create(t_all *all);

//utils.c
long long	timestamp(void);

#endif