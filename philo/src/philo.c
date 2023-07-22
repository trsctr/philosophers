/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:15:35 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/22 17:20:53 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_prog	*prog;
	//t_settings *settings;

	if (argc < 5 || argc > 6)
	{
		bad_arguments();
		return (0);
	}
	init(&prog);
	prog->settings = init_settings();
	if (save_settings(prog->settings, argc, argv) < 0)
	{
	 	free(prog);
	 	printf("fail\n");
	 	return (0);
	}
	// mutex creation function
	create_threads(prog);
	join_threads(prog);
	// thread creation function
	// monitoring / routine?
	// joining threads and destroying mutexes
}
