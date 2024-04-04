/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:45:58 by lbehr             #+#    #+#             */
/*   Updated: 2024/04/04 14:24:55 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initmutex(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nbphilo)
	{
		pthread_mutex_init(&all->forkmutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&all->print, NULL);
	pthread_mutex_init(&all->eat, NULL);
}

void	initphi(t_all *all)
{
	int	i;

	i = 0;
	all->mort = false;
	while (i < all->nbphilo)
	{
		all->philo[i].all = all;
		all->philo[i].id = i;
		all->philo[i].forkg = i;
		all->philo[i].nbeat = 0;
		if (i == 0)
			all->philo[i].forkd = all->nbphilo - 1;
		else
			all->philo[i].forkd = i - 1;
		i++;
	}
}

void	deletemutex(t_all *all)
{	int	i;

	i = 0;
	while (i < all->nbphilo)
	{
		pthread_mutex_destroy(&all->forkmutex[i]);
		i++;
	}
	pthread_mutex_destroy(&all->print);
	pthread_mutex_destroy(&all->eat);
}
