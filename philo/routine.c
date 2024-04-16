/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:15:28 by lbehr             #+#    #+#             */
/*   Updated: 2024/04/16 09:14:52 by lbehr            ###   ########.fr       */
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
	while (all->mort == false)
	{
		eat(philo);
		if (philo->nbeat >= all->nbmusteat && all->nbmusteat != -1)
			return (NULL);
		print(philo, "is sleeping");
		sleepo(all->timesleep, all);
		print(philo, "is thinking");
	}
	return (NULL);
}

void	sleepo(long long time, t_all *all)
{
	long long	first;

	first = timestamp();
	while ((timestamp() - first) < time && all->mort == false)
		usleep(50);
}

void	eat(t_philo *philo)
{
	t_all	*all;

	all = philo->all;
	pthread_mutex_lock(&all->forkmutex[philo->forkg]);
	print(philo, "has taken a fork");
	pthread_mutex_lock(&all->forkmutex[philo->forkd]);
	print(philo, "has taken a fork");
	pthread_mutex_lock(&all->eat);
	philo->lasteat = timestamp();
	print(philo, "is eating");
	pthread_mutex_unlock(&all->eat);
	philo->nbeat++;
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
	if (all->mort == false)
		printf("%lld %d %s\n", time, philo->id, string);
	pthread_mutex_unlock(&all->print);
}
