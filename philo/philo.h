/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:41:09 by lbehr             #+#    #+#             */
/*   Updated: 2024/04/01 14:10:46 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>


typedef struct s_philo
{
	int	id;
	int	forkg;
	int	forkd;
	pthread_t		idthread;
	struct s_all	*all;
}	t_philo;

typedef struct s_all
{
	int	nbphilo;
	int	timedie;
	int	timeeat;
	int	timesleep;
	int	nbmusteat;
	int	oui;
	pthread_mutex_t	forkmutex[225];
	pthread_mutex_t	print;
	t_philo	philo[225];
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
void* printID(void* threadID);

//create.c
int	create(t_all *all);


#endif