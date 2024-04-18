/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:15:28 by lbehr             #+#    #+#             */
/*   Updated: 2024/04/18 13:27:01 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *content)
{
	t_all	*all;
	t_philo	*philo;

	philo = (t_philo *)content;
	all = philo->all;
	if (philo->id % 2)
		usleep(10000);
	pthread_mutex_lock(&all->death);
	while (all->mort == false)
	{
		pthread_mutex_unlock(&all->death);
		eat(philo);
		if ((philo->nbeat >= all->nbmusteat && all->nbmusteat != -1)
			|| all->nbphilo == 1)
			return (NULL);
		print(philo, "is sleeping");
		sleepo(all->timesleep, all);
		print(philo, "is thinking");
		pthread_mutex_lock(&all->death);
	}
	pthread_mutex_unlock(&all->death);
	return (NULL);
}

void	sleepo(long long time, t_all *all)
{
	long long	first;

	first = timestamp();
	pthread_mutex_lock(&all->death);
	while ((timestamp() - first) < time && all->mort == false)
	{
		pthread_mutex_unlock(&all->death);
		usleep(50);
		pthread_mutex_lock(&all->death);
	}
	pthread_mutex_unlock(&all->death);
}

void	eat(t_philo *philo)
{
	t_all	*all;

	all = philo->all;
	pthread_mutex_lock(&all->forkmutex[philo->forkg]);
	print(philo, "has taken a fork");
	if (all->nbphilo == 1)
		return ;
	pthread_mutex_lock(&all->forkmutex[philo->forkd]);
	print(philo, "has taken a fork");
	pthread_mutex_lock(&all->eat);
	pthread_mutex_lock(&all->timemu);
	philo->lasteat = timestamp();
	pthread_mutex_unlock(&all->timemu);
	print(philo, "is eating");
	pthread_mutex_unlock(&all->eat);
	pthread_mutex_lock(&all->nbeat);
	philo->nbeat++;
	pthread_mutex_unlock(&all->nbeat);
	sleepo(all->timeeat, all);
	pthread_mutex_unlock(&all->forkmutex[philo->forkg]);
	pthread_mutex_unlock(&all->forkmutex[philo->forkd]);
}

void	print(t_philo *philo, char *string)
{
	t_all		*all;
	long long	time;

	all = philo->all;
	time = timestamp() - all->time;
	pthread_mutex_lock(&all->print);
	pthread_mutex_lock(&all->death);
	if (all->mort == false)
		printf("%lld %d %s\n", time, philo->id + 1, string);
	pthread_mutex_unlock(&all->death);
	pthread_mutex_unlock(&all->print);
}
