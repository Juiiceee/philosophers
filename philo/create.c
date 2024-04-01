/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:53:07 by lbehr             #+#    #+#             */
/*   Updated: 2024/04/01 14:10:56 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nbphilo)
	{
		if (pthread_create(&(all->philo[i].idthread), NULL, routine, &(all->philo[i])))
		{
			printf("Erreur lors de la création du thread %d\n", i);
			return 1;
		}
		i++;
	}
	i = 0;
	while (i < all->nbphilo)
	{
		pthread_join(all->philo[i].idthread, NULL);
		i++;
	}
	deletemutex(all);
	return (0);
}
