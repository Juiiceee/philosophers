/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:53:07 by lbehr             #+#    #+#             */
/*   Updated: 2024/03/06 17:55:06 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nbphilo)
	{
		printf("%d\n",i);
		pthread_create(&all->philo[i].idthread, NULL, routine, &all->philo[i]);
		i++;
	}
	i = 0;
	while (i < all->nbphilo)
	{
		pthread_join(all->philo->idthread, NULL);
		i++;
	}
	pthread_mutex_destroy(&all->print);
	return (0);
}
