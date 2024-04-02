/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:15:28 by lbehr             #+#    #+#             */
/*   Updated: 2024/04/02 14:45:51 by lbehr            ###   ########.fr       */
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
		usleep(1000);
	eat(philo);
	/*while (all->mort == false)
	{
	}*/
	return (NULL);
}

void	eat(t_philo *philo)
{
	t_all	*all;

	all = philo->all;
	pthread_mutex_lock(&all->print);
	pthread_mutex_lock(&all->forkmutex[philo->forkg]);
	print(philo, "has taken a fork");
	pthread_mutex_lock(&all->forkmutex[philo->forkd]);
	print(philo, "has taken a fork");
	philo->lasteat = timestamp();
	print(philo, "is eating");
	pthread_mutex_unlock(&all->print);
	all->nbmusteat--;
	pthread_mutex_unlock(&all->forkmutex[philo->forkg]);
	pthread_mutex_unlock(&all->forkmutex[philo->forkd]);
}

void	print(t_philo *philo, char *string)
{
	t_all		*all;
	long long	time;

	all = philo->all;
	time = timestamp() - philo->lasteat;
	if (all->mort == false)
	{
		printf("%lld %d %s\n", time, philo->id, string);
	}
}
