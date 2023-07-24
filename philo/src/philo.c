/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:15:35 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/24 18:58:04 by oandelin         ###   ########.fr       */
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
	prog = init_prog();
	if (save_settings(prog, argc, argv) < 0)
	{
		free(prog);
		printf("fail\n");
		return (0);
	}
	set_table(prog);
	//while(42)
	//	usleep(1);
	clear_table(prog);
	// thread creation function
	// monitoring / routine?
	// joining threads and destroying mutexes
}
