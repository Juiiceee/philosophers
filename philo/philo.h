/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:41:09 by lbehr             #+#    #+#             */
/*   Updated: 2024/02/12 14:27:21 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_philo
{
	int	nbphilo;
	int	timedie;
	int	timeeat;
	int	timesleep;
	int	nbmusteat;
}	t_philo;

//checkarg.c
int	checkarg(char **argv, t_philo *philo, int argc);
int	checkdigit(char **str);
int	ft_atoi(char *str);

#endif
