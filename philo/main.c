/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:38:29 by lbehr             #+#    #+#             */
/*   Updated: 2024/04/17 10:25:00 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_all	all;
	int		erreur;

	erreur = checkarg(argv, &all, argc);
	if (erreur == 1)
		return (1);
	else if (erreur == 2)
		return (0);
	initphi(&all);
	initmutex(&all);
	create(&all);
	return (0);
}
