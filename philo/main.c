/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:38:29 by lbehr             #+#    #+#             */
/*   Updated: 2024/03/06 17:42:15 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_all	all;

	if (checkarg(argv, &all, argc))
		return (0);
	initphi(&all);
	initmutex(&all);
	create(&all);
}
