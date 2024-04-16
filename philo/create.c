/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:53:07 by lbehr             #+#    #+#             */
/*   Updated: 2024/04/16 17:03:58 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	checkeatslachdeath(t_all *all)
{
	int	i;

	while (all->tousmangez == false)
	{
		i = -1;
		while (++i < all->nbphilo)
		{
			pthread_mutex_lock(&all->eat);
			if (timestamp() - all->philo[i].lasteat > all->timedie)
			{
				print(&all->philo[i], "died");
				all->mort = true;
			}
			pthread_mutex_unlock(&all->eat);
			usleep(1000);
		}
		if (all->mort)
			break ;
		i = 0;
		while (i < all->nbphilo && all->philo[i].nbeat == all->nbmusteat)
			i++;
		if (i == all->nbphilo)
			all->tousmangez = true;
	}
}

int	create(t_all *all)
{
	int	i;

	i = 0;
	all->time = timestamp();
	while (i < all->nbphilo)
	{
		if (pthread_create(&all->philo[i].idthread,
				NULL, routine, &all->philo[i]))
			return (printf("Erreur lors de la création du thread %d\n", i), 1);
		all->philo[i++].lasteat = timestamp();
	}
	checkeatslachdeath(all);
	i = 0;
	while (i < all->nbphilo)
		if (pthread_join(all->philo[i++].idthread, NULL))
			return (printf("Erreur lors du join du thread %d\n", i), 1);
	deletemutex(all);
	return (0);
}
