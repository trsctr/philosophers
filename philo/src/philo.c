/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:15:35 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/27 21:46:29 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 *  @brief Main function of the philosophers program
 * 
 * Defines the struct t_prog which will contain all the necessary data.
 * Checks if the amount of command line arguments is valid. If amount of 
 * arguments is invalid, it prints an error message and exits.
 * 
 * The prog struct, argument counter and argument vector are sent to 
 * inizializer function which saves parameters 
 * and initializes arrays and mutexes.
 * If initializer fails, struct_cleaner is used to free allocated
 * memory if necessary.
 * 
 * The struct is sent to set_table which initializes the threads,
 * routines and monitoring.
 * End party joins threads, destroys mutexes and frees allocated memory.
 * 
 * @param argc argument count
 * @param argv argument vector
 * 
 *  */
int	main(int argc, char **argv)
{
	t_prog	prog;
	int		i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		bad_arguments(0);
		return (0);
	}
	if (initializer(&prog, argc, argv) < 0)
	{	
		if (prog.philos)
			struct_cleaner(&prog);
		return (0);
	}
	set_table(&prog);
	end_party(&prog);
	return (0);
}
