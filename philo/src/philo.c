/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:15:35 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/27 18:27:52 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_prog	prog;

	if (argc < 5 || argc > 6)
	{
		bad_arguments(0);
		return (0);
	}
	if (initializer(&prog, argc, argv) < 0)
	{	
		return (0);
	}
	set_table(&prog);
	end_party(&prog);
	return (0);
}
