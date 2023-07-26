/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:15:35 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/26 17:34:34 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_prog	prog;
	
	if (argc < 5 || argc > 6)
	{
		bad_arguments();
	 	return (0);
	}
	if(initializer(&prog, argc, argv) < 0)
	{	
		return(0);
	}
	
	set_table(&prog);
	//while(42)
	//	usleep(1);
	end_party(&prog);
	// thread creation function
	// monitoring / routine?
	// joining threads and destroying mutexes
}
