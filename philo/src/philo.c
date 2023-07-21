/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsctr <trsctr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:15:35 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/21 16:44:39 by trsctr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_settings	*settings;

	if (argc < 5 || argc > 6)
	{
		bad_arguments();
		return (0);
	}
	settings = init_settings(); // maybe change this to init_prog??
	if (!settings)
	{
		printf("fail\n");
		return (0);
	}
	if (save_settings(settings, argc, argv) < 0)
	{
		free(settings);
		printf("fail\n");
		return (0);
	}
	// mutex creation function
	// thread creation function
	// monitoring / routine?
	// joining threads and destroying mutexes
}
