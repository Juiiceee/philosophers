/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:41:05 by lbehr             #+#    #+#             */
/*   Updated: 2024/04/18 13:12:48 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checkdigit(char **str)
{
	int	j;
	int	i;

	i = 1;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '\0')
			return (-1);
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

long long	ft_atoi(char *str)
{
	long long	cmp;
	long long	signe;

	signe = 1;
	cmp = 0;
	while (*str)
	{
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				signe = -1;
			str++;
		}
		cmp = cmp * 10 + *str - '0';
		str++;
	}
	return (signe * cmp);
}

int	checkarg(char **argv, t_all *all, int argc)
{
	if (checkdigit(argv) == -1 || !(argc == 5 || argc == 6))
		return (1);
	if (argc == 6 && ft_atoi(argv[5]) > 0)
		all->nbmusteat = ft_atoi(argv[5]);
	else
		all->nbmusteat = -1;
	if (!(ft_atoi(argv[1]) > 0 && ft_atoi(argv[1]) <= 200)
		&& ft_atoi(argv[2]) > 0 && ft_atoi(argv[3]) > 0
		&& ft_atoi(argv[4]) > 0)
		return (1);
	all->nbphilo = ft_atoi(argv[1]);
	all->timedie = ft_atoi(argv[2]);
	all->mort = false;
	all->timeeat = ft_atoi(argv[3]);
	all->timesleep = ft_atoi(argv[4]);
	return (0);
}
