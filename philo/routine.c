/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:15:28 by lbehr             #+#    #+#             */
/*   Updated: 2024/03/06 17:50:14 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *content)
{
	t_all	*all;
	t_philo	*philo;

	philo = (t_philo *)content;
	all = philo->all;
	printf("thread %d\n", philo->id);
	pthread_mutex_lock(&all->print);
	//printf("Je prends le lock thread %d \n", philo->id);
	pthread_mutex_unlock(&all->print);
	//printf("Je prends le delock thread %d \n", philo->id);
	return (NULL);
}
