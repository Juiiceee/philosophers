/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:45:58 by lbehr             #+#    #+#             */
/*   Updated: 2024/03/06 17:07:21 by lbehr            ###   ########.fr       */
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
}

void	initphi(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nbphilo)
	{
		all->philo[i].all = all;
		all->philo[i].id = i;
		all->philo[i].forkg = i;
		if (i == 0)
			all->philo[i].forkd = all->nbphilo - 1;
		else
			all->philo[i].forkd = i - 1;
		i++;
	}
}
